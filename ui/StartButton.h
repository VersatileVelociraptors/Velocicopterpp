#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include "Button.h"

class StartButton : public Button
{
public:
	StartButton(sf::RenderWindow *window, float x, float y);
	~StartButton();
	
};

#endif //STARTBUTTON_H