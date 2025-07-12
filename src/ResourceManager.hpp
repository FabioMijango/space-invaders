#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <unordered_map>
#include <string>

// Resource paths
#define RES "res/"

#define ENEMY_SPRITES "enemy_sprites.png"
#define PLAYER_SPRITE "player_sprite.png"
#define STRUCTURE_SPRITES "structure_sprites.png"
#define SFX_SPRITES "sfx_sprites.png"

#define FONT_REGULAR "PixeloidSans"
#define FONT_BOLD "PixeloidSansBold"

// Enemy
#define ENEMY_QUANTITY 5
#define ENEMY_HEIGHT 8
#define ENEMY_WIDTH 11
// Structure
#define STRUCTURE_QUANTITY 4
#define STRUCTURE_HEIGHT 12
#define STRUCTURE_WIDTH 13 * 2



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