#ifndef MAINMENUBUTTON_H
#define MAINMENUBUTTON_H


#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include "Button.h"

class MainMenuButton : public Button
{
public:
	MainMenuButton(sf::RenderWindow *window);
	MainMenuButton(sf::RenderWindow *window, float x, float y);
	~MainMenuButton();
	
};

#endif //MAINMENUBUTTON_H