#pragma once

#include <SFML/Graphics.hpp>

// Entity Class: Abstract base class for all game entities
class Entity 
{
public:
	virtual ~Entity() = default;

	virtual void update(float deltaTime) = 0;
	virtual void render(sf::RenderWindow& window) = 0;

	virtual sf::Vector2f getPosition() const = 0;
	virtual sf::FloatRect getBounds() const = 0;
};
