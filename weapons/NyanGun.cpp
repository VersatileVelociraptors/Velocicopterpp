#include "NyanGun.h"
#include <iostream>

NyanGun::NyanGun(sf::RenderWindow *window, Level *level){
	this->ammo = 10;
	this->rateOfFire = 1;

	this->window = window;
	this->level = level;

	if(!this->weaponTexture.loadFromFile("assets/images/nyancat.png"))
		window->close();

	this->name = (char *) "Nyan Gun";
	if(!this->playerTexture.loadFromFile("assets/images/nyanplayer.png"))
		window->close();

	weaponSprite.setTexture(weaponTexture);
	playerSprite.setTexture(playerTexture);

}

NyanGun::~NyanGun(){
	for(unsigned int i = 0; i < projectiles.size(); ++i){
		delete projectiles.at(i);
	}
}

void NyanGun::update(float dt){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && ammo > 0 && shotClock.getElapsedTime().asMilliseconds() - lastShotTime.asMilliseconds() >= 1000/rateOfFire){
		ammo--;
		projectiles.push_back(new NyanProjectile(level));
		projectiles.back()->setDir(level->getPlayer()->getDir());
		lastShotTime = shotClock.getElapsedTime();
		level->getSoundManager()->play("potatoShot");
	}

	for(unsigned int i = 0; i < projectiles.size(); i++){
		if(projectiles.at(i)->isAlive())
			projectiles.at(i)->update(dt);
	}
}

void NyanGun::render(){

	for(unsigned int i = 0; i < projectiles.size(); i++){
		if(projectiles.at(i)->isAlive()){
			window->draw(*projectiles.at(i));
		}
	}

}