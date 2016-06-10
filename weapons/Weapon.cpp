#include "Weapon.h"

Weapon::Weapon(){

}

Weapon::Weapon(sf::RenderWindow *window){
	this->window = window;
}

Weapon::~Weapon(){

}

int Weapon::getAmmo(){
	return ammo;
}

void Weapon::setAmmo(int ammo){
	this->ammo = ammo;
}

char* Weapon::getName(){
	return name;
}

void Weapon::setName(char* name){
	this->name = name;
}

void Weapon::setPlayerTexture(sf::Texture texture){
	this->playerTexture = texture;
	playerSprite.setTexture(playerTexture);
}

sf::Texture* Weapon::getPlayerTexture(){
	return &this->playerTexture;
}

void Weapon::setWeaponTexture(sf::Texture texture){
	this->weaponTexture = texture;
	weaponSprite.setTexture(weaponTexture);
}

sf::Texture* Weapon::getWeaponTexture(){
	return &this->weaponTexture;
}