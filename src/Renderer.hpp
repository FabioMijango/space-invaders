// Renderer
#pragma once

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"

#define BACKGROUND_COLOR sf::Color(0, 43, 64)

class Renderer
{
public:
	Renderer() = delete;
	Renderer(sf::RenderWindow& window, ResourceManager& resourceManager);

	void draw();

private:
	sf::RenderWindow& window;
	ResourceManager& resourceManager;

	//sf::Sprite backgroundSprite;

	void drawBackground();
	void drawEntities();
	void drawUI();
};