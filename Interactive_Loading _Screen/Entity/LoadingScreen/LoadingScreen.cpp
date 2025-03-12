#include "LoadingScreen.h"
#include "iostream"
entities::LoadingScreen::LoadingScreen(std::string name, sf::RenderWindow* window):GameObject(name)
{
	this->window = window;
	this->textures = {};
}

entities::LoadingScreen::~LoadingScreen()
{
}

void entities::LoadingScreen::initialize()
{
	Background* background = (Background*)GameObjectManager::getInstance()->findObjectByName("Background");
	for (std::string name : TextureManager::getInstance()->getTextureAssetList())
	{
		if (name.find("Orb") != std::string::npos)
		{
			this->textures.push_back(TextureManager::getInstance()->getFromTextureMap(name, 0));
		}
	}
	for (int i = 0; i < this->textures.size(); i++)
	{
		if (i == 0)
		{
			GameObjectPool* objectPool = new GameObjectPool(PoolTag::RED, 5, new Enemy(PoolTag::RED, "Shootable_Orb" + std::to_string(i), this->textures[i], background, this->window));
			objectPool->initialize();
			std::cout << (int)objectPool->getTag() << std::endl;
			ObjectPoolManager::getInstance()->registerObjectPool(objectPool);
		}
		if (i == 1)
		{
			GameObjectPool* objectPool = new GameObjectPool(PoolTag::GREEN, 5, new Enemy(PoolTag::GREEN, "Shootable_Orb" + std::to_string(i), this->textures[i], background, this->window));
			objectPool->initialize();
			std::cout << (int)objectPool->getTag() << std::endl;

			ObjectPoolManager::getInstance()->registerObjectPool(objectPool);
		}
		if (i == 2)
		{
			GameObjectPool* objectPool = new GameObjectPool(PoolTag::BLUE, 5, new Enemy(PoolTag::BLUE, "Shootable_Orb" + std::to_string(i), this->textures[i], background, this->window));
			objectPool->initialize();
			std::cout << (int)objectPool->getTag() << std::endl;

			ObjectPoolManager::getInstance()->registerObjectPool(objectPool);
		}
		if (i == 3)
		{
			GameObjectPool* objectPool = new GameObjectPool(PoolTag::GOLD, 5, new Enemy(PoolTag::GOLD, "Shootable_Orb" + std::to_string(i), this->textures[i], background, this->window));
			objectPool->initialize();
			std::cout << (int)objectPool->getTag() << std::endl;

			ObjectPoolManager::getInstance()->registerObjectPool(objectPool);
		}
		if (i == 4)
		{
			GameObjectPool* objectPool = new GameObjectPool(PoolTag::PURPLE, 5, new Enemy(PoolTag::PURPLE, "Shootable_Orb" + std::to_string(i), this->textures[i], background, this->window));
			objectPool->initialize();
			std::cout << (int)objectPool->getTag() << std::endl;

			ObjectPoolManager::getInstance()->registerObjectPool(objectPool);
		}
	}


}

void entities::LoadingScreen::processInput(sf::Event event)
{
	
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (SoundManager::getInstance()->getSound(SoundTags::SFX)->getStatus() == sf::Sound::Playing)
			{
				SoundManager::getInstance()->getSound(SoundTags::SFX)->stop();
			}
			SoundManager::getInstance()->getSound(SoundTags::SFX)->play();
		}
		break;
	default:
		break;
	}
}

void entities::LoadingScreen::update(sf::Time deltaTime)
{
	this->timer += deltaTime.asSeconds();
	if (this->timer >= this->spawnTime)
	{
		int random = rand() % (6 - 1 + 1);
		//std::cout << random << std::endl;
		switch (random)
		{
		case 1:
			ObjectPoolManager::getInstance()->getPool(PoolTag::RED)->requestPoolable();
			break;
		case 2:
			ObjectPoolManager::getInstance()->getPool(PoolTag::GREEN)->requestPoolable();
			break;
		case 3:
			ObjectPoolManager::getInstance()->getPool(PoolTag::BLUE)->requestPoolable();
			break;
		case 4:
			ObjectPoolManager::getInstance()->getPool(PoolTag::GOLD)->requestPoolable();
			break;
		case 5:
			ObjectPoolManager::getInstance()->getPool(PoolTag::PURPLE)->requestPoolable();
			break;
		default:
			break;

		}
		this->timer = 0;
	}
}
