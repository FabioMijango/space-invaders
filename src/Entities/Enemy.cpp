
#include "Enemy.hpp"

Enemy::Enemy(std::vector<sf::Texture>& textures, sf::Vector2f position, int health )
    : sprite(sf::Sprite(textures[1])),
        textures(textures),
        direction(1),
        health(health)
{
    sprite.setScale({7.f, 7.f});
    sprite.setPosition(position);
}

void Enemy::update(float deltaTime)
{
    sprite.move(sf::Vector2f(
        velocity * direction * deltaTime,
        0.f
        ));
}

void Enemy::changeDirection(const short newDir) {
    direction = newDir;
}

void Enemy::changeTexture(int textureIndex) {
    sprite.setTexture(textures[textureIndex]);
}

void Enemy::render(sf::RenderWindow &window)
{
    window.draw(sprite);
}

std::vector<sf::Texture> &Enemy::getTextures() const {
    return textures;
}

void Enemy::setPosition(const sf::Vector2f &position) {
    sprite.setPosition(position);
}

sf::Vector2f Enemy::getPosition() const
{
    return sprite.getPosition();
}

sf::FloatRect Enemy::getBounds() const
{
    return sprite.getGlobalBounds();
}

