#pragma once
#include <iostream>
#include "Entity.h"
#include "workersquirrel.h"
#include "cmath"

class Worm :
	public Entity
{
	const float MAX_DIST_SQR;
public:

	Worm(std::pair<float, float> coor, float & scroll);
	Worm operator=(const Worm &);
	~Worm();

	int findClosestSquerrel(std::vector<WorkerSquirrel> & workSquirrVec);

	void moveToSqrl(std::vector<WorkerSquirrel> & workSquirrVec, int id);

	void moveToBase();

	bool damageIfPossible(std::vector<WorkerSquirrel>& workSquirrVec, int id, int dist);

	void update(std::vector<WorkerSquirrel> &workSquirrVec);
};


