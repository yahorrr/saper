#include "MSSFMLView.h"

using namespace std;

MSSFMLView::MSSFMLView(MinesweeperBoard &board) : board(board) {}

void MSSFMLView::draw(sf::RenderWindow &window) const {

    constexpr int fieldSize = 32;
    unsigned int window_width = fieldSize * board.getBoardWidth();
    unsigned int window_height = fieldSize * board.getBoardHeight();


    sf::RectangleShape cell(sf::Vector2f(fieldSize, fieldSize)); // Kształt komórki planszy


    sf::FloatRect visibleArea(0, 0, window_width, window_height);
    window.setView(sf::View(visibleArea));
    window.setSize({window_width, window_height});

    // Załaduj czcionkę
    sf::Font font;
    if (!font.loadFromFile("C:/Users/user/Documents/PO/saper/git/saper_yahor_lazarevich/arialmt.ttf")) {
        std::cerr << "Błąd ładowania czcionki Arial!" << std::endl;
        return;
    }

    sf::Texture t;
    t.loadFromFile("C:/Users/user/Documents/PO/saper/git/saper_yahor_lazarevich/images/tiles.jpg");
    sf::Sprite s(t);



    for (int row = 0; row < board.getBoardHeight(); ++row) {
        for (int col = 0; col < board.getBoardWidth(); ++col) {

            cell.setPosition(col * fieldSize, row * fieldSize);

            // Ustawienie koloru komórki w zależności od stanu pola
            sf::Color color;
            if (board.isRevealed(row, col)) {
                // Jeśli pole jest odkryte
                if (board.hasMine(row, col)) {
                    // Jeśli pole ma minę, wybierz odpowiedni fragment tekstury, który reprezentuje minę
                    s.setTextureRect(sf::IntRect(9 * fieldSize, 0, fieldSize, fieldSize));
                    s.setPosition(col * fieldSize, row * fieldSize);
                    // Narysowanie tekstury na ekranie
                    window.draw(s);
                } else {
                    // Jeśli pole nie ma miny, wybierz odpowiedni fragment tekstury, który reprezentuje liczbę min wokół tego pola
                    int minesAround = board.countMines(row, col);

                    s.setTextureRect(sf::IntRect(minesAround * fieldSize, 0, fieldSize, fieldSize));
                    s.setPosition(col * fieldSize, row * fieldSize);

                    window.draw(s);
                }
            } else {
                // Jeśli pole nie jest odkryte
                if (board.hasFlag(row, col)) {
                    // Jeśli pole ma flagę, wybierz odpowiedni fragment tekstury, który reprezentuje flagę
                    s.setTextureRect(sf::IntRect(11 * fieldSize, 0, fieldSize, fieldSize));
                    s.setPosition(col * fieldSize, row * fieldSize);
                    // Narysowanie tekstury na ekranie
                    window.draw(s);
                } else {
                    // Jeśli pole nie ma flagi ani nie jest odkryte, wybierz odpowiedni fragment tekstury, który reprezentuje zakryte pole
                    s.setTextureRect(sf::IntRect(10 * fieldSize, 0, fieldSize, fieldSize));
                    s.setPosition(col * fieldSize, row * fieldSize);
                    // Narysowanie tekstury na ekranie
                    window.draw(s);
                }
            }
        }
    }
}