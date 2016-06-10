#include "BananaGun.h"
#include <iostream>

BananaGun::BananaGun(sf::RenderWindow *window, Level *level){
	this->ammo = 80;
	this->rateOfFire = 9;

	this->window = window;
	this->level = level;

	if(!this->weaponTexture.loadFromFile("assets/images/bananagun.png"))
		window->close();

	this->name = (char *) "Banana Gun";
	if(!this->playerTexture.loadFromFile("assets/images/bananaplayer.png"))
		window->close();

	weaponSprite.setTexture(weaponTexture);
	playerSprite.setTexture(playerTexture);

}

BananaGun::~BananaGun(){
	for(unsigned int i = 0; i < projectiles.size(); ++i){
		delete projectiles.at(i);
	}
}

void BananaGun::update(float dt){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && ammo > 0 && shotClock.getElapsedTime().asMilliseconds() - lastShotTime.asMilliseconds() >= 1000/rateOfFire){
		ammo--;
		projectiles.push_back(new BananaProjectile(level));
		projectiles.back()->setDir(level->getPlayer()->getDir());
		lastShotTime = shotClock.getElapsedTime();
		level->getSoundManager()->play("potatoShot");
	}

	for(unsigned int i = 0; i < projectiles.size(); i++){
		if(projectiles.at(i)->isAlive())
			projectiles.at(i)->update(dt);
	}
}

void BananaGun::render(){

	for(unsigned int i = 0; i < projectiles.size(); i++){
		if(projectiles.at(i)->isAlive()){
			window->draw(*projectiles.at(i));
		}
	}

}