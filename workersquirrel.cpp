#include "workersquirrel.h"

WorkerSquirrel::WorkerSquirrel(float & scroll)
    :has_nut(false),root_level(0.0f), Entity(scroll)
{

}

void WorkerSquirrel::set_root_level(float l)
{
    root_level = l;
}

void WorkerSquirrel::update(std::vector<Nut> &nuts)
{
    if(has_nut)
    {
        float vpos = sprite.getPosition().x;
        vpos -= 400;
        float hpos = sprite.getPosition().y;

        if(hpos <0)
            has_nut = false;

        if(abs(vpos) <20)
            move(sf::Vector2f(0, -WORKERSPEED));
        else
        {
            if(vpos>0)
                move(sf::Vector2f(-WORKERSPEED, 0));
            else
                move(sf::Vector2f(WORKERSPEED,0));
        }
    }
    else
    {
        if(sprite.getPosition().y < root_level)
            move(sf::Vector2f(0, WORKERSPEED));
        else
        {
            float dist = FLT_MAX;
            Nut *target = nullptr;
            for(auto &n:nuts)
            {
                float temp = dist_to_nut(n);
                target =(temp<dist)? &n:target;
                dist = (temp<dist)? temp:dist;
            }

            if( dist > 10)
            {
                sf::Vector2f distv = sprite.getPosition() - target->sprite.getPosition();
                normalize(distv);
                distv *= WORKERSPEED;
                move(distv);

                dist = dist_to_nut(*target);
            }
            else
            {
                has_nut = true;
            }

        }

    }
}

void WorkerSquirrel::normalize(sf::Vector2f &vect)
{
    float l = sqrt(vect.x*vect.x + vect.y*vect.y);
    vect /= l;
}

float WorkerSquirrel::dist_to_nut(Nut &nut)
{
    sf::Vector2f pos = sprite.getPosition();
    sf::Vector2f pos2 = nut.sprite.getPosition();

    sf::Vector2f rel = pos - pos2;

    return sqrt(rel.x*rel.x + rel.y*rel.y);
}
