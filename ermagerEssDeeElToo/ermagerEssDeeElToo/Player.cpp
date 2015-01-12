#include "Player.h"


Player::Player(int posX, int posY, int textureHeight, int textureWidth) : Actor(posX, posY, textureHeight, textureWidth)
{

}
void Player::act()
{
	;
	if (getRight() == true)
	{
		setX(getX() + 2);
	}
	if (getLeft() == true)
	{
		setX(getX() - 2);
	}
	if (getUp() == true)
	{
		setY(getY() - 2);
	}
	if (getDown() == true)
	{
		setY(getY() + 2);
	}
}
Player::~Player()
{

}
