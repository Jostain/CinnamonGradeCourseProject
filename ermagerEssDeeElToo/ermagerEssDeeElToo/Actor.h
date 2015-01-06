#pragma once
#include "GameEngine.h"
class Actor : public Sprite
{
public:
	virtual void Act()=0;
	~Actor();
};