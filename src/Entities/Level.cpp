
#include "./Level.hpp"

Level::Level(const std::pair<int, int> levelSize, const int enemySpeed, const int structureHealth)
    : levelSize(levelSize), enemySpeed(enemySpeed), structureHealth(structureHealth)
{
    levelNumber = levelCounter++;
}

void Level::load() {
    return;
}

int Level::getLvlNumber() const {
    return levelNumber;
}

std::pair<int, int> Level::getLvlSize() const {
    return levelSize;
}

int Level::getEnemySpeed() const {
    return enemySpeed;
}

int Level::getStructureHealth() const {
    return structureHealth;
}
