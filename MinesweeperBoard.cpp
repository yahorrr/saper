#include "MinesweeperBoard.h"

#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

MinesweeperBoard::MinesweeperBoard()
{
    width = 5;
    height = 7;
    board.resize(height, width);
    clearBoard();

    board[0][0] = {true, false, false};
    board[1][1] = {false, false, true};
    board[0][2] = {true, true, false};
}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode) {
    this->width = width;
    this->height = height;
    board.resize(height, width);
    clearBoard();

    srand(time(nullptr));
    if (mode == EASY) {
        placeMinesRandomly(0.1);
    } else if (mode == NORMAL) {
        placeMinesRandomly(0.2);
    } else if (mode == HARD) {
        placeMinesRandomly(0.3);
    } else if (mode == DEBUG) {
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
}

void MinesweeperBoard::placeMinesRandomly(double percentage)
{
    int totalMines = std::ceil(width * height * percentage);
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