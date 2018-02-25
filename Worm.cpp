#include "Worm.h"



Worm::Worm(std::pair<float,float> coor) :  MAX_DIST_SQR(1000)
{
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

		float dist = (this->sprite.getPosition().x*this->sprite.getPosition().x - this->sprite.getPosition().y*this->sprite.getPosition().y) +
			(squerrel.sprite.getPosition().x*squerrel.sprite.getPosition().x - squerrel.sprite.getPosition().y*squerrel.sprite.getPosition().y);
		if (dist < MAX_DIST_SQR && dist < minDist)
		{
			minDist = dist;
			unId = squerrel.id;
		}
	}
	if (damageIfPossible(workSquirrVec, unId, minDist))
	{
		return -1;
	}
	return unId;
}

void Worm::move(std::vector<WorkerSquirrel> &workSquirrVec, int id)
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

			this->sprite.setPosition(this->sprite.getPosition().x + vec.x, this->sprite.getPosition().y + vec.y);
		}
	}
}
bool Worm::damageIfPossible(std::vector<WorkerSquirrel> &workSquirrVec, int id, int dist)
{
	for (auto sqrl : workSquirrVec)
	{
		if (sqrl.id == id && dist < 10)
		{
			sqrl.HP -= 0.1;
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
		move(workSquirrVec, unId);
	}

}
