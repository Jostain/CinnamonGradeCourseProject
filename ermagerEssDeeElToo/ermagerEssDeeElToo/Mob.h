#ifndef MOB_H
#define MOB_H
#include "Actor.h"
class Mob : public Actor
{
public:
	Mob(int, int , int , int);
	void act();
	~Mob();
};

#endif