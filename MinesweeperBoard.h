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
    GameState state;
    int revealedFields = 0;
    int numberOfMines = 0;

    void clearBoard();
    int modeToPercent() const;
    void placeMinesRandomly();
public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;

    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    GameState getGameState() const;
    int countMines(int row, int col) const;
    bool hasFlag(int row, int col) const;
    bool hasMine(int row, int col) const;
    void toggleFlag(int row, int col);
    void revealField(int row, int col);
    bool isRevealed(int row, int col) const;
    char getFieldInfo(int row, int col) const;
    bool isValidField(int row, int col) const;

};
#endif //MINESWEEPERBOARD_H
