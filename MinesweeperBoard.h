#ifndef MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_H

#include "Array2D.h"

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

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

class MinesweeperBoard
{
    Array2D <Field> board = Array2D<Field>(0, 0);
    int width;
    int height;
    GameMode mode;

    void clearBoard();
    int modeToProcent() const;
    void placeMinesRandomly();
public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;

    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;

};
#endif //MINESWEEPERBOARD_H
