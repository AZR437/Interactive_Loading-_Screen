#pragma once
#include "../GameObject.h"
#include "../../System/Managers/TextureManager.h"
namespace entities
{
	using namespace managers;
	class Icon:public GameObject
	{
	public:
		Icon(std::string name, int textureIndex);
		void initialize();
		void processInput(sf::Event event);
		void update(sf::Time deltaTime);

	private:
		int textureIndex = 0;
	};
}

