#ifndef PLAYER_H
#define PLAYER_H
#include "Actor.h"

/*Implementation av Actor. En karakt�r som styrs av spelaren och har olika kontroller beroende p� vilket team den tillh�r (0 eller 1)*/

class Player : public Actor
{
public:
	Player(int, int,int);
	void act();//definierar Players beteende
	void checkCollision();//kollar om n�gon actor kolliderar med player.
	void PewPew();//skapar kulor som f�rdas i samma rikning som player
	void move();//kontroller f�r spelare 1
	void move2();//kontroller f�r spelare 2
	~Player();
private:
	int direction = 0;//Players nuvarande rikning
	int cooldown = 0;//reglerar anv�ndadet av PewPew()
};

#endif