#include "Player2.h"
#include "Bullet.h"


Player2::Player2(int posX, int posY) : Actor(posX, posY, 32, 32)
{
	setTeam(1);
	setSprite(32, 32,32,32);
	std::cout << getTeam() << std::endl;
}
void Player2::act()
{
	if (getD() == true)
	{
		setX(getX() + 3);
		setSprite(32, 32,32,32);
		direction = 1;
	}
	if (getA() == true)
	{
		setX(getX() - 3);
		setSprite(96, 32,32,32);
		direction = 3;
	}
	if (getW() == true)
	{
		setY(getY() - 3);
		setSprite(0, 32,32,32);
		direction = 0;
	}
	if (getS() == true)
	{
		setY(getY() + 3);
		setSprite(64, 32,32,32);
		direction = 2;
	}
	PewPew();
	checkCollision();

}
void Player2::checkCollision()
{
	std::vector<Actor*> collideVector = getEngine()->intersections(getPosition());
	int nextActor = 0;
	while (nextActor < collideVector.size())
	{
		if (collideVector[nextActor]->getTeam() == 0)
		{
			gameEngine->removeActor(getID());
			delete this;
		}
		nextActor++;

	}
}
void Player2::PewPew()
{
	if (getSpace() == true && cooldown == 0)
	{
		Bullet* bullet = new Bullet(getX() + 13, getY() + 13,32,32, direction, 1);
		gameEngine->add(bullet, gameEngine);
		cooldown = 10;
	}
	if (cooldown != 0)
		cooldown--;

}
Player2::~Player2()
{

}
