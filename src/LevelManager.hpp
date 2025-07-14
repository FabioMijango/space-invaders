#pragma once

#include <vector>

#include "./Entities/Enemy.hpp"
#include "./Entities/Level.hpp"

class LevelManager {
public:
    LevelManager();
    Level& getLevel(int index);

    void startLevel(int index, const std::vector<Enemy>& enemiesVector);

    bool isActiveLevel();
    std::vector<Enemy> levelEnemies;

private:
    std::vector<Level> levels;
    bool activeLevel = false;
};