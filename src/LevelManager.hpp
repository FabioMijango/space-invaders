#pragma once

#include <vector>

#include "./Entities/Enemy.hpp"
#include "./Entities/Level.hpp"

class LevelManager {
public:
    LevelManager();
    Level& getLevel(int index);

    void startLevel(int index, const std::vector<Enemy>& enemiesVector);

    bool isActiveLevel() const;
    std::vector<Enemy> levelEnemies;

    std::vector<bool> isEnemyDead;

    void changeTexture();
    void changeEnemyDirection(Direction newDir);

private:
    std::vector<Level> levels;
    bool activeLevel = false;

    short textureCounter = 0;
};