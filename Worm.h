#pragma once
#include <iostream>
#include "Entity.h"
#include "workersquirrel.h"
#include "cmath"
#include "Base.h"

class Worm :
	public Entity
{
	const float MAX_DIST_SQR;
	float baseDmg;
public:

	Worm(std::pair<float, float> coor, float & scroll);

    Worm& operator=(const Worm & other);

	~Worm();

	int findClosestSquerrel(std::vector<WorkerSquirrel> & workSquirrVec);

	void moveToSqrl(std::vector<WorkerSquirrel> & workSquirrVec, int id);

	void moveToBase(Base &b);

	bool damageIfPossible(std::vector<WorkerSquirrel>& workSquirrVec, int id, int dist);

	void update(std::vector<WorkerSquirrel> &workSquirrVec, Base &b);
};


