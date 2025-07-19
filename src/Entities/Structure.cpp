
#include "Structure.hpp"

Structure::Structure(std::vector<sf::Texture> &textures, sf::Vector2f position)
    : sprite(sf::Sprite(textures[0])),
    textures( textures)
{
    sprite.setPosition(position);
    sprite.setScale({7.f, 7.f});

    std::reverse(textures.begin(), textures.end());
}

void Structure::update(float deltaTime) {
    // Required?
}

void Structure::render(sf::RenderWindow &window) {
    window.draw(sprite);
}

sf::FloatRect Structure::getBounds() const {
    return sprite.getGlobalBounds();
}

void Structure::changeTexture(int textureIndex) {
    sprite.setTexture(textures[textureIndex]);
}
