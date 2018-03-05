#include "WarriorSquirrel.h"



WarriorSquirrel::WarriorSquirrel(float &scroll,std::vector <Worm>& worms)
    :Entity(scroll), worms(worms), active(false), target(sf::Vector2f(0,0)), targeting(false)
{
    cooldown = 0;
}


WarriorSquirrel& WarriorSquirrel::operator =(const WarriorSquirrel &w)
{
    cooldown = w.cooldown;

    return *this;
}


WarriorSquirrel::~WarriorSquirrel()
{
}


void WarriorSquirrel::Input(sf::Event e)
{
    if( e.type == sf::Event::MouseMoved)
    {
        mousePos = sf::Vector2i(e.mouseMove.x, e.mouseMove.y);
    }

	if (e.type == sf::Event::MouseButtonPressed)
	{
        if (e.mouseButton.button == sf::Mouse::Right)
		{
            sf::Vector2i temp(mousePos.x, mousePos.y - scrollOffset);
            if(hasPoint(mousePos))
                    active = true;
            else
                    active = false;
		}

        if(e.mouseButton.button == sf::Mouse::Left)
         {
            if(active)
            {
                std::cout<<"przypis"<<std::endl;
                target = sf::Vector2f(mousePos.x,mousePos.y - scrollOffset);
                targeting = true;
            }
         }
    }
}

float WarriorSquirrel::dist(sf::Vector2f a, sf::Vector2f b)
{
    sf::Vector2f rel = a -b;
    return sqrt(rel.x*rel.x + rel.y*rel.y);
}

float WarriorSquirrel::normalize(sf::Vector2f &a)
{
    float l = sqrt(a.x*a.x + a.y*a.y);
    a/=l;
	return 0;
}

void WarriorSquirrel::targetStep()
{
    if(!targeting)
        return;

    sf::Vector2f distv = target - sprite.getPosition();
    normalize(distv);
    sprite.move(distv*WARRIORSPEED);
}

void WarriorSquirrel::Update()
{


    if(dist(target, sprite.getPosition())>10)
        targetStep();

    //std::cout<<"target"<<target.x<<" "<<target.y<<std::endl;
    //std::cout<<"pos: "<<sprite.getPosition().x<<" "<<sprite.getPosition().y<<std::endl;
    //std::cout<<"active: "<<active<<std::endl;
}
