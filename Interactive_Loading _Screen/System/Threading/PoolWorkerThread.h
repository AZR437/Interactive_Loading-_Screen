#pragma once
#include "IETTHread.h"
#include "ThreadPool.h"
namespace threading
{
	using namespace interfaces;
	class PoolWorkerThread:public IETThread
	{
	private:
		int id;
		IWorkerAction* action;
		IFinishedTask* task;
	public:
		PoolWorkerThread(int threadID, IFinishedTask* finishedTask);
		~PoolWorkerThread();

		int getThreadID();
		void assignTask(IWorkerAction* action);

	private:
		void run();
		

	};
}


