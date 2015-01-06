#include "GameEngine.h"


Sprite::Sprite()
{
}
Sprite::Sprite(int posX, int posY, int textureHeight, int textureWidth, std::string path)
{
	X = posX;
	Y = posY;
	imagePath = path;
	sizeX = textureHeight;
	sizeY = textureWidth;
	SrcR.x = 0;
	SrcR.y = 0;
	SrcR.w = textureHeight;
	SrcR.h = textureWidth;

	DestR.x = X;
	DestR.y = Y;
	DestR.w = textureHeight;
	DestR.h = textureWidth;
}


Sprite::~Sprite()
{
}

SDL_Surface* Sprite::draw()
{
	DestR.x = X;
	DestR.y = Y;
	DestR.w = sizeX;
	DestR.h = sizeY;
	SDL_Surface *bmp_surface = SDL_LoadBMP(imagePath.c_str());
	return bmp_surface;
}
SDL_Rect Sprite::getTextureSize()
{
	return SrcR;
}
SDL_Rect Sprite::getTexturePosition()
{
	return  DestR;
}
int Sprite::getX()
{ 	
	return X;
};
int Sprite::getY()
{
	return Y;
};
void Sprite::setX(int x)
{
	X= x;
};
void Sprite::setY(int y)
{
	Y = y;
};




