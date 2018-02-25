#ifndef WORKERSQUIRREL_H
#define WORKERSQUIRREL_H

#include "Entity.h"

class WorkerSquirrel : public Entity
{
    float root_level;
    bool has_nut;

public:
    WorkerSquirrel();
    void set_root_level(float l);
    void update();
};

#endif // WORKERSQUIRREL_H
