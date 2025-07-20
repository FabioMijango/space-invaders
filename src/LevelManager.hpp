#pragma once

#include <vector>

#include "./Entities/Enemy.hpp"
#include "./Entities/Level.hpp"
#include "Entities/Structure.hpp"

class LevelManager {
public:
    LevelManager();
    Level& getLevel(int index);

    void startLevel(int index, const std::vector<Enemy> &enemiesVector, std::vector<sf::Texture> &structuresVector);

    bool isActiveLevel() const;
    std::vector<Enemy> levelEnemies;
    std::vector<Structure> structures;

    std::vector<bool> isEnemyDead;

    void changeTexture();
    void changeEnemyDirection(Direction newDir);

private:
    std::vector<Level> levels;
    bool activeLevel = false;

    short textureCounter = 0;
};
