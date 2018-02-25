#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "WarriorSquirrel.h"
#include "workersquirrel.h"

class Game
{
    sf::RenderWindow window;
    Entity e1;

public:
	std::vector<WarriorSquirrel> warSquirrVec;
	std::vector<Worm> wormVec;
	std::vector<WorkerSquirrel> workSquirrVec;
    Game();
    void run();
private:
    void input();
    void update();
    void render();
};

#endif // GAME_H
