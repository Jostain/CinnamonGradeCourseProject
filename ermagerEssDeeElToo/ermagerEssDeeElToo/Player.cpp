#include "Player.h"


Player::Player(int posX, int posY, int textureHeight, int textureWidth) : Actor(posX, posY, textureHeight, textureWidth)
{
	setTeam(0);
	std::cout << getTeam();
}
void Player::act()
{
	;
	if (getRight() == true)
	{
		setX(getX() + 3);
		setSprite(32, 0, 32, 32);
	}
	if (getLeft() == true)
	{
		setX(getX() - 3);
		setSprite(32, 32, 32, 32);
	}
	if (getUp() == true)
	{
		setY(getY() - 3);
		setSprite(0, 32, 32, 32);
	}
	if (getDown() == true)
	{
		setY(getY() + 3);
		setSprite(0, 0, 32, 32);
	}
	checkCollision();
}
void Player::checkCollision()
{
	std::vector<Actor*> collideVector = getEngine()->intersections(getPosition());
	int nextActor = 0;
	while (nextActor < collideVector.size())
	{
		if (collideVector[nextActor]->getTeam() != getTeam())
		{
			std::cout << "test3" << std::endl;
			gameEngine->removeActor(getID());
			gameEngine->end();
			std::cout << "test4" << std::endl;
			delete this;
		}
		nextActor++;

	}
}
Player::~Player()
{

}
