#ifndef BANANAPROJECTILE_H
#define BANANAPROJECTILE_H

#include "Projectile.h"

class BananaProjectile : public Projectile
{
public:
	BananaProjectile();
	BananaProjectile(Level *level);
	~BananaProjectile();
private:
	sf::RenderWindow *window;
	
};

#endif //BANANAPROJECTILE_H