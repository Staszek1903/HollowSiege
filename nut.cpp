#include "nut.h"

Nut::Nut(float & scroll)
    :Entity(scroll)
{
    sprite.setScale(0.3f,0.3f);
}
