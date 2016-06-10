#include "BananaProjectile.h"
#include <iostream>

BananaProjectile::BananaProjectile(){

}

BananaProjectile::BananaProjectile(Level *level){
	this->level = level;
	this->window = level->getWindow();

	if(!this->texture.loadFromFile("assets/images/banana.png")){
		window->close();
	}

	this->setTexture(this->texture);
	this->setPosition((int) window->getSize().x/2, (int) window->getSize().y/2);

	sf::IntRect texture_rect = this->getTextureRect();
	this->setOrigin(texture_rect.width/2, texture_rect.height/2);
	this->setScale(1.0f, -1.0f);
	
	this->speed = 90;
	this->range = 250;
	this->damage = 45;
}

BananaProjectile::~BananaProjectile(){

}