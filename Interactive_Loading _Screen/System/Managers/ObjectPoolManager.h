#pragma once
#include "../../Misc/PoolTags.h"
#include "../Pooling/GameObjectPool.h"
namespace managers
{
	using namespace misc;
	using namespace systems;
	class ObjectPoolManager
	{
	private:
		std::unordered_map<PoolTag, GameObjectPool*> mapObjectPool;
	
	public:
		void registerObjectPool(GameObjectPool* pPool);
		void unregisterObjectPool(GameObjectPool* pPool);
	public:
		GameObjectPool* getPool(PoolTag tag);

	private:
		
		ObjectPoolManager();
		ObjectPoolManager(const ObjectPoolManager&);
		ObjectPoolManager& operator = (const ObjectPoolManager&);
		static ObjectPoolManager* sharedInstance;

	public:
		static ObjectPoolManager* getInstance();
	
	};

}

