#include "GameEngine.h"
#include "Mob.h"

//I've been held captive - Please send help ASAP! SOS!

int main(int argc, char** argv){
	
	GameEngine* GE = new GameEngine("Test", 800, 600);
	GE->setBackground("c:/images/BG.bmp");
	GE->setSpriteSheet("c:/images/test.bmp");
	
	Mob* mob = new Mob(0, 0, 32, 32);
	Mob* mob2 = new Mob(65, 64, 64, 64);
	Mob* mob3 = new Mob(66, 64, 64, 64);
	Mob* mob4 = new Mob(67, 64, 64, 64);
	Mob* mob5 = new Mob(68, 64, 64, 64);
	Mob* mob6 = new Mob(69, 64, 64, 64);
	Mob* mob7 = new Mob(70, 64, 64, 64);
	Mob* mob8 = new Mob(71, 64, 64, 64);
	Mob* mob9 = new Mob(72, 64, 64, 64);
	Mob* mob10 = new Mob(73, 64, 64, 64);
	Mob* mob11 = new Mob(74, 64, 64, 64);
	Mob* mob12 = new Mob(74, 64, 64, 64);
	Mob* mob13 = new Mob(74, 64, 64, 64);
	Mob* mob14 = new Mob(74, 64, 64, 64);
	Mob* mob15 = new Mob(74, 64, 64, 64);
	Mob* mob16 = new Mob(74, 64, 64, 64);
	Mob* mob17 = new Mob(74, 64, 64, 64);
	Mob* mob18 = new Mob(74, 64, 64, 64);
	Mob* mob19 = new Mob(74, 64, 64, 64);
	Mob* mob20 = new Mob(74, 64, 64, 64);
	Mob* mob21 = new Mob(74, 64, 64, 64);
	Mob* mob22 = new Mob(74, 64, 64, 64);
	Mob* mob23 = new Mob(74, 64, 64, 64);
	Mob* mob24 = new Mob(74, 64, 64, 64);
	Mob* mob25 = new Mob(74, 64, 64, 64);
	//Sprite* sprite = new Sprite(posX, posY, texturePosX, texturePosY, "c:/images/test.bmp");
	
	GE->add(mob);
	GE->add(mob2);
	GE->add(mob3);
	GE->add(mob4);
	GE->add(mob5);
	GE->add(mob6);
	
	//remove middle one
	GE->run();
	
	delete GE;
	return 0;
}
