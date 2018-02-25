#ifndef WORKERSQUIRREL_H
#define WORKERSQUIRREL_H

#include "Entity.h"
#include "nut.h"
#include <cmath>
#include <cfloat>
#include <iostream>

#define WORKERSPEED 3.0f

class WorkerSquirrel : public Entity
{
    float root_level;
    bool has_nut;

public:
    WorkerSquirrel(float &scroll);
    WorkerSquirrel& operator=(const WorkerSquirrel & w);
    void set_root_level(float l);
    void update(std::vector<Nut> &nuts);

    void normalize(sf::Vector2f & vect);
    float dist_to_nut(Nut & nut);
};

#endif // WORKERSQUIRREL_H
