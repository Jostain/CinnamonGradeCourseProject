#include "GameEngine.h"
#include "Mob.h"


Mob::Mob(int posX, int posY, int textureHeight, int textureWidth) : Actor(posX, posY, textureHeight, textureWidth)
{

}
void Mob::act()
{
	setX(getX()+1);
	setY(getY()+1);
}
Mob::~Mob()
{

}
