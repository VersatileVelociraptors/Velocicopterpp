#include "GameStateManager.h"
#include <iostream>

GameStateManager::GameStateManager(sf::RenderWindow *window){
	this->window = window;
	
	this->musicManager = new MusicManager(this->window);
	musicManager->addAllMusicInAssets();

	main_menu = new MainMenuState(this);
	play = new PlayState(this);
	this->level = play->getLevel();
	end_game = new EndGameState(this, play->getLevel());
}

GameStateManager::~GameStateManager(){
	delete peek();
	delete musicManager;
}

void GameStateManager::set(int state){
	push(state);
}

void GameStateManager::push(int state){
	if(state == MAIN_MENU){
		delete main_menu;
		main_menu = new MainMenuState(this);
		states.push(main_menu);
	}
	else if(state == PLAY){
		delete play;
		play = new PlayState(this);
		states.push(play);
	}
	else if(state == END_GAME){
		delete end_game;
		end_game = new EndGameState(this, play->getLevel());
		states.push(end_game);
	}
}

void GameStateManager::pop(){
	states.pop();
}

State* GameStateManager::peek(){
	return states.top();
}

void GameStateManager::render(){
	peek()->render();
}

void GameStateManager::update(float dt){
	peek()->update(dt);
}

sf::RenderWindow* GameStateManager::getWindow(){
	return window;
}

Level* GameStateManager::getLevel(){
	return level;
}

MusicManager* GameStateManager::getMusicManager(){
	return this->musicManager;
}
