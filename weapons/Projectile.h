#ifndef PROJECTILE_H
#define PROJECTILE_H

#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include <vector>

#include "../entities/Entity.h"
#include "../entities/Mob.h"
#include "../level/Level.h"
#include "../entities/Velociraptor.h"

class Projectile : public Entity
{
public:
	Projectile();
	Projectile(sf::RenderWindow *window);
	Projectile(sf::Texture image, Level *level, sf::Vector2i position, int bulletSpeed, int damage, int dir, int range);
	~Projectile();

	void setDir(int dir);
	void update(float dt);
	std::vector<Velociraptor*> victims;
private:
	float distanceTravelled;
	int dir;
	sf::RenderWindow *window;
protected:
	int range;
	int damage;
	
};

#endif //PROJECTILE_H