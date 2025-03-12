#pragma once
namespace interfaces
{
	class IWorkerAction
	{
	public:
		virtual void onStartTask() =0;
	};
}