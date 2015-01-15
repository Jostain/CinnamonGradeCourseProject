#ifndef BULLET_H
#define BULLET_H
#include "Actor.h"
class Bullet : public Actor
{
public:
	Bullet(int, int,int,int);
	void checkCollision();//kollar om någon actor kolliderar med bullet.

	void act();//definierar bullets beteende
	~Bullet();
private:
	int currentDirection;//styr vilken rikning en bullet färdas i
	int life = 30;//reglerar en bullets räckvid/livslängd
};
#endif
