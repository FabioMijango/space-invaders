// Resource Manager
#include "ResourceManager.hpp"

void ResourceManager::init()
{
	loadTextures();
	loadSounds();
	loadFonts();
}

void ResourceManager::loadTextures()
{
	//Enemy textures
	for (int i = 0; i < ENEMY_QUANTITY; i++) {

		//Sprite 1
		sf::Texture enemyTexture1 = loadTexture(
			std::string(RES) + std::string(ENEMY_SPRITES),
			sf::IntRect(
				{ 0, ENEMY_HEIGHT * 2 * i },
				{ ENEMY_WIDTH, ENEMY_HEIGHT }
			)
		);

		//Sprite 2
		sf::Texture enemyTexture2 = loadTexture(
			std::string(RES) + std::string(ENEMY_SPRITES),
			sf::IntRect(
				{ ENEMY_WIDTH * 2, ENEMY_HEIGHT * 2 * i },
				{ ENEMY_WIDTH, ENEMY_HEIGHT }
			)
		);

		std::vector<sf::Texture> enemyTexture = {
			enemyTexture1,
			enemyTexture2
		};
		enemyTextures.push_back(enemyTexture);
	}

	//Player texture
	playerTexture = loadTexture(
		std::string(RES) + std::string(PLAYER_SPRITE)
	);


	//Structure textures
	for (int i = 0; i < STRUCTURE_QUANTITY; i++) {
		sf::Texture structureTexture = loadTexture(
			std::string(RES) + std::string(STRUCTURE_SPRITES),
			sf::IntRect(
				{ 0, STRUCTURE_HEIGHT * i },
				{ STRUCTURE_WIDTH, STRUCTURE_HEIGHT })
			);
		structureTextures.push_back(structureTexture);
	}


	// SFX textures
	//TODO

}

void ResourceManager::loadFonts()
{
	fonts.emplace(FONT_REGULAR, sf::Font(std::string(RES) + std::string(FONT_REGULAR) + std::string(".ttf")));
	fonts.emplace(FONT_BOLD, sf::Font(std::string(RES) + std::string(FONT_BOLD) + std::string(".ttf")));
}

void ResourceManager::loadSounds()
{
	//TODO
}

sf::Texture ResourceManager::loadTexture(const std::string path, const sf::IntRect& rect)
{
	sf::Texture texture;
	if (!texture.loadFromFile(path,false, rect)) {
		throw std::runtime_error("Failed to load texture from " + path);
	}
	return texture;
}