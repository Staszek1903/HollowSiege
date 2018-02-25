#include "workersquirrel.h"

WorkerSquirrel::WorkerSquirrel()
    :has_nut(false),root_level(0.0f)
{

}

void WorkerSquirrel::set_root_level(float l)
{
    root_level = l;
}

void WorkerSquirrel::update()
{
    if(has_nut)
    {

    }
    else
    {

        move(sf::Vector2f(0, -5));

    }
}
