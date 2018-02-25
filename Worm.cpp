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
	return unId;
}

void Worm::move(int id)
{

}

void Worm::update(std::vector<WorkerSquirrel> &workSquirrVec)
{
	int unId = findClosestSquerrel(workSquirrVec);

	if (unId >= 0)
	{
		move(unId);
	}

}
