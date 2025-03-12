#include "MySemaphore.h"

threading::MySemaphore::MySemaphore(int available)
{
	this->semaphore = new Semaphore(available);
}

threading::MySemaphore::~MySemaphore()
{
	delete this->semaphore;
}

void threading::MySemaphore::aquire() const
{
	this->semaphore->acquire();
}

void threading::MySemaphore::aquire(int permits) const
{
	for (int i = 0; i < permits; i++)
	{
		this->semaphore->acquire();
	}
}

void threading::MySemaphore::release() const
{
	this->semaphore->release();
}

void threading::MySemaphore::release(int permits) const
{
	this->semaphore->release(permits);
}
