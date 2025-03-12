#pragma once
#include <iostream>
#include <random>
#include "../Misc/StringUtils.h"
#include "Interfaces/IExecutableEvent.h"
#include "Interfaces/IWorkerAction.h"
#include "Threading/IETTHread.h"
#include "Threading/MySemaphore.h"

namespace loader
{
	using namespace threading;
	using namespace interfaces;
	using namespace misc;
	
	class StreamAssetLoader:public IWorkerAction
	{
	private:
		typedef std::string String;
	public:
		StreamAssetLoader(String path, IExecutableEvent* executionEvent);
		~StreamAssetLoader();

		String getName();
	private:
		void onStartTask() override;

		String path;
		String name;
		IExecutableEvent* execEvent;
		MySemaphore* semaphore;
	};
}

