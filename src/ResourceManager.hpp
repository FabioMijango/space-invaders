#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <unordered_map>
#include <string>

#include "./Utils/Constants.hpp"


class ResourceManager {
public:
	void init();

	sf::Texture playerTexture;
	std::vector<std::vector<sf::Texture>> enemyTextures;
	std::vector<sf::Texture> structureTextures;
	std::vector<sf::Texture> sfxTextures;

	std::unordered_map<std::string, sf::Font> fonts;

private:
	void loadTextures();
	sf::Texture loadTexture(const std::string path, const sf::IntRect& rect = sf::IntRect());

	void loadFonts();
	void loadSounds();

};