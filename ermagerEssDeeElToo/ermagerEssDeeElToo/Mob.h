#pragma once
#include "GameEngine.h"
class Mob : public Actor
{
public:
	Mob(int, int , int , int);
	void act();
	~Mob();
};

