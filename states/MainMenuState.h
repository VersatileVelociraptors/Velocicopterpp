#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include <SFML/Graphics.hpp>

#include "State.h"
#include "GameStateManager.h"
#include "../ui/StartButton.h"
#include "../ui/ExitButton.h"

class GameStateManager;

class MainMenuState : public State
{
public:
	MainMenuState(GameStateManager *manager);
	~MainMenuState();
	
	void render();
	void update(float dt);
private:
	GameStateManager *manager;
	sf::RenderWindow *window;
	StartButton *startButton;
	ExitButton *exitButton;

};


#endif //MAINMENUSTATE_H