#ifndef MOB_H
#define MOB_H

#include "Entity.h"

class Mob : public Entity
{
public:
	Mob();
	~Mob();
	void takeDamage(double damage);
	double getHealth();
	void update(float dt);
protected:
	void setHealth(double health);
private:
	double health;
	
};

#endif //MOB_H