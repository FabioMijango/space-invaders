
#include "Enemy.hpp"

Enemy::Enemy(const sf::Texture& t, sf::Vector2f position, int healt)
    : sprite(sf::Sprite(t)), healt(healt)
{
    sprite.setPosition(position);
    sprite.setScale({7.f, 7.f});
}

void Enemy::update(float deltaTime)
{
}

void Enemy::render(sf::RenderWindow &window)
{
    window.draw(sprite);
}

sf::Vector2f Enemy::getPosition() const
{
    return sprite.getPosition();
}

sf::FloatRect Enemy::getBounds() const
{
    return sf::FloatRect({});
}

void Enemy::destroy() {
}
