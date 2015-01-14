#include "Sprite.h"
#include <iostream>
int Sprite::objectCount = 0;//statisk variabel som avänds för att ge ett unikt id till alla sprites som skapas för att sedan kunna användas för identifikation i olika metoder.
Sprite::Sprite(int posX, int posY, int textureHeight, int textureWidth)
{
	id = objectCount;//tilldelar Sprite ett unikt id.
	objectCount++;//ökar objectCount för att nästa Sprite skall vara unik
	X = posX; 
	Y = posY;
	
	//sätter storleken på Sprite
	sizeX = textureHeight;
	sizeY = textureWidth;
	position.w = textureHeight;
	position.h = textureWidth;
	
}
Sprite::~Sprite()//standard destruktor
{
}

/**/
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
	return position;
};





