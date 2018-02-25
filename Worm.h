#pragma once
#include "Entity.h"
#include "workersquirrel.h"
class Worm :
	public Entity
{
	const float MAX_DIST_SQR;
public:

	Worm(std::pair<float, float>);
	~Worm();

	int findClosestSquerrel(std::vector<WorkerSquirrel> & workSquirrVec);

	void move(int id);

	void update(std::vector<WorkerSquirrel> &workSquirrVec);
};


