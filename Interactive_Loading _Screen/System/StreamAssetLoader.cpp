#include "StreamAssetLoader.h"
#include "Managers/TextureManager.h"
using namespace loader;
using namespace managers;
StreamAssetLoader::StreamAssetLoader(String path, IExecutableEvent* executionEvent)
{
	this->path = path;
	this->execEvent = executionEvent;
	this->name = "Asset Loader";
	this->semaphore = new MySemaphore(1);
}

StreamAssetLoader::~StreamAssetLoader()
{
	std::cout << "Destroying stream asset loader. " << std::endl;
}

std::string loader::StreamAssetLoader::getName()
{
	return this->name;
}

void loader::StreamAssetLoader::onStartTask()
{
	std::random_device seeder;
	std::mt19937 engine(seeder());
	std::uniform_int_distribution<int> dist(1000, 5000);
	IETThread::sleep(dist(engine));

	this->semaphore->aquire();
	std::vector<String> tokens = StringUtils::split(path, '/');
	String assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
	
	TextureManager::getInstance()->instantiateAsTexture(path, assetName, true);

	std::cout << "[TextureManager] Loaded streaming texture: " << assetName << std::endl;

	this->execEvent->onFinishedExecution();
	this->semaphore->release();
	//delete after being done
	delete this;
}


