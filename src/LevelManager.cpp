
#include "LevelManager.hpp"

#include "./Utils/Constants.hpp"

LevelManager::LevelManager() {
    levels.clear();
    //Set default levels
    levels.emplace_back(DEFAULT_LEVEL_SIZE, DEFAULT_ENEMY_SPEED, DEFAULT_STRUCTURE_HEALTH);
    levels.emplace_back(DEFAULT_LEVEL_SIZE, 150, DEFAULT_STRUCTURE_HEALTH);
    levels.emplace_back(std::pair<int, int>(5, 3), 200, DEFAULT_STRUCTURE_HEALTH);
}

Level& LevelManager::getLevel(const int index) {
    return levels[index];

}

void LevelManager::startLevel(int index, const std::vector<Enemy> &enemiesVector, std::vector<sf::Texture> &structuresVector) {
    if (activeLevel)
        return;
    //TODO Assuming index is valid, fix later

    const Level& level = levels[index];

    int totalEnemies = level.getLvlSize().first * level.getLvlSize().second;

    levelEnemies.clear();

    for (int i = 0; i < level.getLvlSize().first; i++) {
        for (int j = 0; j < level.getLvlSize().second; j++) {
            levelEnemies.emplace_back(
                enemiesVector[j].getTextures(),
                sf::Vector2f(
                    (i * ENEMY_WIDTH) + (i * ENEMY_SPACING.x) * 7.f + 50.f,
                    (j * ENEMY_HEIGHT) + (j * ENEMY_SPACING.y) * 7.f + 50.f),
                    1
            );
        }
    }
    isEnemyDead.clear();
    isEnemyDead.resize(levelEnemies.size(), false);
    activeLevel = true;


    structures.clear();
    for ( int i = 0; i < STRUCTURE_QUANTITY; i++) {
        structures.emplace_back(
            structuresVector,
            sf::Vector2f( WINDOW_WIDTH / 3.f * i, WINDOW_HEIGHT -250.f)
            );
    }

}

void LevelManager::changeEnemyDirection(const Direction newDir) {
    for (auto& enemy : levelEnemies) {
        enemy.changeDirection(newDir);
    }
}

void LevelManager::changeTexture() {
    for (int i = 0; i < levelEnemies.size(); i++) {
        levelEnemies[i].changeTexture(textureCounter);
    }
    textureCounter = (textureCounter + 1) % 2;
}

bool LevelManager::isActiveLevel() const {
    return activeLevel;
}
