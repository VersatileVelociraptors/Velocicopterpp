#include <iostream>
#include <cmath>
#include <vector>

#include "Projectile.h"

using std::vector;

Projectile::Projectile(){

}

Projectile::Projectile(sf::RenderWindow *window){
	this->window = window;
	level->getSoundManager()->play("potatoShot");
}

Projectile::Projectile(sf::Texture image, Level *level, sf::Vector2i position, int bulletSpeed, int damage, int dir, int range){
	this->texture = image;
	this->level = level;
	this->speed = bulletSpeed;
	this->range = range;
	this->window = level->getWindow();
}

Projectile::~Projectile(){

}

void Projectile::setDir(int dir){
	this->dir = dir;
}

void Projectile::update(float dt){
	vector<Velociraptor*> enemies = level->getEnemies();
	for (unsigned int i = 0; i < enemies.size(); ++i){
		if(enemies.at(i)->isAlive() && enemies.at(i)->getGlobalBounds().intersects(this->getGlobalBounds())
			&& std::find(victims.begin(), victims.end(), enemies.at(i)) == victims.end()) {
				enemies.at(i)->takeDamage(damage);
				victims.push_back(enemies.at(i));
		}
	}

	setRotation(getRotation() - 10);
	if(distanceTravelled < range){
		switch(dir){
			case 0:
				move(0, -speed);
				distanceTravelled += speed;
				break;
			case 1:
				move(speed, -speed);
				distanceTravelled += sqrt(2*(speed*speed));
				break;
			case 2:
				move(speed, 0);
				distanceTravelled += speed;
				break;
			case 3:
				move(speed, speed);
				distanceTravelled += sqrt(2*(speed*speed));
				break;
			case 4:
				move(0, speed);
				distanceTravelled += speed;
				break;
			case 5:
				move(-speed, speed);
				distanceTravelled += sqrt(2*(speed*speed));
				break;
			case 6:
				move(-speed, 0);
				distanceTravelled += speed;
				break;
			case 7:
				move(-speed, -speed);
				distanceTravelled += sqrt(2*(speed*speed));
				break;
		}
	}else{
		setAlive(false);
	}

}
