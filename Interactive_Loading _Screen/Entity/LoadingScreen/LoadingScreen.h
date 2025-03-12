#pragma once

#include "../../System/Managers/TextureManager.h"
#include "../../System/Managers/GameObjectManager.h"
#include "../../System/Managers/ObjectPoolManager.h"
#include "../../System/Managers/SoundManager.h"
#include "../../System/Pooling/GameObjectPool.h"
#include "../../Misc/SoundTags.h"
#include "../Pooling/Enemy.h"
#include "../GameObject.h"
#include "../ImageObjects/Background.h"
namespace entities
{
	using namespace managers;
	using namespace pooling;
	class LoadingScreen:public GameObject
	{
	private:
		std::vector<sf::Texture*> textures;
		sf::RenderWindow* window;
		float timer = 0;
		float spawnTime = 2;
	public:
		LoadingScreen(std::string name, sf::RenderWindow* window);
		~LoadingScreen();
		void initialize();
		void processInput(sf::Event event);
		void update(sf::Time deltaTime);
	};
}


