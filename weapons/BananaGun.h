#ifndef BANANAGUN_H
#define BANANAGUN_H

#include <vector>

#include "Weapon.h"
#include "BananaProjectile.h"
#include "../level/Level.h"

class BananaGun : public Weapon
{
public:
	BananaGun(sf::RenderWindow *window, Level *level);
	~BananaGun();
	void update(float dt);
	void render();
private:
	std::vector<BananaProjectile*> projectiles;
	Level *level;
	sf::Time lastShotTime;
	sf::Clock shotClock;

};

#endif //BANANAGUN_H