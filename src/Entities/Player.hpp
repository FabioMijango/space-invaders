#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "../Utils/Constants.hpp"

// Player.hpp
class Player : public Entity {
public:
    Player(const sf::Texture& t, sf::Vector2f pos);

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

    sf::Vector2f getPosition() const override;
    sf::FloatRect getBounds() const override;

private:
    sf::Sprite sprite;
    float velocity = 400.f;
};
