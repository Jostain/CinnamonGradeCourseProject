#include "GameEngine.h"
#include "Mob.h"

//I've been held captive - Please send help ASAP! SOS!

int main(int argc, char** argv){
	
	GameEngine* gameEngine = new GameEngine("Test", 800, 600);
	gameEngine->setBackground("c:/images/BG.bmp");
	
	Mob* mob = new Mob(32, 32, 32, 32,"c:/images/test.bmp");
	Mob* mob2 = new Mob(65, 64, 64, 64, "c:/images/test.bmp");
	Mob* mob3 = new Mob(66, 64, 64, 64, "c:/images/test.bmp");
	Mob* mob4 = new Mob(67, 64, 64, 64, "c:/images/test.bmp");
	Mob* mob5 = new Mob(68, 64, 64, 64, "c:/images/test.bmp");
	Mob* mob6 = new Mob(69, 64, 64, 64, "c:/images/test.bmp");
	Mob* mob7 = new Mob(70, 64, 64, 64, "c:/images/test.bmp");
	Mob* mob8 = new Mob(71, 64, 64, 64, "c:/images/test.bmp");
	Mob* mob9 = new Mob(72, 64, 64, 64, "c:/images/test.bmp");
	Mob* mob10 = new Mob(73, 64, 64, 64, "c:/images/test.bmp");
	Mob* mob11 = new Mob(74, 64, 64, 64, "c:/images/test.bmp");
	//Sprite* sprite = new Sprite(posX, posY, texturePosX, texturePosY, "c:/images/test.bmp");
	
	gameEngine->add(mob);
	gameEngine->add(mob2);
	gameEngine->add(mob3);
	gameEngine->add(mob4);
	gameEngine->add(mob5);
	gameEngine->add(mob6);
	gameEngine->add(mob7);
	gameEngine->add(mob8);
	gameEngine->add(mob9);
	gameEngine->add(mob10);
	gameEngine->add(mob11);
	//remove middle one
	gameEngine->run();
	
	delete gameEngine;
	return 0;
}
