#include "MinesweeperBoard.h"

#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ceil;

MinesweeperBoard::MinesweeperBoard() : width(5), height(7), mode(EASY), state(RUNNING)
{
    board.resize(height, width);
    clearBoard();
    numberOfMines = ceil((double)width * height * modeToPercent() / 100);

    board[0][0] = {true, false, false};
    board[1][1] = {false, false, true};
    board[0][2] = {true, true, false};
}

MinesweeperBoard::MinesweeperBoard(const int width, const int height, const GameMode mode) : width(width), height(height), mode(mode), state(RUNNING)
{
    board.resize(height, width);
    clearBoard();
    numberOfMines = ceil((double)width * height * modeToPercent() / 100);

    //srand(time(nullptr));

    if (mode == DEBUG) {
        numberOfMines = 18;
        for (int i = 0; i < std::min(width, height); i++) {
            board[i][i] = {true, false, false};; // przekątna
        }
        for (int x = 0; x < width; x++) {
            board[0][x] = {true, false, false};; // pierwszy wiersz
        }
        for (int y = 0; y < height; y += 2) {
            board[y][0] = {true, false, false};; // co drugie pole w pierwszej kolumnie
        }
    }
    else
    {
        placeMinesRandomly();
    }
}

int MinesweeperBoard::modeToPercent() const
{
    switch (mode) {
        case EASY:
            return 10;
        case NORMAL:
            return 20;
        case HARD:
            return 30;
        case DEBUG:
            return 0;
    }

    return -1;
}

void MinesweeperBoard::placeMinesRandomly()
{
    const int totalMines = getMineCount();
    int placedMines = 0;
    while (placedMines < totalMines) {
        int x = rand() % width;
        int y = rand() % height;
        if (!board[y][x].hasMine) {
            board[y][x] =  {true, false, false};
            placedMines++;
        }
    }
}

void MinesweeperBoard::clearBoard()
{
    for (int ncol = 0; ncol < width; ncol++) {
        for (int nrow = 0; nrow < height; nrow++) {
            board[nrow][ncol] = {false, false, false};
        }
    }
}

void MinesweeperBoard::debug_display() const
{
    cout << "    ";
    for (int col = 0; col < this->width; col++) {
        cout << col << "     ";
    }
    cout << "\n";
    for (int row = 0; row < this->height; row++) {
        cout << row << " ";
        for (int col = 0; col < this->width; col++) {
            char mina = board[row][col].hasMine ? 'M' : '.';
            char odkryte = board[row][col].isRevealed ? 'o' : '.';
            char flaga = board[row][col].hasFlag ? 'f' : '.';
            cout << "[" << mina << odkryte << flaga << "] ";
        }
        cout << "\n";
    }
}

int MinesweeperBoard::getBoardWidth() const
{
    return width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return height;
}

int MinesweeperBoard::getMineCount() const
{
    return numberOfMines;
}

GameState MinesweeperBoard::getGameState() const
{
    return state;
}

bool MinesweeperBoard::isValidField(const int row, const int col) const
{
    if (row < 0 || row >= height || col < 0 || col >= width) {
        return false;
    }

    return true;
}

int MinesweeperBoard::countMines(const int row, const int col) const
{
    if (!isValidField(row, col) || !board[row][col].isRevealed) {
        return -1;
    }

    int mineCount = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int newRow = row + i;
            int newCol = col + j;

            if (i == 0 && j == 0) continue;
            if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width) {
                if (board[newRow][newCol].hasMine) {
                    mineCount++;
                }
            }
        }
    }

    return mineCount;
}

bool MinesweeperBoard::hasFlag(const int row, const int col) const
{
    if (!isValidField(row, col)) {
        return false;
    }

    return !board[row][col].isRevealed && board[row][col].hasFlag;
}

bool MinesweeperBoard::hasMine(const int row, const int col) const {
    if (!isValidField(row, col)) {
        return false;
    }

    return board[row][col].hasMine;
}

void MinesweeperBoard::toggleFlag(const int row, const int col)
{
    if (row < 0 || row >= height || col < 0 || col >= width) {
        return;
    }

    if (board[row][col].isRevealed || state != RUNNING) {
        return;
    }

    board[row][col].hasFlag = !board[row][col].hasFlag;
}

void MinesweeperBoard::revealField(const int row, const int col)
{
    if (!isValidField(row, col)) return;

    Field& field = board[row][col];

    if (field.isRevealed || field.hasFlag || state != RUNNING) return;

    if (field.hasMine && revealedFields == 0 && mode != DEBUG) {
        field.hasMine = false;
        int placed = 0;
        while (placed < numberOfMines) {
            int x = rand() % width;
            int y = rand() % height;
            if ((x != col || y != row) && !board[y][x].hasMine) {
                board[y][x].hasMine = true;
                placed++;
            }
        }

        revealField(row, col);
        return;
    }

    if (field.hasMine) {
        field.isRevealed = true;
        state = FINISHED_LOSS;
        return;
    }

    field.isRevealed = true;
    revealedFields++;

    if (revealedFields == (width * height) - numberOfMines) {
        state = FINISHED_WIN;
        return;
    }

    if (countMines(row, col) == 0) {
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int newRow = row + i;
                int newCol = col + j;

                if ((i != 0 || j != 0) && isValidField(newRow, newCol)) {
                    revealField(newRow, newCol);
                }
            }
        }
    }
}

bool MinesweeperBoard::isRevealed(const int row, const int col) const
{
    return board[row][col].isRevealed;
}

char MinesweeperBoard::getFieldInfo(const int row, const int col) const
{
    if (!isValidField(row, col)) {
        return '#';
    }
    if (!board[row][col].isRevealed && board[row][col].hasFlag) {
        return 'F';
    }
    if (!board[row][col].isRevealed && !board[row][col].hasFlag) {
        return '_';
    }
    if (board[row][col].isRevealed && board[row][col].hasMine) {
        return 'x';
    }
    if (board[row][col].isRevealed && countMines(row, col) == 0) {
        return ' ';
    }
    if (board[row][col].isRevealed) {
        return '0' + countMines(row, col);
    }

    return '~';
}



