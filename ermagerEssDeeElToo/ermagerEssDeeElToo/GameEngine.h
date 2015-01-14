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
	GameEngine(const char* title, int height, int width);//initierar alla bibliotek som kr�vs f�r att k�ra programmet
	void add(Sprite* sprite, GameEngine* GE);//l�gger till en Sprite till motorn s� att dom ritas ut
	void add(Actor* actor, GameEngine* GE);//l�gger till en Actor s� att den ritas och kan agera(act())
	void removeSprite(int);//tar bort sprite fr�n motorn s� att den inte l�ngre m�las ut.
	void removeActor(int); //tar bort Actor fr�n motorn s� att den inte l�ngre behandlas av motorn 
	void actions();//utf�r act() p� alla Actors som finns i motorn
	void update();//m�lar ut alla sprites och actors som finns i motorn
	void run();//startar motorns loop
	void setBackground(std::string); //s�tter en backgrund enligt en filv�g
	void setSpriteSheet(std::string path);//s�tter ett spriteSheet enligt en filv�g
	std::string convertInt(int number); //hj�lpmetod f�r att konvertera en int till en string

	
	void end(){ endRun = true; } //kan kallas om en Actor vill avsluta programmet
	
	std::vector<Actor*> intersections(SDL_Rect);//returnerar en vector med alla actors som krockar med en angiven SDL_Rect
	bool intersect(SDL_Rect a, SDL_Rect b);//hj�lp metod till intersections och svarar p� om en Rect krockar med en annan Rect
	~GameEngine();//avslutar motorn

	//metoder som ger actor tillg�ng till key events
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

	//ger actors m�jlighet att avsluta loopen
	bool endRun = false;

};


#endif