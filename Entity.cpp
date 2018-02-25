#include "Entity.h"

Entity::Entity()
{
}


Entity::~Entity()
{
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
    win.draw(sprite);
}

bool Entity::isColliding(Entity &en)
{
    return(en.Left() < Right() && en.Right() > Left() && en.Top() > Bottom() && en.Top());
}

void Entity::move(sf::Vector2f offset)
{
    sprite.move(offset.x, offset.y);
}

void Entity::rotate(float angle)
{
    sprite.rotate(angle);
}
