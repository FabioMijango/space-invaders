
#include "Player.hpp"

Player::Player(const sf::Texture& t, sf::Vector2f pos)
	: sprite(sf::Sprite(t))
{
	sprite.setScale({ 6.f, 6.f });
	sprite.setPosition(pos);
}

void Player::update(float deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && sprite.getPosition().x > 0)
        movement.x -= velocity * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && sprite.getPosition().x < 1080) // TODO : Replace with actual screen width
        movement.x += velocity * deltaTime;

	sprite.move(movement);
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(sprite);
}

sf::Vector2f Player::getPosition() const
{
	return sprite.getPosition();
}

sf::FloatRect Player::getBounds() const
{
	return sf::FloatRect();
}
