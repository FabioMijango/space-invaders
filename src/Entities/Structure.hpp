#pragma once

#include "Entity.hpp"

class Structure : public Entity{
public:
    Structure(std::vector<sf::Texture>& textures, sf::Vector2f position);

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

    sf::Vector2f getPosition() const override;
    sf::FloatRect getBounds() const override;

    void changeTexture(int textureIndex);

    std::vector<sf::Texture>& getTextures();

private:
    sf::Sprite sprite;
    std::vector<sf::Texture>& textures;

    int health = 4;

};
