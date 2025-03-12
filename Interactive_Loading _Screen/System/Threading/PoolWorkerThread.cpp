#include "PoolWorkerThread.h"
using namespace threading;
threading::PoolWorkerThread::PoolWorkerThread(int threadID, IFinishedTask* finishedTask)
{
	this->id = threadID;
	this->task = finishedTask;
}

threading::PoolWorkerThread::~PoolWorkerThread()
{

}

int threading::PoolWorkerThread::getThreadID()
{
	return this->id;
}

void threading::PoolWorkerThread::assignTask(IWorkerAction* action)
{
	this->action = action;
}

void threading::PoolWorkerThread::run()
{
	this->action->onStartTask();
	this->task->onFinished(this->id);
}
