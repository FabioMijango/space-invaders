#include "EntityManager.hpp"

EntityManager::EntityManager(ResourceManager& resourceManager)
	: player(Player(resourceManager.playerTexture, sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 100))),
	resourceManager(resourceManager)
{
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
