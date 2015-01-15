#include "Bullet.h"


/*Implementation av Actor. en kula med kort räckvid som dödar player som inte är på samma lag som den player som skapade kulan*/

Bullet::Bullet(int posX, int posY, int direction, int team) : Actor(posX, posY, 6, 6)

{
	setTeam(team);
	setSprite(128, 0,6,6);
	currentDirection = direction;
}
/*definierar Players beteende*/
void Bullet::act()
{
	
	if (currentDirection == 1)
	{
		setX(getX() + 10);
	}
	if (currentDirection == 3)
	{
		setX(getX() - 10);	
	}
	if (currentDirection == 0)
	{
		setY(getY() - 10);
	}
	if (currentDirection == 2)
	{
		setY(getY() + 10);
	}
	
	life--;
	if (life == 0)

	gameEngine->removeActor(getID());
	checkCollision();
}
/*kollar om någon actor kolliderar med Bullet.*/
void Bullet::checkCollision()
{
	std::vector<Actor*> collideVector = gameEngine->intersections(getPosition());
	int nextActor = 0;
	while (nextActor < collideVector.size())
	{
		if (collideVector[nextActor]->getTeam() == 4)
		{
			gameEngine->removeActor(getID());
			delete this;
		}
		nextActor++;

	}
}

Bullet::~Bullet()
{
}
