#include "Actor.h"
#include "Sprite.h"
#include "GameEngine.h"
#include <vector>
/*Konstruktor som endast vidarebefodrar information till Sprite*/
Actor::Actor(int posX, int posY, int textureHeight, int textureWidth) : Sprite(posX, posY, textureHeight, textureWidth)
{

}
/*ger actorn tillgång till gameEngines funktioner genom en pekare*/
void Actor::connectToEngine(GameEngine* GE)
{
	gameEngine = GE;
}
Actor::~Actor()
{
}

