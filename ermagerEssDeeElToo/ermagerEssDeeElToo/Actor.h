#ifndef ACTOR_H
#define ACTOR_H
#include "Sprite.h"
#include "GameEngine.h"
#include <vector>

class Actor : public Sprite
{
public:
	GameEngine* gameEngine;
	Actor::Actor(int posX, int posY, int textureHeight, int textureWidth);
	virtual void act() = 0;
	void connectToEngine(GameEngine* GE);
	void disconnectfromEngine();
	std::vector<Actor*> intersect();
	GameEngine* Actor::getEngine(){return gameEngine;}
	bool getUp(){ return gameEngine->getUp(); }
	bool getDown(){ return gameEngine->getDown(); }
	bool getRight(){ return gameEngine->getRight(); }
	bool getLeft(){ return gameEngine->getLeft(); }
	~Actor();

};
#endif