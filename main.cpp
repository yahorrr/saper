#include "MinesweeperBoard.h"

int main(){
    MinesweeperBoard board(9, 7, HARD);
    board.debug_display();
    cout << board.getMineCount();
    return 0;
}
