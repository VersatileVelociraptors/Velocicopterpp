#ifndef RESTARTBUTTON_H
#define RESTARTBUTTON_H

#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include "Button.h"

class RestartButton : public Button
{
public:
	RestartButton(sf::RenderWindow *window);
	RestartButton(sf::RenderWindow *window, float x, float y);
	~RestartButton();
	
};

#endif //RESTARTBUTTON_H