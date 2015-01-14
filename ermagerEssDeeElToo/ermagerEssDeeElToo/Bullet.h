#ifndef BULLET_H
#define BULLET_H
#include "Actor.h"
class Bullet : public Actor
{
public:
	Bullet(int, int, int, int);
	void act();
	~Bullet();
};
#endif
