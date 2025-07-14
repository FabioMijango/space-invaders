
#pragma once


#include "ResourceManager.hpp"
#include "LevelManager.hpp"
#include "Renderer.hpp"
#include "./Entities/Entity.hpp"
#include "./Entities/Player.hpp"
#include "./Entities/Enemy.hpp"
#include "./Utils/Constants.hpp"


class EntityManager
{
public:
	EntityManager(ResourceManager& resourceManager);


	void update(float deltaTime);


	Player& getPlayer();

	std::vector<Enemy>& getEnemies();

	Level& getCurrentLevel();

	std::vector<Enemy>& getLevelEnemies();


private:
	int currentLevel = 0;
	LevelManager levelManager;

	Player player;
	std::vector<Enemy> enemies;
	//std::vector<Structure> structures;

	ResourceManager& resourceManager;

	sf::Clock clock;
};