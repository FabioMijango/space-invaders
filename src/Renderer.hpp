// Renderer
#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "ResourceManager.hpp"
#include "./Entities/Player.hpp"
#include "./Entities/Enemy.hpp"


#define BACKGROUND_COLOR sf::Color(0, 43, 64)

class Renderer
{
public:
	Renderer() = delete;
	Renderer(sf::RenderWindow& window, ResourceManager& resourceManager, Player& player, std::vector<Enemy>& enemy); //TODO make a better constructor

	void draw();

private:
	sf::RenderWindow& window;
	ResourceManager& resourceManager;

	Player& player;
	std::vector<Enemy>& enemy;

	void drawBackground();
	void drawEntities();
	void drawUI();
};