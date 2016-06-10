#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H


#ifndef SFML_STATIC
#define SFML_STATIC
#endif

#include "AudioManager.h"
#include <vector>
#include <string>

class MusicManager : public AudioManager 
{
public:
	MusicManager(sf::RenderWindow *window);
	~MusicManager();

	void addAllMusicInAssets();
	void addMusic(std::string name, sf::Music *music);
	void addMusic(std::string name, char* path);
	void play(std::string name);
	void loop(std::string name);
	void stop(std::string name);
	void stop();
	std::vector<std::string> getMusicsNames();
	std::vector<sf::Music*> getMusics();
	
};

#endif //MUSICMANAGER_H