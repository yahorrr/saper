#include "MinesweeperBoard.h"

#include <iostream>
#include <vector>
#include "Array2D.h"

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

            std::cout << "[" << mina << odkryte << flaga << "] ";
        }
        std::cout << "\n";

    }
}