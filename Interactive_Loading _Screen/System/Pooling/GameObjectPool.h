#pragma once
#include "../../Misc/PoolTags.h"
#include "../Managers/GameObjectManager.h"
#include "../../Entity/GameObject.h"
#include "../../Entity/Pooling/PoolableObject.h"
namespace systems
{
	using namespace entities;
	using namespace managers;
	using namespace pooling;
	using namespace misc;
	class GameObjectPool
	{
	private:
		PoolTag tag;
		int poolSize;
		PoolableObject* poolableReference;

		std::vector<PoolableObject*> vecAvailableEntities;
		std::vector<PoolableObject*> vecUsedEntities;
	public:
		GameObjectPool(PoolTag ETag, int nPoolSize, PoolableObject* pPoolableReference);

	public:
		void initialize();

		PoolableObject* requestPoolable();
		void releasePoolable(PoolableObject* pPoolableObject);
		PoolTag getTag();
	private:
		bool hasAvailable(int nRequestSize);
		void setEnabled(PoolableObject* pPoolableObject, bool bEnabled);

	};
}


