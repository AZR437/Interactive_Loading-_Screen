#pragma once
namespace interfaces
{
	class IKillable
	{
	public:
		virtual void onKill() = 0;
		virtual void onSuicide() = 0;
	};
}