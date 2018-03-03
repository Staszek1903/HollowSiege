#include "Entity.h"

Entity::Entity(float & scroll)
    :scrollOffset(scroll), HP(100)
{
    static int id_count = 0;
    id = id_count++;
}

Entity::~Entity() 
{
}

Entity &Entity::operator=(const Entity &other)
{
    id = other.id;

    sprite = other.sprite;
    bounding = other.bounding;
    lastPos = other.lastPos;
    scrollOffset = other.scrollOffset;

    HP = other.HP;

    return *this;
}

void Entity::SetSpriteTexture(sf::Texture &tex)
{
    sprite.setTexture(tex);
    auto texR = sprite.getTextureRect();
    bounding = texR;
    sprite.setOrigin(texR.width/2, texR.height/2);
}

float Entity::Left()
{
    return sprite.getPosition().x - bounding.width/2;
}

float Entity::Right()
{
    return sprite.getPosition().x + bounding.width/2;
}

float Entity::Top()
{
    return sprite.getPosition().y - bounding.height/2;
}

float Entity::Bottom()
{
    return sprite.getPosition().y + bounding.height/2;
}

void Entity::Draw(sf::RenderWindow& win)
{
    sf::Vector2f pos = sprite.getPosition();
    sprite.move(sf::Vector2f(0,scrollOffset));
    win.draw(sprite);
    sprite.setPosition(pos);
}

bool Entity::isColliding(Entity &en)
{
    return(en.Left() < Right() && en.Right() > Left() && en.Top() > Bottom() && en.Top());
}

bool Entity::hasPoint(sf::Vector2i p)
{
    return (p.x<Right() && p.x>Left() && p.y>Top() && p.y < Bottom());
}

void Entity::move(sf::Vector2f offset)
{
    sprite.move(offset.x, offset.y);
}

void Entity::setPosition(sf::Vector2f pos)
{
    sprite.setPosition(pos);
}

void Entity::rotate(float angle)
{
    sprite.rotate(angle);
}
