#include "WarriorSquirrel.h"



WarriorSquirrel::WarriorSquirrel(float &scroll)
    :Entity(scroll)
{
	cooldown = 0;
	targetPosition = { 400,100 };
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
	if(isColliding(character) && cooldown == 0)
	{
		character.HP -= damagePoints;
		cooldown = cooldownConst;
	}
}

sf::Vector2f WarriorSquirrel::TargetClosestEnemyPosition(std::vector<Worm> worms)
{
	float tmpDist;
	std::pair<int, float> minDist;
	minDist.first = 0;
	tmpDist = Distance(worms.at(0).sprite.getPosition(),sprite.getPosition());
	minDist.second = tmpDist;
	for (unsigned i = 1; i < worms.size(); ++i)
	{
		tmpDist = Distance(worms.at(i).sprite.getPosition(), sprite.getPosition());
		if (tmpDist<minDist.second && tmpDist<=range)
		{
			minDist.first = i;
			minDist.second = tmpDist;
		}
	}
	if (minDist.second > range)
		return sprite.getPosition();
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

void WarriorSquirrel::Input(sf::Event e)
{
	if (e.type == sf::Event::MouseButtonPressed)
	{
		if (e.mouseButton.button == sf::Mouse::Left)
		{
			targetPosition.x = static_cast<float>(sf::Mouse::getPosition().x);
			targetPosition.y = static_cast<float>(sf::Mouse::getPosition().y);
		}
	}
}

void WarriorSquirrel::Update(std::vector <Worm> worms)
{
	if (targetPosition != sprite.getPosition())
	{
		MoveToPosition(targetPosition);
	}
	if(TargetClosestEnemyPosition(worms)!=sprite.getPosition())
	{ 
		MoveToPosition(TargetClosestEnemyPosition(worms));
	}
	for(unsigned i = 0; i < worms.size(); ++i)
	{
		if (isColliding(worms.at(i)))
		{
			Attack(worms.at(i));
		}
	}
}
