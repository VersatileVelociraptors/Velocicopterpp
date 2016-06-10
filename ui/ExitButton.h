#ifndef EXITBUTTON_H
#define EXITBUTTON_H

#include "Button.h"

class ExitButton : public Button
{
public:
	ExitButton(sf::RenderWindow *window);
	ExitButton(sf::RenderWindow *window, float x, float y);
	~ExitButton();
	
};

#endif //EXITBUTTON_H