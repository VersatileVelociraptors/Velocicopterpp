#include "EndGameState.h"
#include <iostream>

EndGameState::EndGameState(GameStateManager *manager, Level *level){
	
	this->manager = manager;
	this->level = level;
	this->window = level->getWindow();

	if(!rektTexture.loadFromFile("assets/images/Rekt.png"))
		window->close();

	if(!font.loadFromFile("assets/fonts/arial.ttf"))
		window->close();

	rekt.setTexture(rektTexture);
	rekt.setPosition((int) window->getSize().x/2 - (int) rekt.getLocalBounds().width/2, 100);

	score.setFont(font);
	score.setCharacterSize(16);
	score.setPosition((int) window->getSize().x/2 - score.getGlobalBounds().height*2, 100 + (int) rekt.getLocalBounds().height);
	score.setColor(sf::Color::Green);

	restartButton = new RestartButton(window);
	restartButton->setPosition(window->getSize().x/2 - restartButton->getGlobalBounds().width/2, 150 + rekt.getGlobalBounds().height);

	exitButton = new ExitButton(window);
	exitButton->setPosition(window->getSize().x/2 - exitButton->getGlobalBounds().width/2, 250 + rekt.getGlobalBounds().height);

	mainMenuButton = new MainMenuButton(window);
	mainMenuButton->setPosition(window->getSize().x/2 - mainMenuButton->getGlobalBounds().width/2, 350 + rekt.getGlobalBounds().height);

}

EndGameState::~EndGameState(){
	delete restartButton;
	delete exitButton;
	delete mainMenuButton;
}

void EndGameState::render(){
	sprintf(scoreTextBuffer, "Score: %i", level->getKills());
	score.setString(scoreTextBuffer);
	window->clear(sf::Color::White);
	window->draw(rekt);
	window->draw(score);
	window->draw(*exitButton);
	window->draw(*restartButton);
	window->draw(*mainMenuButton);
}

void EndGameState::update(float dt){

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		float posx = sf::Mouse::getPosition(*window).x;
		float posy = sf::Mouse::getPosition(*window).y;
		restartButton->update(posx, posy);
		exitButton->update(posx, posy);
		mainMenuButton->update(posx, posy);
	}

	if(restartButton->isClicked()){
		manager->set(PLAY);
		manager->getMusicManager()->stop();
		manager->getMusicManager()->play("dosnegus");
	}

	if(exitButton->isClicked()){
		window->close();
		manager->getMusicManager()->stop();
	}

	if(mainMenuButton->isClicked()){
		manager->set(MAIN_MENU);
		manager->getMusicManager()->stop();
	}
}

void EndGameState::setLevel(Level *level){
	this->level = level;
}
