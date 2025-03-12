#include "TexDisplay.h"
#include "Background.h"
using namespace entities;
TexDisplay::TexDisplay(std::string name):GameObject(name)
{
}

void TexDisplay::initialize()
{
	
}

void TexDisplay::processInput(sf::Event event)
{
}

void TexDisplay::update(sf::Time deltaTime)
{
	this->ticks += TIME_PER_FRAME.asMilliseconds();

	if(this->streamingType == StreamingType::BATCH_LOAD && !this->startedStreaming && this->ticks > this->STREAMING_LOAD_DELAY)
	{
		this->startedStreaming = true;
		this->ticks = 0;
		TextureManager::getInstance()->loadStreamingAssets();

	}

	if (this->streamingType == StreamingType::SINGLE_STREAM && this->ticks > this->STREAMING_LOAD_DELAY )
	{
		this->ticks = 0;
		TextureManager::getInstance()->loadSingleStreamAsset(this->numDisplayed, this);
		this->numDisplayed++;
		
	}
	if (this->numFinished > TextureManager::getInstance()->getStreamingAssetCount() - 1)
		GameObjectManager::getInstance()->findObjectByName("NextButton")->setEnabled(true);
	if (isDone)
	{
		GameObjectManager::getInstance()->findObjectByName("LoadingScreen")->setEnabled(false);
		if (!this->musicLoaded)
		{
			this->musicLoaded = true;
			SoundManager::getInstance()->loadMusic();
			SoundManager::getInstance()->getSound(SoundTags::MUSIC)->play();
		}
		this->arrangeCast();
		this->arrangeEnemies();

	}
}

void TexDisplay::onFinishedExecution()
{
	this->spawnObject();
}
void entities::TexDisplay::spawnObject()
{

	std::string objectName = TextureManager::getInstance()->getNameFromList(this->iconList.size()+6);
	Icon* icon = new Icon(objectName, this->iconList.size());
	this->iconList.push_back(icon);

	if (icon->getName() == "V")
		icon->setScale(.15, .15);
	else if (icon->getName() == "Trish")
		icon->setScale(.15f, .15f);
	else if (icon->getName() == "Eva")
		icon->setScale(.75,.75);
	else
		icon->setScale(.25f, .25f);

	//set position
	int IMG_WIDTH = 50; int IMG_HEIGHT = 50;
	float x = this->columnGrid * (IMG_WIDTH );
	float y = this->rowGrid * (IMG_HEIGHT );
	icon->setPosition(-1000, 0);

	std::cout << icon->getName() << std::endl;

	std::cout << "Set position: " << x << " " << y << std::endl;

	
	GameObjectManager::getInstance()->addObject(icon);
	this->numFinished++;

}
void TexDisplay::arrangeCast()
{

	GameObjectManager* manager = GameObjectManager::getInstance();
	manager->findObjectByName("Sparda")->setPosition(WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2);
	manager->findObjectByName("Eva")->setPosition(WINDOW_WIDTH / 2 - 200, WINDOW_HEIGHT / 2);
	manager->findObjectByName("Dante")->setPosition(WINDOW_WIDTH / 2 - 400, WINDOW_HEIGHT / 2);
	manager->findObjectByName("Vergil")->setPosition(WINDOW_WIDTH / 2 + 50, WINDOW_HEIGHT / 2 - 50);
	manager->findObjectByName("Nero")->setPosition(WINDOW_WIDTH / 2 + 250, WINDOW_HEIGHT / 2 - 50);
	manager->findObjectByName("V")->setPosition(WINDOW_WIDTH / 2 + 450, WINDOW_HEIGHT / 2 + 50);
	manager->findObjectByName("Lady")->setPosition(WINDOW_WIDTH / 2 - 500, WINDOW_HEIGHT / 2);
	manager->findObjectByName("Trish")->setPosition(WINDOW_WIDTH / 2 - 650, WINDOW_HEIGHT / 2 - 50);
	manager->findObjectByName("Rebellion")->setPosition(75, WINDOW_HEIGHT / 2 + 125);
	manager->findObjectByName("Yamato")->setPosition(75 + manager->findObjectByName("Yamato")->getLocalBounds().width / 2, WINDOW_HEIGHT - 400);
	manager->findObjectByName("Yamato")->setScale(-.5, .5);
	manager->findObjectByName("Kalina_Ann")->setPosition(0, WINDOW_HEIGHT / 2 + 225);
	manager->findObjectByName("Kalina_Ann")->setScale(.45, .45);
	manager->findObjectByName("Devil_Sword_Sparda")->setPosition(WINDOW_WIDTH - manager->findObjectByName("Devil_Sword_Sparda")->getLocalBounds().width / 2, WINDOW_HEIGHT - 500);
	manager->findObjectByName("Devil_Sword_Sparda")->setScale(.45, .45);
	manager->findObjectByName("Devil_Sword_Dante")->setPosition(WINDOW_WIDTH - 50, WINDOW_HEIGHT - 500);
	manager->findObjectByName("Devil_Sword_Dante")->setScale(-.45, .45);
	manager->findObjectByName("Devil_May_Cry")->setPosition(WINDOW_WIDTH / 2 - 175, 205);
	manager->findObjectByName("Devil_May_Cry")->setScale(.5, .5);
}

void TexDisplay::arrangeEnemies()
{
	GameObjectManager* manager = GameObjectManager::getInstance();
	manager->findObjectByName("Berial")->setPosition(-100, -25);
	manager->findObjectByName("Great_Demon3")->setPosition(-100, 150);
	manager->findObjectByName("Nelo_Angelo")->setPosition(-200, 250);
	manager->findObjectByName("Nelo_Angelo")->setScale(1, 1);
	manager->findObjectByName("Great_Demon")->setPosition(-50,500);
	manager->findObjectByName("Great_Demon")->setScale(.10,.10);
	manager->findObjectByName("Urizen")->setPosition(WINDOW_WIDTH - 150, 400);
	manager->findObjectByName("Echidna")->setPosition(WINDOW_WIDTH-150, 0);
	manager->findObjectByName("Great_Demon2")->setPosition(WINDOW_WIDTH-200, 150);
	manager->findObjectByName("Credo_Demon")->setPosition(WINDOW_WIDTH / 2 - 300,50);
	manager->findObjectByName("Demon")->setPosition(WINDOW_WIDTH/2 +200, 200);
	manager->findObjectByName("Demon1")->setPosition(WINDOW_WIDTH/2-100, 0);
	manager->findObjectByName("Demon2")->setPosition(WINDOW_WIDTH/2+100, 0);
	manager->findObjectByName("Demon4")->setPosition(WINDOW_WIDTH / 2 - 500, 300);
	manager->findObjectByName("Demon4")->setScale(.15, .15);
	manager->findObjectByName("Demon3")->setPosition(500, 0);
	manager->findObjectByName("Demon3")->setScale(-.35, .35);
	manager->findObjectByName("Demon5")->setPosition(WINDOW_WIDTH -400, 0);
	manager->findObjectByName("Demon6")->setPosition(200, 250);




}

void entities::TexDisplay::setIsDone(bool isDone)
{
	this->isDone = isDone;
}

