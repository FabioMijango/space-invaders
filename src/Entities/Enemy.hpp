#pragma once

#include "Entity.hpp"


class Enemy : public Entity {
public:
    Enemy(std::vector<sf::Texture>& textures, sf::Vector2f position, int health = 1); // TODO Implement health system

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

    std::vector<sf::Texture> &getTextures() const;
    sf::Vector2f getPosition() const override;
    sf::FloatRect getBounds() const override;

private:
    sf::Sprite sprite;
    std::vector<sf::Texture>& textures;
    sf::Vector2f direction;

    int health{};
    float velocity = 400.f;
};