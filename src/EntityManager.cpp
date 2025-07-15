#include "EntityManager.hpp"

#include <iostream>

EntityManager::EntityManager(ResourceManager& resourceManager)
	: levelManager(LevelManager()),
	player(Player(
		resourceManager.playerTexture,
		sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 100),
		resourceManager.shootTexture
		)),
	resourceManager(resourceManager)
{

	// TODO Change the player init

	// Initialize enemies
	for (int i = resourceManager.enemyTextures.size() - 1; i >= 0; i--) {
		enemies.push_back(
			Enemy(
				resourceManager.enemyTextures[i],
				sf::Vector2f(100.f * 1, 100.f),
				1) // TODO Implement health system
		);
	}
}


void EntityManager::update(float deltaTime)
{
	if (clock.getElapsedTime() > sf::seconds(1)){
		clock.restart();
		levelManager.changeTexture();
	}

	if (!levelManager.isActiveLevel()) {
		levelManager.startLevel(currentLevel, enemies);
	}
	//Player
	player.update(deltaTime);

	const auto lvlEnem = levelManager.levelEnemies;
	for (int i = 0; i < lvlEnem.size(); i++) {
		if (player.getShootBounds().findIntersection(lvlEnem[i].getBounds())) {
			player.enemyGetHit();
			levelManager.isEnemyDead[i]	= true;
			levelManager.levelEnemies[i].setPosition(sf::Vector2f(-100.f, -100.f)); // Move enemy off-screen
		}
	}
}


Player& EntityManager::getPlayer()
{
	return player;
}

std::vector<Enemy> & EntityManager::getLevelEnemies()  {
	return levelManager.levelEnemies;
}
std::vector<bool> & EntityManager::getIsEnemyDead() {
	return levelManager.isEnemyDead;
}

std::vector<Enemy>& EntityManager::getEnemies() {
	return enemies;
}

Level & EntityManager::getCurrentLevel() {
	return levelManager.getLevel(currentLevel);
}
