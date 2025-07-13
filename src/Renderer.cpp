#pragma once

#include "Renderer.hpp"


Renderer::Renderer(sf::RenderWindow& w, ResourceManager& rm)  
   : window(w), resourceManager(rm), player(Player(resourceManager.playerTexture, sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 100)))
{
}

void Renderer::draw()
{
	window.clear(BACKGROUND_COLOR);
	//drawBackground(); 
	drawEntities();
	drawUI();
	window.display();
}

void Renderer::drawBackground()
{
}

void Renderer::drawEntities()
{
	player.render(window);
}

void Renderer::drawUI()
{
}
