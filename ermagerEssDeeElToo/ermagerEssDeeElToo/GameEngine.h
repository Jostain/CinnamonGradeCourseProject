#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <vector>
class Sprite;
class Actor;
class GameEngine
{
	/**/
public:
	GameEngine(const char* title, int height, int width);//initierar alla bibliotek som krävs för att köra programmet
	void add(Sprite* sprite, GameEngine* GE);//lägger till en Sprite till motorn så att dom ritas ut
	void add(Actor* actor, GameEngine* GE);//lägger till en Actor så att den ritas och kan agera(act())
	void removeSprite(int);//tar bort sprite från motorn så att den inte längre målas ut.
	void removeActor(int); //tar bort Actor från motorn så att den inte längre behandlas av motorn 
	void actions();//utför act() på alla Actors som finns i motorn
	void update();//målar ut alla sprites och actors som finns i motorn
	void run();//startar motorns loop
	void setBackground(std::string); //sätter en backgrund enligt en filväg
	void setSpriteSheet(std::string path);//sätter ett spriteSheet enligt en filväg
	std::string convertInt(int number); //hjälpmetod för att konvertera en int till en string

	
	void end(){ endRun = true; } //kan kallas om en Actor vill avsluta programmet
	
	std::vector<Actor*> intersections(SDL_Rect);//returnerar en vector med alla actors som krockar med en angiven SDL_Rect
	bool intersect(SDL_Rect a, SDL_Rect b);//hjälp metod till intersections och svarar på om en Rect krockar med en annan Rect
	~GameEngine();//avslutar motorn

	//metoder som ger actor tillgång till key events
	bool getUp(){ return up; }
	bool getDown(){ return down; }
	bool getRight(){ return right; }
	bool getLeft(){ return left; }
	bool getSpace(){ return space; }
	bool getW(){ return W; }
	bool getS(){ return S; }
	bool getD(){ return D; }
	bool getA(){ return A; }
	bool getZero(){ return zero; }


private:

	//booleans som anger om en viss tangent tryckts
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	bool zero = false;
	bool Enter = false;
	bool W = false;
	bool S = false;
	bool A = false;
	bool D = false;
	bool space = false;
	bool E = false;

	//ger actors möjlighet att avsluta loopen
	bool endRun = false;

};


#endif