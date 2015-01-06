#pragma once
#include "GameEngine.h"
class Sprite
{
public:
	Sprite();
	Sprite(int posX, int posY, int textureHeight, int textureWidth, std::string path);
	~Sprite();
	SDL_Surface* draw();
	SDL_Rect getTextureSize();
	SDL_Rect getTexturePosition();
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	
	
	
	
private:
	int X = 0;
	int Y = 0;
	std::string imagePath = "c:/images/test.bmp";
	int sizeX = 64;
	int sizeY = 64;
	SDL_Rect SrcR;
	SDL_Rect DestR;
};

