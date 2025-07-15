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
	if (!levelManager.isActiveLevel()) {
		levelManager.startLevel(currentLevel, enemies);
	}
	//Player
	player.update(deltaTime);
}

Player& EntityManager::getPlayer()
{
	return player;
}

std::vector<Enemy> & EntityManager::getLevelEnemies()  {
	return levelManager.levelEnemies;
}

std::vector<Enemy>& EntityManager::getEnemies() {
	return enemies;
}

Level & EntityManager::getCurrentLevel() {
	return levelManager.getLevel(currentLevel);
}
