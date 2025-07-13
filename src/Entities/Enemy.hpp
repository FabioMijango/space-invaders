#pragma once

#include "Entity.hpp"


class Enemy : public Entity {
public:
    Enemy(const sf::Texture& texture, sf::Vector2f position, int healt = 1);

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

    sf::Vector2f getPosition() const override;
    sf::FloatRect getBounds() const override;

private:
    sf::Sprite sprite;
    sf::Vector2f direction;

    int healt;
    float velocity = 400.f;
};