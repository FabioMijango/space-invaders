#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "../Utils/Constants.hpp"

// Player.hpp
class Player : public Entity {
public:
    Player(const sf::Texture &playerTexture, sf::Vector2f pos, const sf::Texture &shootTexture);

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

    sf::Vector2f getPosition() const override;
    sf::FloatRect getBounds() const override;

    bool canShoot() const;
    sf::FloatRect getShootBounds() const;

    void enemyGetHit();

private:
    sf::Sprite sprite;
    float velocity = 400.f;

    bool activeShoot = true;
    sf::Sprite shootSprite;

    void setShoot();
};
