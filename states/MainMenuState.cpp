#include "MainMenuState.h"
#include "PlayState.h"
#include <iostream>

MainMenuState::MainMenuState(GameStateManager *manager){
	this->manager = manager;
	this->window = manager->getWindow();
	startButton = new StartButton(this->window, 100, 100);
	exitButton = new ExitButton(this->window, 100, 200);
}

MainMenuState::~MainMenuState(){
	delete startButton;
	delete exitButton;
}

void MainMenuState::render(){
	window->clear(sf::Color::White);
	window->draw(*startButton);
	window->draw(*exitButton);
}

void MainMenuState::update(float dt){
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		float posx = sf::Mouse::getPosition(*window).x;
		float posy = sf::Mouse::getPosition(*window).y;
		startButton->update(posx, posy);
		exitButton->update(posx, posy);
	}

	if(startButton->isClicked()){
		manager->set(PLAY);
		manager->getMusicManager()->loop("dosnegus");
		manager->getMusicManager()->play("dosnegus");
		return;
	}

	if(exitButton->isClicked()){
		window->close();
	}
}