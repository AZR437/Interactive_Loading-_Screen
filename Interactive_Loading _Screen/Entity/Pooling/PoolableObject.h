#pragma once
#include "../GameObject.h"
#include "../../Misc/PoolTags.h"
namespace pooling
{
    using namespace entities;
    using namespace misc;
	class PoolableObject:public GameObject
	{
    protected: 
        PoolTag tag;
    public:
        PoolableObject(PoolTag tag, std::string strName);
        ~PoolableObject();

    public:
        virtual void initialize() = 0;
        virtual void onActivate() = 0;
        virtual void onRelease() = 0;
        virtual PoolableObject* clone() = 0;
        PoolTag getTag();
        
	};
}

