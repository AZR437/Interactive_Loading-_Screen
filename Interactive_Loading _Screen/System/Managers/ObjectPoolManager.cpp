#include "ObjectPoolManager.h"
using namespace managers;
ObjectPoolManager* ObjectPoolManager::sharedInstance = NULL;
void managers::ObjectPoolManager::registerObjectPool(GameObjectPool* pPool)
{
	this->mapObjectPool[pPool->getTag()] = pPool;
}

void managers::ObjectPoolManager::unregisterObjectPool(GameObjectPool* pPool)
{
	this->mapObjectPool[pPool->getTag()] = pPool;
}

GameObjectPool* managers::ObjectPoolManager::getPool(PoolTag tag)
{
	return this->mapObjectPool[tag];
}

managers::ObjectPoolManager::ObjectPoolManager()
{
}

ObjectPoolManager* managers::ObjectPoolManager::getInstance()
{
	if (sharedInstance == NULL)
		sharedInstance = new ObjectPoolManager();
	return sharedInstance;
}
