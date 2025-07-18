#include "EntityManager.hpp"

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
		enemies.emplace_back(
				resourceManager.enemyTextures[i],
				sf::Vector2f(100.f * 1, 100.f),
				1 // TODO Implement health system
		);
	}
}


void EntityManager::update(float deltaTime)
{
	std::vector<Enemy>& _enemies = levelManager.levelEnemies;

	if (clock.getElapsedTime() > sf::seconds(1)){
		clock.restart();
		levelManager.changeTexture();

		//Not the best way to do this, but it works for now
		for (auto& enemy : _enemies) {
			enemy.update(deltaTime);
		}

		//Double loop... I know, I know... but it just executes every second
		for (auto& enemy : _enemies) {
			if (enemy.getPosition().x > WINDOW_WIDTH - 150.f ) {
				levelManager.changeEnemyDirection(LEFT);
			} else if (enemy.getPosition().x < 0.f) {
				levelManager.changeEnemyDirection(RIGHT);
			}
		}
	}

	if (!levelManager.isActiveLevel()) {
		levelManager.startLevel(currentLevel, enemies);
	}
	//Player
	player.update(deltaTime);

	// IS HORRIBLE, BUT IT WORKS... I'm sorry
	for (int i = 0; i < _enemies.size(); i++) {

		if (player.getShootBounds().findIntersection(_enemies[i].getBounds())) {
			player.enemyGetHit();
			levelManager.isEnemyDead[i]	= true;
			_enemies[i].setPosition(sf::Vector2f(-100.f, -100.f)); // Move enemy off-screen
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
