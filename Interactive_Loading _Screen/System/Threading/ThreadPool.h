#pragma once
#include "queue"
#include "unordered_map"
#include "IETTHread.h"
#include "../Interfaces/IWorkerAction.h"
namespace threading
{
	using namespace interfaces;
	class PoolWorkerThread;
	class IFinishedTask
	{
	public:
		virtual void onFinished(int threadID) = 0;
	};
	class ThreadPool:public IETThread, public IFinishedTask
	{
	public:
		typedef std::string String;
		typedef std::queue<PoolWorkerThread*> ThreadList;
		typedef std::unordered_map<int, PoolWorkerThread*> ActiveThreadMap;
		typedef std::queue<IWorkerAction*> ActionList;
	private:
		String name;
		int counter = 0;
		bool running = false;
		int numWorkers = 0;
		ActiveThreadMap activeThreads;
		ThreadList inactiveThreads;
		ActionList pendingActions;

	
	public:
		ThreadPool(String name, int numWorkers);
		~ThreadPool();

		void startScheduler();
		void stopScheduler();
		void scheduleTask(IWorkerAction* action);
		void onFinished(int threadID);
	private:
		void run();
		
	};
}

