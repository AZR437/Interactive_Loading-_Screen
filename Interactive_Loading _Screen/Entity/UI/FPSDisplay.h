#pragma once
#include "../GameObject.h"
#include "../../Misc/Constants.h"
#include "../../System/Runner.h"
namespace userinterface
{
	using namespace entities;

	class FPSDisplay : public GameObject
	{
	private:
		sf::Time updateTime;
		sf::Text* statsText;

	private:
		void updateFPS(sf::Time elapsedTime);

	public:
		FPSDisplay(std::string name);
		~FPSDisplay();
		void initialize() ;
		void processInput(sf::Event event) ;
		void update(sf::Time deltaTime) ;
		void draw(sf::RenderWindow* targetWindow) ;



	};
}

