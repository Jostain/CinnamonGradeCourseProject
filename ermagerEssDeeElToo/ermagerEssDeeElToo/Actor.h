#ifndef ACTOR_H
#define ACTOR_H
#include "Sprite.h"
#include "GameEngine.h"
#include <vector>

class Actor : public Sprite
{
public:
	GameEngine* gameEngine = NULL;
	Actor::Actor(int posX, int posY, int textureHeight, int textureWidth);
	virtual void act() = 0;
	void connectToEngine(GameEngine* GE);
	void disconnectfromEngine();
	std::vector<Actor*> intersect();
	GameEngine* Actor::getEngine(){return gameEngine;}
	//player 1 contoller
	bool getUp(){ return gameEngine->getUp(); }
	bool getDown(){ return gameEngine->getDown(); }
	bool getRight(){ return gameEngine->getRight(); }
	bool getLeft(){ return gameEngine->getLeft(); }
	bool getZero(){ return gameEngine->getZero(); }
	
	//player 2 controller
	bool getW(){ return gameEngine->getW(); }
	bool getS(){ return gameEngine->getS(); }
	bool getD(){ return gameEngine->getD(); }
	bool getA(){ return gameEngine->getA(); }
	bool getSpace(){ return gameEngine->getSpace(); }
	int getTeam(){ return team; }
	void setTeam(int newTeam){ team = newTeam; }

	~Actor();
private:
	int team = 0;
	
};
#endif