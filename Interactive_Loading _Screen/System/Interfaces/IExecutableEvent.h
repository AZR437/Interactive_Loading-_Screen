#pragma once
namespace interfaces
{
	class IExecutableEvent
	{
	public:
		virtual void onFinishedExecution() = 0;
	};
};