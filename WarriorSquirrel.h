#pragma once
#include "Entity.h"
#include "Worm.h"
#include <vector>
#include <utility>
#include <cmath>

#define WARRIORSPEED 4.0f

class WarriorSquirrel :
	public Entity
{
public:
    WarriorSquirrel(float &scroll, std::vector<Worm> &worms);

    WarriorSquirrel& operator=(const WarriorSquirrel & w);

	~WarriorSquirrel();

	const float damagePoints = 5;
	const float cooldownConst = 50;// obojetne ile
	const float range = 100;// np w pixelach, w jakims managerze obslugiwac kiedy moze atakowac??
	const float speed = 5;

    std::vector <Worm> &worms;

	float cooldown;
    bool active, targeting;
    sf::Vector2i mousePos;
    sf::Vector2f target;

	void Input(sf::Event e);
    float dist(sf::Vector2f a, sf::Vector2f b);
    float normalize(sf::Vector2f & a);
    void targetStep();
    void Update();
};

