#include "Mob.h"


Mob::Mob(int posX, int posY) : Actor(posX, posY, 32, 32)
{
	setTeam(1);
}
void Mob::act()
{
	checkCollision();
}
void Mob::checkCollision()
{
	std::vector<Actor*> collideVector = getEngine() -> intersections(getPosition());
	int nextActor = 0;
	while (nextActor < collideVector.size())
	{
		if (collideVector[nextActor]->getTeam() != getTeam())
		{
			gameEngine->removeActor(getID());
			gameEngine->removeSprite(getID());
		}
		nextActor++;

	}
}
Mob::~Mob()
{

}
