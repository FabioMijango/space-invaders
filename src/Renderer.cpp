#pragma once

#include "Renderer.hpp"



Renderer::Renderer(sf::RenderWindow& w, ResourceManager& rm, Player& p, std::vector<Enemy>& enemy, std::vector<bool>& isEnemyDead, std::vector<Structure>& structures)
   : window(w), resourceManager(rm), player(p), enemy(enemy), isEnemyDead(isEnemyDead), structures(structures)
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

	for (int i = 0; i < enemy.size(); i++) {
		if (isEnemyDead[i]) {
			continue; // Skip dead enemies
		}
		enemy[i].render(window);
	}

	for (auto& structure : structures) {
		structure.render(window);
	}
}

void Renderer::drawUI()
{
}
