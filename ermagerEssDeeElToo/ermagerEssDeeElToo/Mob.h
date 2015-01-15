#ifndef MOB_H
#define MOB_H
#include "Actor.h"
class Mob : public Actor
{
public:
	Mob(int, int);
	void act();//definierar bullets beteende
	~Mob();
private:
	bool goingUp = true;
};

#endif