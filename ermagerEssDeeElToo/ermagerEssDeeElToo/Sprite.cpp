#include "GameEngine.h"


Sprite::Sprite()
{
}
Sprite::Sprite(int posX, int posY, int textureHeight, int textureWidth)
{
	X = posX;
	Y = posY;
	sizeX = textureHeight;
	sizeY = textureWidth;
	dimension.x = 0;
	dimension.y = 0;
	dimension.w = textureHeight;
	dimension.h = textureWidth;

	position.x = X;
	position.y = Y;
	position.w = textureHeight;
	position.h = textureWidth;
	
}


Sprite::~Sprite()
{
}

void Sprite::draw(SDL_Renderer *renderer)
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
SDL_Rect Sprite::getDimension()
{
	return dimension;
};
SDL_Rect Sprite::getPosition()
{
	position.x = X;
	position.y = Y;
	position.w = sizeX;
	position.h = sizeY;
	return position;
};





