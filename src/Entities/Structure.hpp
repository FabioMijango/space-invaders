#pragma once

#include "Entity.hpp"

class Structure : public Entity{
public:
    Structure(std::vector<sf::Texture>& textures, sf::Vector2f position);

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

    sf::FloatRect getBounds() const override;

    void changeTexture(int textureIndex);

private:
    sf::Sprite sprite;
    std::vector<sf::Texture>& textures;

    int health = 4;

};
