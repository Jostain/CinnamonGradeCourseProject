#pragma once
#include "GameEngine.h"
class Actor : public Sprite
{
public:
	Actor::Actor(int posX, int posY, int textureHeight, int textureWidth, std::string path);
	virtual void Act() = 0;
	~Actor();
};