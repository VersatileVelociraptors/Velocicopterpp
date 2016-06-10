#include "Velociraptor.h"
#define _USE_MATH_DEFINES //For older systems
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Velociraptor::Velociraptor(Level *level, int x, int y){
	this->level = level;
	this->window = level->getWindow();

	if(!this->texture.loadFromFile("assets/images/dino.png"))
		window->close();

	this->setTexture(texture);
	this->x = x;
	this->y = y;

	this->setPosition(this->x + level->getXOffset(), this->y + level->getYOffset());
	speed /= 2;

	sf::IntRect texture_rect = this->getTextureRect();
	this->setOrigin(texture_rect.width/2, texture_rect.height/2);

}

Velociraptor::~Velociraptor(){

}

void Velociraptor::update(float dt){

	sf::Vector2i player(level->getPlayer()->getPosition());
	sf::Vector2i pos(this->getPosition());

	angle = atan2(player.y - pos.y, player.x - pos.x);
	setRotation((float) angle*180/(M_PI));
	x+=speed*cos(angle);
	y+=speed*sin(angle);
	this->setPosition(x + level->getXOffset(), y + level->getYOffset());

	if(level->getPlayer()->getGlobalBounds().intersects(this->getGlobalBounds()) && clock.getElapsedTime().asMilliseconds() - lastHitTime.asMilliseconds() >= kHitDelay){
		level->getPlayer()->takeDamage(kDamage);
		lastHitTime = clock.getElapsedTime();
	}

}

void Velociraptor::setBulletHitTime(sf::Time bulletHitTime){
	this->bulletHitTime = bulletHitTime;
}

sf::Time Velociraptor::getBulletHitTime(){
	return bulletHitTime;
}