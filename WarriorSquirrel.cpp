#include "WarriorSquirrel.h"



WarriorSquirrel::WarriorSquirrel()
{
	cooldown = 0;
}


WarriorSquirrel::~WarriorSquirrel()
{
}

float WarriorSquirrel::Distance(sf::Vector2f a, sf::Vector2f b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void WarriorSquirrel::Attack(Entity & character)
{
	character.HP -= damagePoints;
	cooldown = cooldownConst;
}

sf::Vector2f WarriorSquirrel::TargetClosestEnemyPosition(std::vector<Worm> worms)
{
	float minDist = Distance(worms.at(0).sprite.getPosition,);
	for (int i = 1; i < worms.size(); ++i)
	{

	}
	return sf::Vector2f();
}

void WarriorSquirrel::MoveToPosition(sf::Vector2f position)
{
}
