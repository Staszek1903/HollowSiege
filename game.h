#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <sstream>
#include <vector>
#include "Entity.h"
#include "WarriorSquirrel.h"
#include "workersquirrel.h"
#include "Worm.h"
#include "TreePart.h"
#include "nut.h"
#include "texcontainer.h"
#include "Base.h"

class Game
{
    sf::RenderWindow window;
    //Entity e1;

    TexContainer cont;
    sf::Sprite background, nut, wor_inst, atk_inst;

    sf::Font comic;
    sf::Text nut_am;
    int nut_amount;

    int scroll_state; // 0=NULL -1=UP 1=DOWN

    std::default_random_engine engine;
    float scroll, freqOfSpawningWorms;
	sf::Clock clk, wormClk, gameTimeWorm;
	sf::Time time, timeWormResp;
    Nut temp_nut;
	Base base;
	//WorkerSquirrel newWorker;
	//WarriorSquirrel newWarior;
	//Worm newWorm;
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
	void spawnWorm();
	void manageWarmSpawn();
	void update();
    void render();
    void nut_update(int i);
};

#endif // GAME_H
