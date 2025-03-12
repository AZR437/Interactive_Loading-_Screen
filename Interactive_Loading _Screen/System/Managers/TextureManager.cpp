#include "TextureManager.h"
using namespace loader;
using namespace managers;
TextureManager* TextureManager::sharedInstance = NULL;
TextureManager* managers::TextureManager::getInstance()
{
	if (sharedInstance == NULL)
	{
		sharedInstance = new TextureManager();
	}
	return sharedInstance;
}
TextureManager::TextureManager()
{
	this->countStreamingAssets();
	this->threadPool = new ThreadPool("ThreadPool", 8);
	this->threadPool->startScheduler();
	
}
void managers::TextureManager::loadFromAssetList()
{
	std::cout << "[TextureManager] Reading from asset list" << std::endl;
	std::ifstream stream("Media/assets.txt");
	std::string path;

	while (std::getline(stream, path))
	{
		std::vector<std::string> tokens = StringUtils::split(path, '/');
		std::string assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
		std::cout << assetName << std::endl;
		this->instantiateAsTexture(path, assetName, false);
		std::cout << "[TextureManager] Loaded texture: " << assetName << std::endl;
	}
}

void managers::TextureManager::loadStreamingAssets()
{
	for (const auto& entry : std::filesystem::directory_iterator(STREAMING_PATH)) {
		//simulate loading of very large file
		IETThread::sleep(200);

		std::string path = entry.path().generic_string();
		std::vector<std::string> tokens = StringUtils::split(path, '/');
		std::string assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
		this->instantiateAsTexture(path, assetName, true);

		std::cout << "[TextureManager] Loaded streaming texture: " << assetName << std::endl;
	}
}

void managers::TextureManager::loadSingleStreamAsset(int index, IExecutableEvent* executableEvent)
{
	int fileNum = 0;
	
	for (const auto& entry : std::filesystem::directory_iterator(STREAMING_PATH)) 
	{
		if (index == fileNum)
		{


			//<code here for loading asset>
			std::string path = STREAMING_PATH + entry.path().filename().string();
			std::vector<std::string> tokens = StringUtils::split(path, '/');
			std::string assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
			StreamAssetLoader* assetLoader = new StreamAssetLoader(path, executableEvent);

			//std::cout << path;
			this->threadPool->scheduleTask(assetLoader);
			break;
		}

		fileNum++;
	}
	
}



sf::Texture* managers::TextureManager::getFromTextureMap(const std::string assetName, int frameIndex)
{
	if (!this->textureMap[assetName].empty()) {
		return this->textureMap[assetName][frameIndex];
	}
	else {
		std::cout << "[TextureManager] No texture found for " << assetName << std::endl;
		return NULL;
	}
}

int managers::TextureManager::getNumFrames(const std::string assetName)
{
	if (!this->textureMap[assetName].empty()) {
		return this->textureMap[assetName].size();
	}
	else {
		std::cout << "[TextureManager] No texture found for " << assetName << std::endl;
		return 0;
	}
}

sf::Texture* managers::TextureManager::getStreamTextureFromList(const int index)
{
	return this->streamTextureList[index];
}

std::string managers::TextureManager::getNameFromList(const int index)
{
	return this->assetNames[index];
}

std::vector<std::string> managers::TextureManager::getTextureAssetList()
{
	return this->assetNames;
}

int managers::TextureManager::getNumLoadedStreamTextures() const
{
	return this->streamTextureList.size();
}

int managers::TextureManager::getStreamingAssetCount()
{
	return this->streamingAssetCount;
}

void managers::TextureManager::countStreamingAssets()
{
	this->streamingAssetCount = 0;
	for (const auto& entry : std::filesystem::directory_iterator(STREAMING_PATH)) {
		this->streamingAssetCount++;
	}
	std::cout << "[TextureManager] Number of streaming assets: " << this->streamingAssetCount << std::endl;
}

void managers::TextureManager::instantiateAsTexture(std::string path, std::string assetName, bool isStreaming)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	this->textureMap[assetName].push_back(texture);
	
	if (isStreaming)
	{
		this->streamTextureList.push_back(texture);
		this->assetNames.push_back(assetName);
	}
	else
	{
		this->baseTextureList.push_back(texture);
		this->assetNames.push_back(assetName);
	}
	

}
