#pragma once
#include "GameEngine.h"
class Sprite
{
public:
	Sprite();
	Sprite(int posX, int posY, int textureHeight, int textureWidth, std::string path);
	~Sprite();
	void draw(SDL_Renderer *renderer);
	SDL_Rect getTextureSize();
	SDL_Rect getTexturePosition();
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	
	
	
	
private:
	int X = 0;
	int Y = 0;
	std::string imagePath;
	int sizeX = 64;
	int sizeY = 64;
	SDL_Rect SrcR;
	SDL_Rect DestR;
	SDL_Texture *spriteTexture = NULL;

	bool once = false;
};

