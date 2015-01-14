#ifndef BULLET_H
#define BULLET_H
#include "Actor.h"
class Bullet : public Actor
{
public:
	Bullet(int, int, int,int,int,int);
	void checkCollision();
	void act();
	~Bullet();
private:
	int currentDirection = 3;
	int life = 30;
};
#endif
