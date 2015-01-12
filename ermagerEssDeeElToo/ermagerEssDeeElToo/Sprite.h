#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
//#include "GameEngine.h"
class Sprite
{
public:
	Sprite();
	Sprite(int posX, int posY, int textureHeight, int textureWidth);
	~Sprite();
	void draw(SDL_Renderer *renderer);
	SDL_Rect getTextureSize();
	SDL_Rect getTexturePosition();
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	SDL_Rect getDimension();
	SDL_Rect Sprite::getPosition();
	
	
	
	
private:
	int X = 0;
	int Y = 0;
	int sizeX = 64;
	int sizeY = 64;
	SDL_Rect dimension;
	SDL_Rect position;
	SDL_Texture *spriteTexture = NULL;

	bool once = false;
};

#endif