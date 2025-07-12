#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Space Invaders");
    window.setFramerateLimit(60);



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

            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                if (resized->size.x < 720) {
                    window.setSize(sf::Vector2u(720u, resized->size.y));
                }
                if (resized->size.y < 720) {
					window.setSize(sf::Vector2u(resized->size.y, 720u));
                }
                sf::FloatRect visibleArea(sf::Vector2f(0, 0), sf::Vector2f(resized->size.x, resized->size.y));
                window.setView(sf::View(visibleArea));
            }
        
        }

        window.clear();
        window.display();
    }
}
