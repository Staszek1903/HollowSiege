#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <string>

class Entity
{
public:
    Entity(float & scroll);
	~Entity();

    Entity& operator=(const Entity& other);

    int id;

	sf::Texture texture;
	sf::Sprite sprite;
    sf::Rect<int> bounding;
    sf::Vector2f lastPos;
    float & scrollOffset;

	float HP;

	float Left();
	float Right();
	float Top();
	float Bottom();

	void SetSpriteTexture(std::string texturePath);
	void Draw(sf::RenderWindow& win);

    bool isColliding(Entity & en);
    void move(sf::Vector2f offset);
    void setPosition(sf::Vector2f);
    void rotate(float angle);
};

#endif // ENTITY_H
