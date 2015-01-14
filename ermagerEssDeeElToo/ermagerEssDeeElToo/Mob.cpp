#include "Mob.h"

Mob::Mob(int posX, int posY) : Actor(posX, posY, 32, 32)
{
	
	setTeam(4);
	setSprite(128, 6, 32, 32);
	std::cout << getTeam() << std::endl;
}
void Mob::act()
{
	if (getY() <= 0)
	goingUp = false;

	if (getY() >= 568)
	goingUp = true;

	if (goingUp == true)
		setY(getY() - 6);

	if (goingUp == false)
		setY(getY() + 6);
}
Mob::~Mob()
{

}
