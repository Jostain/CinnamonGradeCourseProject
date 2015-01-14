#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
/*Det object som alla actors sedan baseras på. endast en sprite kan användas som en dekal men kan inte interageras med på något sätt i motorn*/

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
	SDL_Rect Sprite::getSprite(){return sprite;}
	SDL_Rect getPosition();
	void setSprite(int, int, int, int);
	int getID(){ return id; }
	int getNextID(){ objectCount; }
	
	
	
	
private:
	int id; //unikt id för denna sprite
	int X; //sprites position i x led
	int Y; //sprites position i y led
	int sizeX; //sprites storlek i y led
	int sizeY; //sprites storlek i y led
	SDL_Rect sprite; //returnerar en Rect som beskriver Sprites storkel och position i spritesheet
	SDL_Rect position; //returnerar en Rect som beskriver Sprites position i spelet.


};

#endif