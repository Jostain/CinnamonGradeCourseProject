#ifndef PLAYER_H
#define PLAYER_H
#include "Actor.h"
class Player : public Actor
{
public:
	Player(int, int, int, int);
	void act();
	~Player();
};

#endif