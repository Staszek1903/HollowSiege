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
}

float Entity::Left()
{
	return sprite.getPosition().x;
}

float Entity::Right()
{
	return sprite.getPosition().x+sprite.getTextureRect().width;
}

float Entity::Top()
{
	return sprite.getPosition().y;
}

float Entity::Bottom()
{
	return sprite.getPosition().y + sprite.getTextureRect().height;
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
