#include "FPSDisplay.h"
using namespace userinterface;
using namespace systems;
FPSDisplay::FPSDisplay(std::string name):GameObject(name)
{
	
}

FPSDisplay::~FPSDisplay()
{
	delete this->statsText->getFont();
	delete this->statsText;
	GameObject::~GameObject();
}

void FPSDisplay::initialize()
{
	sf::Font* font = new sf::Font();
	font->loadFromFile("Media/Sansation.ttf");

	this->statsText = new sf::Text();
	this->statsText->setFont(*font);
	this->statsText->setPosition(WINDOW_WIDTH - 200, WINDOW_HEIGHT - 70);
	this->statsText->setOutlineColor(sf::Color(1.0f, 1.0f, 1.0f));
	this->statsText->setOutlineThickness(2.5f);
	this->statsText->setCharacterSize(35);
}

void FPSDisplay::processInput(sf::Event event)
{
	
}

void FPSDisplay::update(sf::Time deltaTime)
{
	this->updateFPS(deltaTime);
}

void FPSDisplay::updateFPS(sf::Time elapsedTime)
{
	this->updateTime += elapsedTime;
	if (this->updateTime >= sf::seconds(0.25f))
	{
		this->updateTime = sf::seconds(0.0f);
		this->statsText->setString("FPS: " + std::to_string(Runner::getInstance()->getFPS()) + "\n");

	}
}

void FPSDisplay::draw(sf::RenderWindow* targetWindow)
{
	GameObject::draw(targetWindow);

	if (this->statsText != nullptr)
		targetWindow->draw(*this->statsText);
}

