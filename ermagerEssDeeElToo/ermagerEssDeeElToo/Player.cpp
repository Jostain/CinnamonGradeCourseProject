#include "Player.h"


Player::Player(int posX, int posY, int textureHeight, int textureWidth) : Actor(posX, posY, textureHeight, textureWidth)
{

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
}
Player::~Player()
{

}
