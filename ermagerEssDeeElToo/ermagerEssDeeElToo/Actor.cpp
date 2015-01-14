#include "Actor.h"
#include "Sprite.h"
#include "GameEngine.h"
#include <vector>
Actor::Actor(int posX, int posY, int textureHeight, int textureWidth) : Sprite(posX, posY, textureHeight, textureWidth)
{

}
void Actor::connectToEngine(GameEngine* GE)
{
	gameEngine = GE;
}
Actor::~Actor()
{
}

