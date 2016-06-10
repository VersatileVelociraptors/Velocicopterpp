#include "Mob.h"
#include "../level/Level.h"

Mob::Mob()
:health(100){

}

Mob::~Mob(){

}

void Mob::takeDamage(double damage){
	health -= damage;
	if (health <= 0){
		setAlive(false);
	}
}

double Mob::getHealth(){
	return health;
}

void Mob::setHealth(double health){
	this->health = health;
}

void Mob::update(float dt){
	
}
