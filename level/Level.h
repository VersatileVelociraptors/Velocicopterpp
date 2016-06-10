#ifndef LEVEL_H
#define LEVEL_H

#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include <vector>
#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "../entities/Player.h"
#include "../entities/Velociraptor.h"
#include "../audio/SoundManager.h"

class Player;
class Velociraptor;

class Level
{
public:
	Level(char* path, sf::RenderWindow *window);
	~Level();
	int getXOffset();
	int getYOffset();
	void setXOffset(int offset);
	void setYOffset(int offset);
	void loadLevel(char* path);
	void update(float dt);
	void render();
	bool inSolid(int x, int y);
	int tileType(int x, int y);
	std::vector<sf::Vector2i> getWalls();
	sf::Vector2i getTileCoordinates(int index);
	void spawnEnemy();
	int getWidthInPixels();
	int getHeightInPixels();
	int getWidthInTiles();
	int getHeightInTiles();
	Player* getPlayer();
	void setPlayer(Player *player);
	std::vector<Velociraptor*> getEnemies();
	int getKills();
	void setKills(int kills);
	void close();
	sf::RenderWindow* getWindow();
	SoundManager* getSoundManager();

	static const int SPAWN_DELAY = 5000;

private:
	sf::RenderWindow *window;
	int width, height;
	int *tileMap;
	int xOffset, yOffset;
	Tile *tiles;
	Player *player;
	int kills;
	sf::Clock clock;
	sf::Time lastSpawnTime;
	std::vector<Velociraptor*> enemies;
	SoundManager *soundManager;

	
};

#endif //LEVEL_H