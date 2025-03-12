#pragma once
#include "vector"
#include "unordered_map"
#include "string"
#include "filesystem"
#include "fstream"
#include "SFML/Graphics.hpp"
#include "iostream"
#include "../../Misc/StringUtils.h"
#include "../Threading/IETTHread.h"
#include "../Threading/ThreadPool.h"
#include "../Interfaces/IExecutableEvent.h"
#include "../StreamAssetLoader.h"
#
namespace managers
{
	using namespace misc;
	using namespace threading;
	using namespace interfaces;
	class TextureManager
	{

	public:
		static TextureManager* getInstance();
		void loadFromAssetList(); //loading of all assets needed for startup
		void loadStreamingAssets(); //loading of assets during runtime
		void loadSingleStreamAsset(int index, IExecutableEvent* executableEvent); //loads a single streaming asset based on index in directory
		sf::Texture* getFromTextureMap(const std::string assetName, int frameIndex);
		int getNumFrames(const std::string assetName);

		sf::Texture* getStreamTextureFromList(const int index);
		std::string getNameFromList(const int index);
		std::vector<std::string> getTextureAssetList();
		int getNumLoadedStreamTextures() const;
		int getStreamingAssetCount();
		void instantiateAsTexture(std::string path, std::string assetName, bool isStreaming);


	private:
		TextureManager();
		TextureManager(TextureManager const&) {};             // copy constructor is private
		TextureManager& operator=(TextureManager const&) {};  // assignment operator is private
		static TextureManager* sharedInstance;

		std::unordered_map<std::string, std::vector<sf::Texture*>> textureMap;
		std::vector<sf::Texture*> baseTextureList;
		std::vector<sf::Texture*> streamTextureList;
		std::vector<std::string> assetNames;

		const std::string STREAMING_PATH = "Media/Assets/Entities/";
		int streamingAssetCount = 0;
		ThreadPool* threadPool;

		void countStreamingAssets();
		
	};
}


