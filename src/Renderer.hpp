// Renderer
#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "ResourceManager.hpp"
#include "./Entities/Player.hpp"


#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define BACKGROUND_COLOR sf::Color(0, 43, 64)

class Renderer
{
public:
	Renderer() = delete;
	Renderer(sf::RenderWindow& window, ResourceManager& resourceManager, Player& player);

	void draw();

private:
	sf::RenderWindow& window;
	ResourceManager& resourceManager;

	Player& player;

	void drawBackground();
	void drawEntities();
	void drawUI();
};