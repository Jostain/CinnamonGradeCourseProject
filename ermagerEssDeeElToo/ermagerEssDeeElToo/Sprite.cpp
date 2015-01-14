#include "Sprite.h"
#include <iostream>

/*Det object som alla actors sedan baseras p�. endast en sprite kan anv�ndas som en dekal men kan inte interageras med p� n�got s�tt i motorn*/

int Sprite::objectCount = 0;//statisk variabel som av�nds f�r att ge ett unikt id till alla sprites som skapas f�r att sedan kunna anv�ndas f�r identifikation i olika metoder.
Sprite::Sprite(int posX, int posY, int textureHeight, int textureWidth)
{
	id = objectCount;//tilldelar Sprite ett unikt id.
	objectCount++;//�kar objectCount f�r att n�sta Sprite skall vara unik
	X = posX; 
	Y = posY;
	
	//s�tter storleken p� Sprite
	sizeX = textureHeight;
	sizeY = textureWidth;
	position.w = textureHeight;
	position.h = textureWidth;
	
}
//standard destruktor
Sprite::~Sprite()
{
}
/*s�tter formen p� spriten och vart p� sprite sheetet som texturen skall h�mtas d�r x och y �r storlek och posX och posY �r texturen position*/
void Sprite::setSprite(int x, int y, int posX, int posY)
{
	sprite.x = x;
	sprite.y = y;
	sprite.w = posX;
	sprite.h = posY;
}
/*returnerar en rect som beskriver vart en sprite skall m�las p� sk�rmen*/
SDL_Rect Sprite::getPosition()
{
	position.x = X;
	position.y = Y;
	return position;
};





