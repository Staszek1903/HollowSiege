#include "workersquirrel.h"

WorkerSquirrel::WorkerSquirrel(float & scroll)
    :has_nut(false),root_level(0.0f), Entity(scroll)
{
    root_level = 2200;
    sprite.rotate(180);
}

WorkerSquirrel& WorkerSquirrel::operator =(const WorkerSquirrel &w)
{
    root_level = w.root_level;
    has_nut = w.has_nut;
    return *this;
}

void WorkerSquirrel::set_root_level(float l)
{
    root_level = l;
}

bool WorkerSquirrel::update(std::vector<Nut> &nuts)
{
    bool ret = false;
   // std::cout<<has_nut<<std::endl;
    if(has_nut)
    {
        float vpos = sprite.getPosition().x;
        vpos -= 400;
        float hpos = sprite.getPosition().y;

        if(hpos <0)
        {
            has_nut = false;
            sprite.rotate(180);
            ret = true;

        }

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
            int nut_iter =0;
            for(int i=0; i<nuts.size(); ++i)
            {
                Nut &n = nuts.at(i);
                float temp = dist_to_nut(n);
                target =(temp<dist)? &n:target;
                nut_iter = (temp<dist)? i:nut_iter;
                dist = (temp<dist)? temp:dist;
            }

           // std::cout<<dist<<std::endl;
            if( dist > 10)
            {

                sf::Vector2f distv =  target->sprite.getPosition() - sprite.getPosition();
                normalize(distv);
                distv *= WORKERSPEED;
                //std::cout<<"distv: "<<distv.x<< "  "<<distv.y<<std::endl;
                move(distv);

                dist = dist_to_nut(*target);
            }
            else
            {
                has_nut = true;
                nuts.erase(nuts.begin()+nut_iter);
                sprite.rotate(180);
            }

        }

    }

    return ret;
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
