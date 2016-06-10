#include "PotatoGun.h"
#include <iostream>

PotatoGun::PotatoGun(sf::RenderWindow *window, Level *level){
	this->ammo = 30;
	this->rateOfFire = 3;

	this->window = window;
	this->level = level;

	if(!this->weaponTexture.loadFromFile("assets/images/potatogun.png"))
		window->close();

	this->name = (char *) "Mr. Potato Gun";
	if(!this->playerTexture.loadFromFile("assets/images/potatoplayer.png"))
		window->close();

	weaponSprite.setTexture(weaponTexture);
	playerSprite.setTexture(playerTexture);

}

PotatoGun::~PotatoGun(){
	for(unsigned int i = 0; i < projectiles.size(); ++i){
		delete projectiles.at(i);
	}
}

void PotatoGun::update(float dt){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && ammo > 0 && shotClock.getElapsedTime().asMilliseconds() - lastShotTime.asMilliseconds() >= 1000/rateOfFire){
		ammo--;
		projectiles.push_back(new PotatoProjectile(level));
		projectiles.back()->setDir(level->getPlayer()->getDir());
		lastShotTime = shotClock.getElapsedTime();
		level->getSoundManager()->play("potatoShot");
	}

	for(unsigned int i = 0; i < projectiles.size(); i++){
		if(projectiles.at(i)->isAlive())
			projectiles.at(i)->update(dt);
	}
}

void PotatoGun::render(){

	for(unsigned int i = 0; i < projectiles.size(); i++){
		if(projectiles.at(i)->isAlive()){
			window->draw(*projectiles.at(i));
		}
	}

}