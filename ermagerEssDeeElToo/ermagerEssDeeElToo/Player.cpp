#include "Player.h"
#include "Bullet.h"


Player::Player(int posX, int posY) : Actor(posX, posY, 32, 32)
{
	setTeam(0);
	setSprite(32, 0,32,32);
	std::cout << getTeam() << std::endl;
}
void Player::act()
{
	if (getRight() == true)
	{
		setX(getX() + 3);
		setSprite(32, 0, 32, 32);
		direction = 1;
	}
	if (getLeft() == true)
	{
		setX(getX() - 3);
		setSprite(96, 0, 32, 32);
		direction = 3;
	}
	if (getUp() == true)
	{
		setY(getY() - 3);
		setSprite(0, 0, 32, 32);
		direction = 0;
	}
	if (getDown() == true)
	{
		setY(getY() + 3);
		setSprite(64, 0,32,32);
		direction = 2;
	}
	PewPew();
	checkCollision();
	
}
void Player::checkCollision()
{
	std::vector<Actor*> collideVector = getEngine()->intersections(getPosition());
	int nextActor = 0;
	while (nextActor < collideVector.size())
	{
		if (collideVector[nextActor]->getTeam() != 0)
		{
			gameEngine->removeActor(getID());
			//gameEngine->end();
			delete this;
		}
		nextActor++;

	}
}
void Player::PewPew()
{
	if(getZero() == true && cooldown == 0)
	{
		Bullet* bullet = new Bullet(getX() + 13, getY() + 13, 32, 32, direction, 0);
		gameEngine->add(bullet, gameEngine);
		cooldown = 10;
	}
	if (cooldown != 0)
	cooldown--;
	
}
Player::~Player()
{

}
