
#pragma once


#include "ResourceManager.hpp"
#include "Renderer.hpp"
#include "./Entities/Entity.hpp"
#include "./Entities/Player.hpp"
#include "./Entities/Enemy.hpp"
#include "./Utils/Constants.hpp"


class EntityManager
{
public:
	EntityManager(ResourceManager& resourceManager);

	void addEntity(std::unique_ptr<Entity> entity);

	void update(float deltaTime);


	Player& getPlayer();

	std::vector<Enemy>& getEnemies();


private:
	Player player;
	std::vector<Enemy> enemies;
	//std::vector<Structure> structures;

	ResourceManager resourceManager;

	sf::Clock clock;
};