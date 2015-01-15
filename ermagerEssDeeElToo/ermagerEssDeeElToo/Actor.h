#ifndef ACTOR_H
#define ACTOR_H
#include "Sprite.h"
#include "GameEngine.h"
#include <vector>
/*En Virtuell Klass som hanterar Klassers interaktioner med spel motorn*/
class Actor : public Sprite
{
public:
	GameEngine* gameEngine = NULL;//en GameEngine pekare som fylls n�r actor kopplas till en GameEngine via connectToEngine();
	Actor::Actor(int posX, int posY, int textureHeight, int textureWidth);//Konstruktor som endast vidarebefodrar information till Sprite
	virtual void act() = 0;//en virtuell metod som m�ste finnas i alla klasser som �rver av Actor s� att motorn S� att motorn kan r�ra p� sig.
	void connectToEngine(GameEngine* GE);//ger actorn tillg�ng till gameEngines funktioner genom en pekare
	
	//ger en actor tillg�ng till key events fr�n motorn.
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
	//getter och setter till team som g�r det m�jligt att ha olika beteenden i akt beroende p� vilket team dom tillh�r snarare �n klass.
	int getTeam(){ return team; }
	void setTeam(int newTeam){ team = newTeam; }

	~Actor();
private:
	int team = 0;
	
};
#endif