#include "EntityManager.hpp"

EntityManager::EntityManager(ResourceManager& resourceManager)
	: levelManager(LevelManager()),
	player(Player(resourceManager.playerTexture, sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 100))),
	resourceManager(resourceManager)
{
	Enemy e = Enemy(resourceManager.enemyTextures[0][0], sf::Vector2f(500, 500), 1);
	enemies.push_back(e);
}

void EntityManager::addEntity(std::unique_ptr<Entity> entity)
{
}

void EntityManager::update(float deltaTime)
{
	//Player
	player.update(deltaTime);
}

Player& EntityManager::getPlayer()
{
	return player;
}

std::vector<Enemy>& EntityManager::getEnemies() {
	return enemies;
}

Level & EntityManager::getCurrentLevel() {
	return levelManager.getLevel(currentLevel);
}
