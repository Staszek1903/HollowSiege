#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "WarriorSquirrel.h"
#include "workersquirrel.h"
#include "Worm.h"
#include "TreePart.h"

class Game
{
    sf::RenderWindow window;
    Entity e1;

    sf::Sprite background;
    sf::Texture bg_tex;

public:
	std::vector<WorkerSquirrel> workSqrVec;
	std::vector<WarriorSquirrel> warSqrVec;
	std::vector<Worm> wormVec;
	TreePart treeParts[5];

    Game();
    void run();
private:
    void input();
    void update();
    void render();
};

#endif // GAME_H
