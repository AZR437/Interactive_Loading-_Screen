#include "GameObject.h"
using namespace entities;

GameObject::GameObject(std::string name)
{
	this->name = name;
}

GameObject::~GameObject()
{
	delete this->sprite;
	delete this->texture;

}

void GameObject::draw(sf::RenderWindow* targetWindow)
{
	if (this->sprite != NULL) {
		this->sprite->setPosition(this->posX, this->posY);
		this->sprite->setScale(this->scaleX, this->scaleY);
		targetWindow->draw(*this->sprite);
	}
}

std::string GameObject::getName()
{
	return this->name;
}

void GameObject::setPosition(float x, float y)
{
	this->posX = x;
	this->posY = y;
	if (this->sprite != nullptr)
	{
		this->sprite->setPosition(this->posX, this->posY);
	}
}

void GameObject::setScale(float x, float y)
{
	this->scaleX = x;
	this->scaleY = y;
	if (this->sprite != nullptr)
	{
		this->sprite->setScale(this->scaleX, this->scaleY);
	}
}


sf::FloatRect GameObject::getLocalBounds()
{
	return this->sprite->getLocalBounds();
}

sf::Vector2f GameObject::getPosition()
{
	return sf::Vector2f(this->posX, this->posY);
}

sf::Vector2f GameObject::getScale()
{
	return sf::Vector2f(this->scaleX, this->scaleY);
}

bool entities::GameObject::getEnabled()
{
	return this->isEnabled;
}

void entities::GameObject::setEnabled(bool isEnabled)
{
	this->isEnabled = isEnabled;
}

float entities::GameObject::getWidth()
{
	if (this->sprite != NULL)
		return this->sprite->getTexture()->getSize().x;
	return 0.0f;
}

float entities::GameObject::getHeight()
{
	if (this->sprite != NULL)
		return this->sprite->getTexture()->getSize().y;
	return 0.0f;
}

