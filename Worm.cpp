#include "Worm.h"



Worm::Worm(std::pair<float,float> coor) : coordinates(coor) , MAX_DIST_SQR(1000)
{
}



Worm::~Worm()
{
}

void Worm::findClosestSquerrel(std::vector<WorkerSquirrel> & workSquirrVec;)
{
}

void Worm::update(std::vector<WorkerSquirrel> &workSquirrVec)
{
	findClosestSquerrel(workSquirrVec);
}
