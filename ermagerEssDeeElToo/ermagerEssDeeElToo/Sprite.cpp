#include "Sprite.h"
#include <iostream>

/*Det object som alla actors sedan baseras på. endast en sprite kan användas som en dekal men kan inte interageras med på något sätt i motorn*/

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
//standard destruktor
Sprite::~Sprite()
{
}
/*sätter formen på spriten och vart på sprite sheetet som texturen skall hämtas där x och y är storlek och posX och posY är texturen position*/
void Sprite::setSprite(int x, int y, int posX, int posY)
{
	sprite.x = x;
	sprite.y = y;
	sprite.w = posX;
	sprite.h = posY;
}
/*returnerar en rect som beskriver vart en sprite skall målas på skärmen*/
SDL_Rect Sprite::getPosition()
{
	position.x = X;
	position.y = Y;
	return position;
};





