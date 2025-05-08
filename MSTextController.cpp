#include "MSTextController.h"
#include <iostream>

MSTextController::MSTextController(MinesweeperBoard& board, MSBoardTextView& view)
    : board(board), view(view) {}

void MSTextController::play() const {
    while (board.getGameState() == RUNNING) {
        view.display();

        std::cout << "\nEnter your command (r x y - open; f x y - flag): ";
        char command;
        int x, y;
        std::cin >> command >> y >> x;

        if (command == 'r') {
            board.revealField(y, x);
        } else if (command == 'f') {
            board.toggleFlag(y, x);
        } else {
            std::cout << "Unknown command!\n";
        }
    }

    view.display();
    if (board.getGameState() == FINISHED_WIN)
        std::cout << "\nYou win!!\n";
    else if (board.getGameState() == FINISHED_LOSS)
        std::cout << "\nBUM! You lose!\n";
}
