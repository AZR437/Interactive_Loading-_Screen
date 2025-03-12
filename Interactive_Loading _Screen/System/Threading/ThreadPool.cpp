#include "ThreadPool.h"
#include "PoolWorkerThread.h"
#include "../StreamAssetLoader.h"
using namespace threading;
using namespace loader;
threading::ThreadPool::ThreadPool(String name, int numWorkers)
{
	this->name = name;
	this->numWorkers = numWorkers;
	for (int i = 0; i < numWorkers; i++)
	{
		this->inactiveThreads.push(new PoolWorkerThread(i, this));
	}
}

threading::ThreadPool::~ThreadPool()
{
	this->stopScheduler();
	this->activeThreads.clear();
	while (!this->inactiveThreads.empty())
	{
		this->inactiveThreads.pop();
	}
}

void threading::ThreadPool::startScheduler()
{
	this->running = true;
	this->start();
}

void threading::ThreadPool::stopScheduler()
{
	this->running = false;
}

void threading::ThreadPool::scheduleTask(IWorkerAction *action)
{
	this->pendingActions.push(action);
}

void threading::ThreadPool::run()
{
	std::cout << this->running << std::endl;
	while (this->running)
	{
		if (!this->pendingActions.empty())
		{
			if(!this->inactiveThreads.empty())
			{
				
				PoolWorkerThread* workerThread = this->inactiveThreads.front();
				
				this->inactiveThreads.pop();

				this->activeThreads[workerThread->getThreadID()] = workerThread;

				
				workerThread->assignTask(this->pendingActions.front());
			
				workerThread->start();
				this->pendingActions.pop();
		
				//std::cout << this->inactiveThreads.size() << std::endl;
				//this->onFinished(workerThread->getThreadID());
				
			}
		}
	}
}

void threading::ThreadPool::onFinished(int threadID)
{
	if (this->activeThreads[threadID] != nullptr)
	{
		delete this->activeThreads[threadID];
		this->activeThreads.erase(threadID);
		this->inactiveThreads.push(new PoolWorkerThread(threadID, this));
	}
}
