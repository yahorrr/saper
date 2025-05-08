#include "MSBoardTextView.h"
#include <iostream>
#include <iomanip>

MSBoardTextView::MSBoardTextView(const MinesweeperBoard& board) : board(board) {}

void MSBoardTextView::display() const
{
    int width = board.getBoardWidth();
    int height = board.getBoardHeight();

    std::cout << "   ";
    for (int col = 0; col < width; ++col)
        std::cout << std::setw(2) << col;
    std::cout << "\n";

    for (int row = 0; row < height; ++row) {
        std::cout << std::setw(2) << row << " ";
        for (int col = 0; col < width; ++col) {
            std::cout << std::setw(2) << board.getFieldInfo(row, col);
        }
        std::cout << "\n";
    }
}
