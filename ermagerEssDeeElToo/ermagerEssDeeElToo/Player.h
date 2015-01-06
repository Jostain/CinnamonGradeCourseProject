#pragma once
#include "Actor.h"

class Player:public Actor
{
public:
	Player();
	void OverrideMe();
	~Player();
};

