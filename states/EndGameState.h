#ifndef ENDGAMESTATE_H
#define ENDGAMESTATE_H

#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include "GameStateManager.h"
#include "../ui/ExitButton.h"
#include "../ui/RestartButton.h"
#include "../ui/MainMenuButton.h"
#include "../level/Level.h"

class GameStateManager;

class EndGameState : public State
{
public:
	EndGameState(GameStateManager *manager, Level *level);
	~EndGameState();
	void render();
	void update(float dt);
	void setLevel(Level *level);

private:
	sf::Sprite rekt;
	sf::Texture rektTexture;
	//MusicManager *music;
	sf::Font font;
	sf::Text score;
	char scoreTextBuffer[20];
	sf::Text scoreText;
	Level *level;
	GameStateManager *manager;
	sf::RenderWindow *window;

	RestartButton *restartButton;
	ExitButton *exitButton;
	MainMenuButton *mainMenuButton;
};

#endif //ENDGAMESTATE_H