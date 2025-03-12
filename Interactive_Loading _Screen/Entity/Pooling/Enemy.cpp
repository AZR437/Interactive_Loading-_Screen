#include "Enemy.h"
using namespace pooling;
Enemy::Enemy(PoolTag tag,std::string name, sf::Texture* tex, Background* background, sf::RenderWindow* window):PoolableObject(tag,name)
{
	this->tag = tag;
	this->texture = tex;
	this->background = background;
	this->window = window;
}

Enemy::~Enemy()
{
}

void Enemy::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*this->texture);
	this->setScale(.25f, .25f);
}

void Enemy::processInput(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if(sprite->getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*this->window))))
			{
				this->isKilled = true;
				ObjectPoolManager::getInstance()->getPool(this->tag)->releasePoolable(this);
				
			}
		}
		break;
	default:
		break;
	}
}

void pooling::Enemy::update(sf::Time deltaTime)
{
	this->timer += deltaTime.asSeconds();
	if (this->timer >= this->lifeSpan && !this->isKilled)
	{
		ObjectPoolManager::getInstance()->getPool(this->tag)->releasePoolable(this);
		this->timer = 0;
	}
}

PoolableObject* pooling::Enemy::clone()
{
	PoolableObject* clone = new Enemy(this->tag,this->name, this->texture, this->background, this->window);
	return clone;
}

void pooling::Enemy::onActivate()
{
	int x = this->getRandomNumber(this->sprite->getTexture()->getSize().x / 2, this->background->getWidth() - this->sprite->getTexture()->getSize().x / 2);
	int y = this->getRandomNumber(this->sprite->getTexture()->getSize().y / 2, (this->background->getHeight() - 200) - this->sprite->getTexture()->getSize().y / 2);

	this->sprite->setPosition(x, y);
	this->setPosition(x, y);
}

void pooling::Enemy::onRelease()
{
	if (this->isKilled)
	{
		this->onKill();
	}
	else
	{
		this->onSuicide();
	}
}


void Enemy::onKill()
{
	std::cout << "Dead" << std::endl;
}

void Enemy::onSuicide()
{
	std::cout << "Self-Delete" << std::endl;
}

int pooling::Enemy::getRandomNumber(int nLowerbound, int nUpperbound)
{
	return rand() % (nUpperbound - nLowerbound + 1);
}


