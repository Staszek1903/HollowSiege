#pragma once
#include "Entity.h"
#include "workersquirrel.h"
class Worm :
	public Entity
{
	const float MAX_DIST_SQR;
public:
	std::pair<float, float> coordinates;

	Worm(std::pair<float, float>);
	~Worm();

	void findClosestSquerrel(std::vector<WorkerSquirrel> & workSquirrVec);

	void update(std::vector<WorkerSquirrel> &workSquirrVec);
};


