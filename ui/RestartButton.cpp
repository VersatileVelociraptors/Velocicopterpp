#include "RestartButton.h"

RestartButton::RestartButton(sf::RenderWindow *window){
	this->window = window;
	
	if(!this->buttonTexture.loadFromFile("assets/images/playagain.png"))
		window->close();
	this->setTexture(buttonTexture);
	clicked = false;
}

RestartButton::RestartButton(sf::RenderWindow *window, float x, float y){

	if(!this->buttonTexture.loadFromFile("assets/images/playagain.png"))
		window->close();

	this->x = x;
	this->y = y;
	this->window = window;
	this->setTexture(buttonTexture);
	this->setPosition(x,y);
	clicked = false;
}

RestartButton::~RestartButton(){

}