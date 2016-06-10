#ifndef VELOCIRAPTOR_H
#define VELOCIRAPTOR_H


#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include "Mob.h"
#include "../level/Level.h"

class Velociraptor : public Mob
{
public:
	Velociraptor(Level *level, int x, int y);
	~Velociraptor();

	void update(float dt);
	void setBulletHitTime(sf::Time bulletHitTime);
	sf::Time getBulletHitTime();
		
private:
	const int kHitDelay = 300;
	const int kDamage = 5;
	sf::RenderWindow *window;

	double angle;
	sf::Clock clock;
	sf::Time lastHitTime;
	sf::Time bulletHitTime;
	int x, y;

};

#endif //VELOCIRAPTOR_H