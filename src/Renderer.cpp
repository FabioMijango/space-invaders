#include "Renderer.hpp"


Renderer::Renderer(sf::RenderWindow& w, ResourceManager& rm)  
   : window(w), resourceManager(rm)  
{  
}

void Renderer::draw()
{
	window.clear(BACKGROUND_COLOR);
	//drawBackground(); 
	drawEntities();
	drawUI();
}

void Renderer::drawBackground()
{
	//TODO
}

void Renderer::drawEntities()
{
}

void Renderer::drawUI()
{
}
