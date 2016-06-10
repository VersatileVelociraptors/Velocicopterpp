#ifndef WEAPON_H
#define WEAPON_H

#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include <SFML/Graphics.hpp>

class Weapon
{
public:
	Weapon();
	Weapon(sf::RenderWindow *window);
	virtual ~Weapon();

	int getAmmo();
	void setAmmo(int ammo);
	char* getName();
	void setName(char* name);
	void setPlayerTexture(sf::Texture texture);
	sf::Texture *getPlayerTexture();
	void setWeaponTexture(sf::Texture texture);
	sf::Texture *getWeaponTexture();
	virtual void update(float dt) = 0;
	virtual void render() = 0;
protected:
	sf::RenderWindow *window;
	int ammo;
	int rateOfFire;
	sf::Texture weaponTexture;
	sf::Sprite weaponSprite;
	char* name;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	
};

#endif //WEAPON_H