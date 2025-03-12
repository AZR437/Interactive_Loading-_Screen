#pragma once
#include "PoolableObject.h"
#include "../../Component/Interfaces/IKillable.h"
#include "../../Misc/PoolTags.h"
#include "../ImageObjects/Background.h"
#include "../../System/Managers/ObjectPoolManager.h"
namespace pooling
{
	using namespace interfaces;
	using namespace misc;
	class Enemy:public PoolableObject, IKillable
	{
	private: 
		bool isKilled;
		float timer = 0;
		float lifeSpan = 2;
		Background* background;
		sf::RenderWindow* window;
	public:
		Enemy(PoolTag tag, std::string name, sf::Texture* tex, Background* background, sf::RenderWindow* window);
		~Enemy();
	public:
		void initialize();
		void processInput(sf::Event event);
		void update(sf::Time deltaTime);
		PoolableObject* clone();
		void onActivate();
		void onRelease();
		void onKill();
		void onSuicide();
		int getRandomNumber(int nLowerbound, int nUpperbound);
	};
}


