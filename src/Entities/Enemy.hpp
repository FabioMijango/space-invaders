#pragma once

#include "Entity.hpp"

enum Direction {
    LEFT = -1,
    RIGHT = 1
};

class Enemy : public Entity {
public:
    Enemy(std::vector<sf::Texture>& textures, sf::Vector2f position, int health = 1); // TODO Implement health system

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

    std::vector<sf::Texture> &getTextures() const;

    sf::Vector2f getPosition() const override;
    void setPosition(const sf::Vector2f& position);

    void changeDirection(Direction newDir);

    sf::FloatRect getBounds() const override;

    void changeTexture(int textureIndex);

private:
    sf::Sprite sprite;
    std::vector<sf::Texture>& textures;
    short direction;

    int health;
    float velocity = 400.f;
};
