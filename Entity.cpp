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

    texture = other.texture;
    sprite = other.sprite;
    bounding = other.bounding;
    lastPos = other.lastPos;
    scrollOffset = other.scrollOffset;
	std::cout << "opp";
	HP = other.HP;

    return *this;
}

void Entity::SetSpriteTexture(std::string texturePath)
{
	texture.loadFromFile(texturePath);
	sprite.setTexture(texture);
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
