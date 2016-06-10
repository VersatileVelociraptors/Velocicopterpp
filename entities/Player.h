#ifndef PLAYER_H
#define PLAYER_H


#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include <vector>
#include <SFML/Graphics.hpp>

#include "Mob.h"
#include "../weapons/Weapon.h"

class Player : public Mob
{
public:
	Player();
	Player(Level *level);
	~Player();
	void move(int x, int y);
	int getDir();
	void update(float dt);
	void setLevel(Level *level);
	void init();
	Weapon* getWeapon();
	void setWeapon(Weapon *weapon);
private:
	sf::RenderWindow *window;
	std::vector<sf::Vector2i> walls;
	Weapon *weapon;
	int dir;
	//SoundManager *sounds;
	int timer;
	int box_timer;
	
};

#endif //PLAYER_H