#include "Worm.h"



Worm::Worm(std::pair<float, float> coor, float & scroll) : MAX_DIST_SQR(1000000), Entity(scroll)
{
	this->sprite.setPosition(coor.first,coor.second);
}


Worm& Worm::operator =(const Worm &other)
{
    return *this;
}


Worm::~Worm()
{
}

int Worm::findClosestSquerrel(std::vector<WorkerSquirrel> & workSquirrVec)
{

	float minDist = FLT_MAX;
	int unId = -1;
	for (auto squerrel : workSquirrVec)
	{
		float dist = (squerrel.sprite.getPosition().y  - this->sprite.getPosition().y)*(squerrel.sprite.getPosition().y - this->sprite.getPosition().y) +
			(squerrel.sprite.getPosition().x - this->sprite.getPosition().x)*(squerrel.sprite.getPosition().x - this->sprite.getPosition().x);
		if (dist < MAX_DIST_SQR && dist < minDist)
		{
			minDist = dist;
			unId = squerrel.id;
		}
	}
	//std::cout << minDist << std::endl;
	if (damageIfPossible(workSquirrVec, unId, minDist))
	{
		return -1;
	}
	return unId;
}

void Worm::moveToSqrl(std::vector<WorkerSquirrel> &workSquirrVec, int id)
{
	for (auto sqrl : workSquirrVec)
	{
		if (sqrl.id == id)
		{
			sf::Vector2f vec;
			vec.x = sqrl.sprite.getPosition().x - this->sprite.getPosition().x;
			vec.y = sqrl.sprite.getPosition().y - this->sprite.getPosition().y;

			float vecLengh = sqrtf(vec.x*vec.x + vec.y*vec.y);
			
			vec /= vecLengh;
			vec.x *= 4;
			vec.y *= 4;
			this->sprite.setPosition(this->sprite.getPosition().x + vec.x, this->sprite.getPosition().y + vec.y);
		}
	}
}
void Worm::moveToBase()
{
	sf::Vector2f vec;
	vec.x = 400 - this->sprite.getPosition().x;
	vec.y = 0 - this->sprite.getPosition().y;

	float vecLengh = sqrtf(vec.x*vec.x + vec.y*vec.y);

	vec /= vecLengh;
	
	if (vecLengh > 1)
	{
		this->sprite.setPosition(this->sprite.getPosition().x + vec.x, this->sprite.getPosition().y + vec.y);
	}
}
bool Worm::damageIfPossible(std::vector<WorkerSquirrel> &workSquirrVec, int id, int dist)
{
	for (auto &sqrl : workSquirrVec)
	{
		
		if (sqrl.id == id && dist < 10000)
		{
			
			sqrl.HP -= 3;
			return true;
		}
	}
	return false;
}

void Worm::update(std::vector<WorkerSquirrel> &workSquirrVec)
{
	int unId = findClosestSquerrel(workSquirrVec);

	if (unId >= 0)
	{
		moveToSqrl(workSquirrVec, unId);
	}
	else
	{
		moveToBase();
	}

}
