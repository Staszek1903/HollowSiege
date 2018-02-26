#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <sstream>
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

    sf::Sprite background, nut;
    sf::Texture bg_tex, nut_tex;

    sf::Font comic;
    sf::Text nut_am;
    int nut_amount;

    int scroll_state; // 0=NULL -1=UP 1=DOWN

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
	void spawnR();
	void spawnT();
private:
    void input();
    void update();
    void render();
};

#endif // GAME_H
