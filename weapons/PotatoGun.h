#ifndef POTATOGUN_H
#define POTATOGUN_H

#include <vector>

#include "Weapon.h"
#include "PotatoProjectile.h"
#include "../level/Level.h"

class PotatoGun : public Weapon
{
public:
	PotatoGun(sf::RenderWindow *window, Level *level);
	~PotatoGun();
	void update(float dt);
	void render();
private:
	std::vector<PotatoProjectile*> projectiles;
	Level *level;
	sf::Time lastShotTime;
	sf::Clock shotClock;

};

#endif //POTATOGUN_H