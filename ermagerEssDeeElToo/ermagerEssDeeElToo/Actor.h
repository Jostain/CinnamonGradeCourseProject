#ifndef ACTOR_H
#define ACTOR_H
#include "Sprite.h"
#include "GameEngine.h"
#include <vector>
/*En Virtuell Klass som hanterar Klassers interaktioner med spel motorn*/
class Actor : public Sprite
{
public:
	GameEngine* gameEngine = NULL;//en GameEngine pekare som fylls när actor kopplas till en GameEngine via connectToEngine();
	Actor::Actor(int posX, int posY, int textureHeight, int textureWidth);//Konstruktor som endast vidarebefodrar information till Sprite
	virtual void act() = 0;//en virtuell metod som måste finnas i alla klasser som ärver av Actor så att motorn Så att motorn kan röra på sig.
	void connectToEngine(GameEngine* GE);//ger actorn tillgång till gameEngines funktioner genom en pekare
	
	//ger en actor tillgång till key events från motorn.
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
	//getter och setter till team som gör det möjligt att ha olika beteenden i akt beroende på vilket team dom tillhör snarare än klass.
	int getTeam(){ return team; }
	void setTeam(int newTeam){ team = newTeam; }

	~Actor();
private:
	int team = 0;
	
};
#endif