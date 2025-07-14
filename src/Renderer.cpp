#pragma once

#include "Renderer.hpp"



Renderer::Renderer(sf::RenderWindow& w, ResourceManager& rm, Player& p, std::vector<Enemy>& enemy)
   : window(w), resourceManager(rm), player(p), enemy(enemy)
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

	for (Enemy e : enemy) {
		e.render(window);
	}
}

void Renderer::drawUI()
{
}
