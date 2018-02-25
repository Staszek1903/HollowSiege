#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include "Entity.h"
#include "WarriorSquirrel.h"
#include "workersquirrel.h"
#include "Worm.h"
#include "TreePart.h"
#include "nut.h"

class Game
{
    sf::RenderWindow window;
    //Entity e1;

    sf::Sprite background;
    sf::Texture bg_tex;

    std::default_random_engine engine;
    float scroll;
	sf::Clock clk;
	sf::Time time;
    Nut temp_nut;
public:
	std::vector<WorkerSquirrel> workSqrVec;
	std::vector<WarriorSquirrel> warSqrVec;
	std::vector<Worm> wormVec;
    std::vector<TreePart> treeParts;
    std::vector<Nut> nuts;

    Game();
    void run();
private:
    void input();
    void update();
    void render();
};

#endif // GAME_H
