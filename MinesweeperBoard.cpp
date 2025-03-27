#include "MinesweeperBoard.h"

#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

MinesweeperBoard::MinesweeperBoard() : width(5), height(7)
{
    board.resize(height, width);
    clearBoard();

    board[0][0] = {true, false, false};
    board[1][1] = {false, false, true};
    board[0][2] = {true, true, false};
}

MinesweeperBoard::MinesweeperBoard(const int width, const int height, const GameMode mode) : width(width), height(height), mode(mode)
{
    board.resize(height, width);
    clearBoard();

    srand(time(nullptr));

    if (mode == DEBUG) {
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

int MinesweeperBoard::modeToProcent() const
{
    switch (mode) {
        case EASY:
            return 10;
            break;
        case NORMAL:
            return 20;
            break;
        case HARD:
            return 30;
            break;
        case DEBUG:
            return 0;
            break;
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

void MinesweeperBoard::debug_display() const {
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
    return std::ceil((double)width * height * modeToProcent() / 100);
}
