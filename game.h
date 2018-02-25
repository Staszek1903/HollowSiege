#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Game
{
    sf::RenderWindow window;
    Entity e1;

public:
    Game();
    void run();
private:
    void input();
    void update();
    void render();
};

#endif // GAME_H
