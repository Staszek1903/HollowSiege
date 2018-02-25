#include "WarriorSquirrel.h"



WarriorSquirrel::WarriorSquirrel()
{
	cooldown = 0;
}


WarriorSquirrel::~WarriorSquirrel()
{
}

void WarriorSquirrel::Attack(Entity & character)
{
	character.HP -= damagePoints;
	cooldown = cooldownConst;
}
