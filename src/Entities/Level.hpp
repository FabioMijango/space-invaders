#pragma once

#include <utility>

#define DEFAULT_LEVEL_SIZE std::make_pair(11, 5)
#define DEFAULT_STRUCTURE_HEALTH 3
#define DEFAULT_ENEMY_SPEED 100

class Level {
public:
    Level(std::pair<int, int> levelSize, int enemySpeed, int structureHealth);

    void load();
    // void unload(); // TODO Required?

    int getLvlNumber() const;
    std::pair<int, int> getLvlSize() const;
    int getEnemySpeed() const;
    int getStructureHealth() const;

private:
    static int levelCounter;
    int levelNumber;

    std::pair<int, int> levelSize;
    int enemySpeed;

    int structureHealth;

};
