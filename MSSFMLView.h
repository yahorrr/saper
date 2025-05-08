#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>

class MSSFMLView {
    MinesweeperBoard & board;
public:
    MSSFMLView(MinesweeperBoard & board);
    void draw(sf::RenderWindow &window)const;
};

#endif //SAPER_MSSFMLVIEW_H
