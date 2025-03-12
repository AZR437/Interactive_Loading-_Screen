#pragma once
#include "semaphore"
namespace threading
{
	class MySemaphore
	{
	public:
		MySemaphore(int available);
		~MySemaphore();

		void aquire() const;
		void aquire(int permits) const;
		void release() const;
		void release(int permits) const;

	private:
		const static int GLOBAL_MAX_PERMIT = 16;
		typedef std::counting_semaphore<GLOBAL_MAX_PERMIT> Semaphore;
		Semaphore* semaphore;

	};
}

