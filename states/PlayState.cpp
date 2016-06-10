#include "PlayState.h"
#include <iostream>
#include <SFML/Graphics.hpp>

PlayState::PlayState(GameStateManager *manager){
	this->manager = manager;
	this->window = manager->getWindow();

	level = new Level((char *)"assets/levels/level02.txt", window);

	player = new Player(level);
	player->setPosition((int) window->getSize().x/2, (int) window->getSize().y/2);
	level->setPlayer(player);

	if(!overlayTexture.loadFromFile("assets/images/overlay.png"))
		window->close();

	if (!font.loadFromFile("assets/fonts/arial.ttf"))
		window->close();

	overlay.setTexture(overlayTexture);
	overlayText.setFont(font);
	overlayText.setCharacterSize(16);
	overlayText.setColor(sf::Color::White);
}

PlayState::~PlayState(){
	delete player;
	delete level;
}

void PlayState::render(){
	window->clear(sf::Color(101, 156, 239, 255));
	level->render();
	window->draw(*player);
	player->getWeapon()->render();
	window->draw(overlay);
	sf::Texture *weaponTexture = player->getWeapon()->getWeaponTexture();
	sf::Sprite weaponSprite(*weaponTexture);
	float weaponY = (int) window->getSize().y - (int) weaponTexture->getSize().y;
	weaponSprite.setPosition(0, weaponY);
	window->draw(weaponSprite);
	sprintf(overlayTextBuffer, "Points: %i\nHealth: %i\nAmmo: %i\nWeapon: %s",
					 (int) level->getKills(), (int) player->getHealth(), (int) player->getWeapon()->getAmmo(), player->getWeapon()->getName());
	overlayText.setPosition(0, weaponY - 90);
	overlayText.setString(overlayTextBuffer);
	window->draw(overlayText);
}

void PlayState::update(float dt){
	level->update(dt);

	if(level->tileType(player->getPosition().x, player->getPosition().y) == SNOOP_TILE && !fourtwenty){
		manager->getMusicManager()->stop();
		manager->getMusicManager()->play("420");
		fourtwenty = true;
	}

	if(!level->getPlayer()->isAlive()){
		manager->getMusicManager()->stop();
		manager->getMusicManager()->loop("endscreen");
		manager->getMusicManager()->play("endscreen");
		manager->set(END_GAME);
		return;
	}
}

Level* PlayState::getLevel(){
	return this->level;
}