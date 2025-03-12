#pragma once
#include "SFML/Graphics.hpp"
#include "../Misc/Constants.h"
#include "Managers/TextureManager.h"
#include "Managers/GameObjectManager.h"
#include "Managers/SoundManager.h"
#include "../Entity/ImageObjects/Background.h"
#include "../Entity/ImageObjects/TexDisplay.h"
#include "../Entity/UI/FPSDisplay.h"
#include "../Entity/UI/NextButton.h"
#include "../Entity/LoadingScreen/LoadingScreen.h"

#include "vector"
namespace systems
{
	using namespace entities;
	using namespace managers;
	class Runner
	{
	private:

		sf::RenderWindow window;
		float fps = 0.0f;

	private:
		void processEvents();
		void update(sf::Time elapsedTime);
		void render();

	public:

		Runner();
		void run();
		static Runner* getInstance();
		static Runner* sharedInstance;
		float getFPS() const;


	};
}


