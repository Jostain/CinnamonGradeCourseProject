#ifndef PLAYER2_H
#define PLAYER2_H
#include "Actor.h"
class Player2 : public Actor
{
public:
	Player2(int, int);
	void act();
	void checkCollision();
	void PewPew();
	void getDirection();
	~Player2();
private:
	int direction = 0;
	int cooldown = 0;
};

#endif