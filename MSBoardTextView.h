#ifndef MSBOARDTEXTVIEW_H
#define MSBOARDTEXTVIEW_H

#include "MinesweeperBoard.h"

class MSBoardTextView {
    const MinesweeperBoard &board;

public:
    MSBoardTextView(const MinesweeperBoard &board);
    void display() const;
};

#endif