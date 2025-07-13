#pragma once

#include "Renderer.hpp"


Renderer::Renderer(sf::RenderWindow& w, ResourceManager& rm, Player& p)  
   : window(w), resourceManager(rm), player(p)
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
