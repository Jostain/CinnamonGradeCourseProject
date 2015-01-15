#ifndef PLAYER_H
#define PLAYER_H
#include "Actor.h"

/*Implementation av Actor. En karaktär som styrs av spelaren och har olika kontroller beroende på vilket team den tillhör (0 eller 1)*/

class Player : public Actor
{
public:
	Player(int, int,int);
	void act();//definierar Players beteende
	void checkCollision();//kollar om någon actor kolliderar med player.
	void PewPew();//skapar kulor som fördas i samma rikning som player
	void move();//kontroller för spelare 1
	void move2();//kontroller för spelare 2
	~Player();
private:
	int direction = 0;//Players nuvarande rikning
	int cooldown = 0;//reglerar användadet av PewPew()
};

#endif