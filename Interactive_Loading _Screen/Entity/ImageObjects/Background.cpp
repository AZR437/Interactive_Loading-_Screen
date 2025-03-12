#include "Background.h"
using namespace entities;
Background::Background(std::string name):GameObject(name)
{
}
void Background::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";

	//assign texture
	this->sprite = new sf::Sprite();
	sf::Texture* texture = TextureManager::getInstance()->getFromTextureMap("DMC_Shop", 0);
	this->sprite->setTexture(*texture);
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	//make BG height x k to emulate repeating BG.
	/*this->sprite->setTextureRect(sf::IntRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT * 8));
	this->setPosition(0, -WINDOW_HEIGHT * 7);*/
}

void Background::processInput(sf::Event event)
{
	
}

void Background::update(sf::Time deltaTime)
{
	////make BG scroll slowly
	//sf::Vector2f position = this->getPosition();
	//position.y += this->SPEED_MULTIPLIER * deltaTime.asSeconds();
	//this->setPosition(position.x, position.y);

	//sf::Vector2f localPos = this->sprite->getPosition();
	//if (localPos.y * deltaTime.asSeconds() > 0) {
	//	//reset position
	//	this->setPosition(0, -WINDOW_HEIGHT * 7);
	//}
	//else {

	//}
	
}

void entities::Background::setTexture(sf::Texture* texture)
{
	this->sprite->setTexture(*texture);
}
