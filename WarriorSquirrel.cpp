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
	if (cooldown == 0)
	{
		character.HP -= damagePoints;
		cooldown = cooldownConst;
	}
}

sf::Vector2f WarriorSquirrel::TargetClosestEnemyPosition(std::vector<Worm> worms)
{
	std::pair<int, float> minDist;
	minDist.first = 0;
	minDist.second = Distance(worms.at(0).sprite.getPosition(),sprite.getPosition());
	float tmpDist;
	for (unsigned i = 1; i < worms.size(); ++i)
	{
		tmpDist = Distance(worms.at(i).sprite.getPosition(), sprite.getPosition());
		if (tmpDist<minDist.second && tmpDist<=range)
		{
			minDist.first = i;
			minDist.second = tmpDist;
		}
	}
	return worms.at(minDist.first).sprite.getPosition();
}

void WarriorSquirrel::MoveToPosition(sf::Vector2f position)
{
	if (position.x > sprite.getPosition().x)
		move({ speed, 0 });
	else
		move({ -speed,0 });
	if (position.y > sprite.getPosition().y)
		move({ 0,speed });
	else 
		move({ 0,-speed });
}
