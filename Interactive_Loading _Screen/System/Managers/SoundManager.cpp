#include "SoundManager.h"
#include"iostream"
using namespace managers;
SoundManager* SoundManager::sharedInstance = NULL;
SoundManager* SoundManager::getInstance()
{
    if (sharedInstance == NULL)
	{
		sharedInstance = new SoundManager();
	}
	return sharedInstance;;
}

sf::Sound* managers::SoundManager::getSound(SoundTags tag)
{
	if (this->soundMap[tag] != NULL)
	{
		return this->soundMap[tag];
	}
	else
	{
		std::cout << "Error" << std::endl;
		return NULL;
	}
}

void managers::SoundManager::loadLoadingScreenSFX()
{
	
	std::cout << "[SoundManager] Reading from sfx list" << std::endl;
	std::ifstream stream("Media/sfx.txt");
	std::string path;

	while (std::getline(stream, path))
	{
		std::vector<std::string> tokens = StringUtils::split(path, '/');
		std::string soundName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
		this->loadSound(SoundTags::SFX, path);
		std::cout << soundName << std::endl;
		std::cout << "[SoundManager] Loaded sfx: " << soundName << std::endl;
	}
}

void managers::SoundManager::loadMusic()
{
	std::cout << "[SoundManager] Reading from music list" << std::endl;
	std::ifstream stream("Media/music.txt");
	std::string path;

	while (std::getline(stream, path))
	{
		std::vector<std::string> tokens = StringUtils::split(path, '/');
		std::string soundName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
		this->loadSound(SoundTags::MUSIC, path);
		std::cout << soundName << std::endl;
		std::cout << "[SoundManager] Loaded music: " << soundName << std::endl;
	}
}

void managers::SoundManager::loadSound(SoundTags tag, std::string path)
{
	sf::Sound* sound = new sf::Sound();
	sf::SoundBuffer* buffer = new sf::SoundBuffer();

	buffer->loadFromFile(path);
	sound->setBuffer(*buffer);
	if (tag == SoundTags::SFX)
	{
		sound->setVolume(50.f);
	}
	else
	{
		sound->setVolume(100);
		sound->setLoop(true);
	}
	this->addSound(tag, sound);
}


void managers::SoundManager::addSound(SoundTags tag, sf::Sound* sound)
{
	this->soundMap[tag] = sound;
	this->soundList.push_back(sound);

}

void managers::SoundManager::deleteAllSounds()
{
	sf::Sound* sound;
	for (int i = 0; i < this->soundList.size(); i++) {
		sound = this->soundList[i];
		if (sound->getStatus() == sf::Sound::Stopped) {
			delete this->soundList[i];
		}
	}
	soundMap.clear();
}








