#include "Bullet.h"


Bullet::Bullet(int posX, int posY, int textureHeight, int textureWidth, int direction, int team) : Actor(posX, posY, 6, 6)

{
	setTeam(team);
	setSprite(128, 0,6,6);
	currentDirection = direction;
	std::cout << currentDirection << std::endl;
}
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
void Bullet::checkCollision()
{
	std::vector<Actor*> collideVector = getEngine()->intersections(getPosition());
	int nextActor = 0;
	while (nextActor < collideVector.size())
	{
		if (collideVector[nextActor]->getTeam() == 4)
		{
			gameEngine->removeActor(getID());
			//gameEngine->end();
			delete this;
		}
		nextActor++;

	}
}

Bullet::~Bullet()
{
}
