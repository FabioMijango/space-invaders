#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "EntityManager.hpp"
#include "Renderer.hpp"


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Space Invaders", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

	ResourceManager resourceManager;

	EntityManager entityManager(resourceManager);

    Renderer renderer(window, resourceManager, entityManager.getPlayer(), entityManager.getLevelEnemies());

    sf::Clock clock;
    float deltaTime = clock.restart().asSeconds();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scan::Escape)
                {
                    window.close();
                }
            }
        
        }



		deltaTime = clock.restart().asSeconds();

		entityManager.update(deltaTime);

		renderer.draw();

    }
}
