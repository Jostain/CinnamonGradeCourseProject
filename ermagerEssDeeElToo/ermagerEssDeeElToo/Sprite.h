#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
//#include "GameEngine.h"
class Sprite
{
public:
	static int objectCount;//statisk variabel som avänds för att ge ett unikt id till alla sprites som skapas för att sedan kunna användas för identifikation i olika metoder.
	
	Sprite(int, int, int, int);//tilldelar Sprite ett unikt id.
	~Sprite();//standard destruktor

	//getters och setters
	int Sprite::getX(){ return X; }
	int Sprite::getY(){ return Y; }
	void Sprite::setX(int x){ X = x; }
	void Sprite::setY(int y){ Y = y; }
	SDL_Rect getSprite();
	SDL_Rect getPosition();
	void setSprite(int, int, int, int);
	int getID(){ return id; }
	int getNextID(){ objectCount; }
	
	
	
	
private:
	int id;
	int X;
	int Y;
	int sizeX;
	int sizeY;
	SDL_Rect sprite;
	SDL_Rect position;
	bool once = false;

};

#endif