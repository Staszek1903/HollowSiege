#pragma once
#include "Entity.h"
class WarriorSquirrel :
	public Entity
{
public:
	WarriorSquirrel();
	~WarriorSquirrel();

	const float damagePoints = 5;
	const float cooldownConst = 50;// obojetne ile
	const float range = 100;// np w pixelach, w jakims managerze obslugiwac kiedy moze atakowac??

	float cooldown;

	void Attack(Entity& character);

};

