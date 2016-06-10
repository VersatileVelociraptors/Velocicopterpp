#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H


#include "State.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "EndGameState.h"
#include "../level/Level.h"
#include "../audio/MusicManager.h"

#include <stack>
#include <SFML/Graphics.hpp>

#define MAIN_MENU 0
#define PLAY 			1
#define END_GAME  2

class MainMenuState;
class PlayState;
class EndGameState;
class Level;

class GameStateManager
{
public:
	GameStateManager(sf::RenderWindow *window);
	~GameStateManager();

	void set(int state);
	void push(int state);
	void pop();
	State* peek();
	void render();
	void update(float dt);
	sf::RenderWindow* getWindow();
	Level* getLevel();
	MusicManager* getMusicManager();

private:
	std::stack<State*> states;
	sf::RenderWindow *window;
	MainMenuState *main_menu;
	PlayState *play;
	EndGameState* end_game;
	Level *level;
	MusicManager *musicManager;
	
};


#endif //GAMESTATEMANAGER_H