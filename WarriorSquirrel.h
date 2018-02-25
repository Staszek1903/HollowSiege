#pragma once
#include "Entity.h"
#include "Worm.h"
#include <vector>
#include <utility>
#include <cmath>
class WarriorSquirrel :
	public Entity
{
public:
	WarriorSquirrel();
	~WarriorSquirrel();

	const float damagePoints = 5;
	const float cooldownConst = 50;// obojetne ile
	const float range = 100;// np w pixelach, w jakims managerze obslugiwac kiedy moze atakowac??
	const float speed = 5;

	float cooldown;

	float Distance(sf::Vector2f a, sf::Vector2f b);

	void Attack(Entity& character);

	sf::Vector2f TargetClosestEnemyPosition(std::vector<Worm> worms);

	void MoveToPosition(sf::Vector2f position);


};

