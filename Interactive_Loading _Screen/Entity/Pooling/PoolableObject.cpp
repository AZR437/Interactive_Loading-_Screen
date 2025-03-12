#include "PoolableObject.h"
using namespace pooling;
pooling::PoolableObject::PoolableObject(PoolTag tags, std::string strName):GameObject(strName)
{
	this->tag = tag;
}

pooling::PoolableObject::~PoolableObject()
{
}

PoolTag pooling::PoolableObject::getTag()
{
	return this->tag;
}
