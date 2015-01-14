#ifndef MOB_H
#define MOB_H
#include "Actor.h"
class Mob : public Actor
{
public:
	Mob(int, int);
	void act();
	void checkCollision();
	~Mob();
};

#endif