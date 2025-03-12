#include "Icon.h"

entities::Icon::Icon(std::string name, int textureIndex):GameObject(name)
{
	this->textureIndex = textureIndex;
}

void entities::Icon::initialize()
{
	this->sprite = new sf::Sprite();
	sf::Texture* texture = TextureManager::getInstance()->getStreamTextureFromList(this->textureIndex);
	this->sprite->setTexture(*texture);
}

void entities::Icon::processInput(sf::Event event)
{
}

void entities::Icon::update(sf::Time deltaTime)
{
}
