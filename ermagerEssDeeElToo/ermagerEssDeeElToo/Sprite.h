#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
//#include "GameEngine.h"
class Sprite
{
public:
	static int objectCount;
	Sprite();
	Sprite(int, int, int, int textureWidth);
	~Sprite();
	void draw(SDL_Renderer *renderer);
	SDL_Rect getTextureSize();
	SDL_Rect getTexturePosition();
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	SDL_Rect getSprite();
	SDL_Rect getPosition();
	void setSprite(int, int, int, int);
	int getID(){ return id; }
	int getNextID(){ objectCount; }
	
	
	
	
private:
	int id = 0;
	int X = 0;
	int Y = 0;
	int sizeX = 64;
	int sizeY = 64;
	SDL_Rect sprite;
	SDL_Rect position;
	SDL_Texture *spriteTexture = NULL;

	bool once = false;
};

#endif