#pragma once
#include "../GameObject.h"
#include "../../Misc/Constants.h"
#include "../../System/Managers/GameObjectManager.h"
#include "../../System/Managers/SoundManager.h"
#include "../../System/Interfaces/IExecutableEvent.h"
#include "../../System/StreamAssetLoader.h"
#include "Icon.h"
namespace entities
{
	using namespace managers;
	using namespace interfaces;
	
	class TexDisplay:public GameObject,public IExecutableEvent
	{
	private:
		std::vector<Icon*> iconList;

		enum StreamingType { BATCH_LOAD = 0, SINGLE_STREAM = 1 };
		const float STREAMING_LOAD_DELAY = 1.f;
		const StreamingType streamingType = SINGLE_STREAM;
		float ticks = 0.0f;
		bool startedStreaming = false;
		bool isDone = false;
		bool musicLoaded = false;

		int columnGrid = 0; int rowGrid = 0;
		int numDisplayed = 0;
		int numFinished = 0;
		//const int MAX_COLUMN = 28;
		//const int MAX_ROW = 22;
		
	public:
		TexDisplay(std::string name);
		void initialize();
		void processInput(sf::Event event);
		void update(sf::Time deltaTime);
		void onFinishedExecution();
		void arrangeCast();
		void arrangeEnemies();
		void setIsDone(bool isDone);
	private:
		void spawnObject();
	};
}

