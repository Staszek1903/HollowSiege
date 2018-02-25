#pragma once
#include <SFML\Graphics.hpp>
#include <string>

class Entity
{
public:
	Entity();
	~Entity();

	sf::Texture texture;
	sf::Sprite sprite;

	float HP;

	float Left();
	float Right();
	float Top();
	float Bottom();

	void SetSpriteTexture(std::string texturePath);
	void Draw(sf::RenderWindow& win);
};

