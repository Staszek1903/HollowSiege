#pragma once
#include "Entity.h"
#include "workersquirrel.h"
#include "cmath"

class Worm :
	public Entity
{
	const float MAX_DIST_SQR;
public:

    Worm(std::pair<float, float>, float & scroll);
	~Worm();

	int findClosestSquerrel(std::vector<WorkerSquirrel> & workSquirrVec);

	void move(std::vector<WorkerSquirrel> & workSquirrVec, int id);

	bool damageIfPossible(std::vector<WorkerSquirrel>& workSquirrVec, int id, int dist);

	void update(std::vector<WorkerSquirrel> &workSquirrVec);
};


