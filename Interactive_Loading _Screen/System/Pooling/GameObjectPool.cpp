#include "GameObjectPool.h"
using namespace systems;
systems::GameObjectPool::GameObjectPool(PoolTag tag, int poolSize, PoolableObject* poolableReference)
{
	this->tag = tag;
	this->poolSize = poolSize;
	this->poolableReference = poolableReference;

	this->vecAvailableEntities = {};
	this->vecUsedEntities = {};
}

void systems::GameObjectPool::initialize()
{
	for (int i = 0; i < this->poolSize; i++)
	{
		PoolableObject* poolableObject = this->poolableReference->clone();
		GameObjectManager::getInstance()->addObject(poolableObject);
		poolableObject->setEnabled(false);
		this->vecAvailableEntities.push_back(poolableObject);
	}
}

PoolableObject* systems::GameObjectPool::requestPoolable()
{
	if (this->hasAvailable(1)) {
		//std::cout << "pulling" << std::endl;
		PoolableObject* holder = this->vecAvailableEntities.back();
		//std::cout << holder->getName() << std::endl;
		this->vecAvailableEntities.pop_back();
		this->vecUsedEntities.push_back(holder);
		//std::cout << this->vecUsedEntities.size() << std::endl;
		this->setEnabled(holder, true);
		return holder;
	}
	return NULL;
}

void systems::GameObjectPool::releasePoolable(PoolableObject* poolableObject)
{
	int nIndex = -1;
	
	for (int i = 0; i < this->vecUsedEntities.size() && nIndex == -1; i++) {
		if (this->vecUsedEntities[i] == poolableObject) {
			nIndex = i;
		}
	}

	if (nIndex != -1) {
		std::cout << "releasing" << std::endl;
		PoolableObject* pHolder = this->vecUsedEntities[nIndex];
		this->vecAvailableEntities.push_back(pHolder);
		this->vecUsedEntities.erase(this->vecUsedEntities.begin() + nIndex);
		this->setEnabled(pHolder, false);
	}
}

PoolTag systems::GameObjectPool::getTag()
{
	return this->tag;
}

bool systems::GameObjectPool::hasAvailable(int nRequestSize)
{
	if (this->vecAvailableEntities.size() >= nRequestSize)
		return true;
	return false;
}

void systems::GameObjectPool::setEnabled(PoolableObject* poolableObject, bool bEnabled)
{
	poolableObject->setEnabled(bEnabled);
	std::cout << "Activating" << std::endl;
	if (bEnabled)
		poolableObject->onActivate();
	else
		poolableObject->onRelease();
}



