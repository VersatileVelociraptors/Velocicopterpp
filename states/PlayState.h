#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include "GameStateManager.h"
#include "../level/Level.h"
#include "../entities/Player.h"

class GameStateManager;

class PlayState : public State
{
public:
	PlayState(GameStateManager *manager);
	~PlayState();
	void render();
	void update(float dt);
	Level* getLevel();
private:
	Level *level;
	GameStateManager *manager;
	sf::RenderWindow *window;
	Player *player;
	sf::Texture overlayTexture;
	sf::Sprite overlay;
	sf::Font font;
	char overlayTextBuffer[200];
	sf::Text overlayText;
	bool fourtwenty;
};

#endif //PLAYSTATE_H