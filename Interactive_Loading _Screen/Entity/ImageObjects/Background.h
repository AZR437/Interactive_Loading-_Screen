#pragma once
#include "../GameObject.h"
#include "../../System/Managers/TextureManager.h"
#include "../../Misc/Constants.h"
namespace entities
{
	using namespace managers;

	class Background: public GameObject
	{
	private:
		const float SPEED_MULTIPLIER = 10000.f;
	public:
		Background(std::string name);
		void initialize() ;
		void processInput(sf::Event event) ;
		void update(sf::Time deltaTime) ;
		void setTexture(sf::Texture* texture);

	};
}

