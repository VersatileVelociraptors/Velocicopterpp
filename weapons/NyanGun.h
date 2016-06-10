#ifndef NYANGUN_H
#define NYANGUN_H

#include <vector>

#include "Weapon.h"
#include "NyanProjectile.h"
#include "../level/Level.h"

class NyanGun : public Weapon
{
public:
	NyanGun(sf::RenderWindow *window, Level *level);
	~NyanGun();
	void update(float dt);
	void render();
private:
	std::vector<NyanProjectile*> projectiles;
	Level *level;
	sf::Time lastShotTime;
	sf::Clock shotClock;

};

#endif //NYANGUN_H