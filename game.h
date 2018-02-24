#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game
{
    sf::RenderWindow window;

public:
    Game();
    void run();
private:
    void input();
    void update();
    void render();
};

#endif // GAME_H
