#pragma once

#include <vector>

#include "./Entities/Level.hpp"

class LevelManager {
public:
    LevelManager();
    Level& getLevel(int index);
    // void addLevel(const Level& level);

private:
    std::vector<Level> levels;
};