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


std::vector<Actor*> Actor::intersect()
{
	std::vector<Actor*> intersections;
	
	SDL_bool SDL_IntersectRect(const SDL_Rect* A, const SDL_Rect* B);
	
	return intersections;
}
Actor::~Actor()
{

}

