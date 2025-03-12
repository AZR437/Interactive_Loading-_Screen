#include "NextButton.h"

userinterface::NextButton::NextButton(std::string name, sf::RenderWindow* rw): GameObject(name)
{
	this->rw = rw;
}

userinterface::NextButton::~NextButton()
{
	delete this->statsText->getFont();
	delete this->statsText;
	GameObject::~GameObject();
}

void userinterface::NextButton::initialize()
{
	sf::Font* font = new sf::Font();
	font->loadFromFile("Media/Sansation.ttf");
	this->rs = new sf::RectangleShape(sf::Vector2f(200,100));
	this->rs->setOrigin(this->rs->getScale().x / 2, this->rs->getScale().y / 2);
	rs->setPosition(WINDOW_WIDTH/2 -100,WINDOW_HEIGHT-200);
	this->statsText = new sf::Text();
	this->statsText->setFont(*font);
	this->statsText->setPosition(this->rs->getPosition().x +60, this->rs->getPosition().y + 25);
	this->statsText->setOutlineColor(sf::Color(0.f, 0.f, 0.f));
	this->statsText->setOutlineThickness(2.5f);
	this->statsText->setCharacterSize(35);
	this->statsText->setString("Next");
	
}

void userinterface::NextButton::processInput(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (this->rs->getGlobalBounds().contains(this->rw->mapPixelToCoords(sf::Mouse::getPosition(*this->rw))))
			{
				((TexDisplay*)GameObjectManager::getInstance()->findObjectByName("TextureDisplay"))->setIsDone(true);
				this->isEnabled = false;
			}
		}
		break;
	default:
		break;
	}
}

void userinterface::NextButton::update(sf::Time deltaTime)
{
}

void userinterface::NextButton::draw(sf::RenderWindow* targetWindow)
{
	GameObject::draw(targetWindow);

	if (this->rs != nullptr)
		targetWindow->draw(*this->rs);
	if (this->statsText != nullptr)
		targetWindow->draw(*this->statsText);
}
