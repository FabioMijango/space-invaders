
#include "LevelManager.hpp"

#include <SFML/System/Exception.hpp>

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
