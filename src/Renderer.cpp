#pragma once

#include "Renderer.hpp"

#include <iostream>


Renderer::Renderer(sf::RenderWindow& w, ResourceManager& rm, Player& p, std::vector<Enemy>& enemy)
   : window(w), resourceManager(rm), player(p), enemy(enemy)
{
	std::cout << enemy.size() << std::endl;
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

	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i].render(window);
	}
}

void Renderer::drawUI()
{
}
