#ifndef MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_H

#include "Array2D.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

enum GameMode  { DEBUG, EASY, NORMAL, HARD };

class MinesweeperBoard
{
    Array2D <Field> board = Array2D<Field>(0, 0);
    int width;
    int height;
    void clearBoard();

public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;
};
#endif //MINESWEEPERBOARD_H
