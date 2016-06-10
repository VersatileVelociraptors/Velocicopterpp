#ifndef NYANPROJECTILE_H
#define NYANPROJECTILE_H

#include "Projectile.h"

class NyanProjectile : public Projectile
{
public:
	NyanProjectile();
	NyanProjectile(Level *level);
	~NyanProjectile();
private:
	sf::RenderWindow *window;
	
};

#endif //NYANPROJECTILE_H