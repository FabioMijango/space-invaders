
#include "Player.hpp"

Player::Player(const sf::Texture& playerTexture, sf::Vector2f pos, const sf::Texture& shootTexture)
	: sprite(sf::Sprite(playerTexture)) ,
	shootSprite(sf::Sprite(shootTexture))
{
	sprite.setScale({ 7.f, 7.f });
	sprite.setPosition(pos);

	shootSprite.setScale({7.f, 7.f});
	shootSprite.setPosition(getPosition() + sf::Vector2f(25.f, 0.f));
}

void Player::update(float deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && sprite.getPosition().x > 0)
        movement.x -= velocity * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && sprite.getPosition().x < WINDOW_WIDTH)
        movement.x += velocity * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && activeShoot) {
		activeShoot = false;
		setShoot();
	}

	if (!activeShoot) {
		shootSprite.move({0, -velocity * deltaTime});
		if (shootSprite.getPosition().y < 0) {
			activeShoot = true;
			shootSprite.setPosition(getPosition() + sf::Vector2f(25.f, 0.f));
		}
	}

	sprite.move(movement);
}

void Player::enemyGetHit() {
	activeShoot = true;
	shootSprite.setPosition(getPosition() + sf::Vector2f(25.f, 0.f));
}

sf::FloatRect Player::getShootBounds() const {
	return shootSprite.getGlobalBounds();
}

bool Player::canShoot() const {
	return activeShoot;
}

void Player::setShoot() {
	shootSprite.setPosition(getPosition() + sf::Vector2f( 25.f, 0.f));
}

void Player::render(sf::RenderWindow& window)
{
	if (!activeShoot) {
		window.draw(shootSprite);
	}
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
