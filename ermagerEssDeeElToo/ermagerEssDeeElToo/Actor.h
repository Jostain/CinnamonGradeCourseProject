#pragma once
#include "GameEngine.h"
class Actor : public Sprite
{
public:
	Actor::Actor(int posX, int posY, int textureHeight, int textureWidth);
	virtual void act() = 0;
	void connectToEngine();
	~Actor();
};