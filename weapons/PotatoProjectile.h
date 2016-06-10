#ifndef POTATOPROJECTILE_H
#define POTATOPROJECTILE_H

#include "Projectile.h"

class PotatoProjectile : public Projectile
{
public:
	PotatoProjectile();
	PotatoProjectile(Level *level);
	~PotatoProjectile();
private:
	sf::RenderWindow *window;
	
};

#endif //POTATOPROJECTILE_H