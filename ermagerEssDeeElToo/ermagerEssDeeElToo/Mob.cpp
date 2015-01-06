#include "GameEngine.h"
#include "Mob.h"


Mob::Mob(int posX, int posY, int textureHeight, int textureWidth, std::string path) : Actor(posX, posY, textureHeight, textureWidth, path)
{

}
void Mob::act()
{
	setX(getX()+2);
	setY(getY()+2);
}
Mob::~Mob()
{

}
