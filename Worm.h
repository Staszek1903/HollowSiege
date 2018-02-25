#pragma once
#include "Entity.h"
class Worm :
	public Entity
{
public:
	std::pair<float, float> coordinates;

	Worm(std::pair<float, float> );
	~Worm();

	void findClosestSquerrel();

	void update();
};

