#ifndef PLAYER_H
#define PLAYER_H
#include "Actor.h"
class Player : public Actor
{
public:
	Player(int, int);
	void act();
	void checkCollision();
	void PewPew();
	void getDirection();
	~Player();
private:
	int direction = 0;
	int cooldown = 0;
};

#endif