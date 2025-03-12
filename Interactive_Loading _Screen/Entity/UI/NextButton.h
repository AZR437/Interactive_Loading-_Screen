#pragma once
#include "../GameObject.h"
#include "../../Misc/Constants.h"
#include "../../System/Runner.h"
namespace userinterface
{
	using namespace entities;
	class NextButton : public GameObject
	{
	private:
		sf::Text* statsText;
		sf::RectangleShape* rs;
		sf::RenderWindow* rw;
	public:
		NextButton(std::string name, sf::RenderWindow* rw);
		~NextButton();
		void initialize();
		void processInput(sf::Event event);
		void update(sf::Time deltaTime);
		void draw(sf::RenderWindow* targetWindow);
	};
}

