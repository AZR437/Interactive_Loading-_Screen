#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "../../Misc/SoundTags.h"
#include "../../Misc/StringUtils.h"
#include "unordered_map"
#include "vector"
#include "string"
#include "filesystem"
#include "fstream"
namespace managers
{
	using namespace misc;
	class SoundManager
	{
	private:
		std::unordered_map<SoundTags, sf::Sound*> soundMap;
		std::vector<sf::Sound*> soundList;

	public:
		static SoundManager* getInstance();
		sf::Sound* getSound(SoundTags tag);
		void loadLoadingScreenSFX();
		void loadMusic();
		void loadSound(SoundTags tag, std::string path);
		void addSound(SoundTags tag, sf::Sound* sound);
		void deleteAllSounds();
	private:
		SoundManager() {};
		SoundManager(SoundManager const&) {};             // copy constructor is private
		SoundManager& operator=(SoundManager const&) {};  // assignment operator is private
		static SoundManager* sharedInstance;


	};
}

