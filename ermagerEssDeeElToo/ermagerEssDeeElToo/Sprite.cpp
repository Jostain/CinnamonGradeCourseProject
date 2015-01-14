#include "Sprite.h"
#include <iostream>
int Sprite::objectCount = 0;
Sprite::Sprite()
{
	
}
Sprite::Sprite(int posX, int posY, int textureHeight, int textureWidth)
{
	std::cout << objectCount;
	id = objectCount;
	objectCount++;
	X = posX;
	Y = posY;
	sizeX = textureHeight;
	sizeY = textureWidth;
	sprite.x = 0;
	sprite.y = 0;
	sprite.w = textureHeight;
	sprite.h = textureWidth;

	position.x = X;
	position.y = Y;
	position.w = textureHeight;
	position.h = textureWidth;
	
}


Sprite::~Sprite()
{
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
void Sprite::setSprite(int x, int y, int posX, int posY)
{
	sprite.x = x;
	sprite.y = y;
	sprite.w = posX;
	sprite.h = posY;
}
SDL_Rect Sprite::getSprite()
{
	return sprite;
};
SDL_Rect Sprite::getPosition()
{
	position.x = X;
	position.y = Y;
	position.w = sizeX;
	position.h = sizeY;
	return position;
};





