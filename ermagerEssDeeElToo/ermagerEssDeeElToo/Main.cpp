#include "GameEngine.h"
#include "Mob.h"

//I've been held captive - Please send help ASAP! SOS!

int main(int argc, char** argv){
	
	GameEngine* gameEngine = new GameEngine("Test", 800, 600);
	gameEngine->setBackground("c:/images/BG.bmp");
	
	Mob* mob = new Mob(32, 32, 32, 32,"c:/images/test.bmp");
	Mob* mob2 = new Mob(64, 64, 64, 64, "c:/images/test.bmp");
	//Sprite* sprite = new Sprite(posX, posY, texturePosX, texturePosY, "c:/images/test.bmp");
	
	gameEngine->add(mob);
	gameEngine->add(mob2);
	//remove middle one
	gameEngine->run();
	
	delete gameEngine;
	return 0;
}
