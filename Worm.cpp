#include "Worm.h"



Worm::Worm(std::pair<float,float> coor) :  MAX_DIST_SQR(1000)
{
}



Worm::~Worm()
{
}

int Worm::findClosestSquerrel(std::vector<WorkerSquirrel> & workSquirrVec)
{
<<<<<<< HEAD
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
=======
>>>>>>> 6e8c5410ab4675c5ba4abe37b8cb45c493f7687d
}

void Worm::update(std::vector<WorkerSquirrel> &workSquirrVec)
{
	int unId = findClosestSquerrel(workSquirrVec);


}
