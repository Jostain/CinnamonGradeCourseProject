#include "GameEngine.h"
#include "Mob.h"
#include "Player.h"
#include "Bullet.h"

//I've been held captive - Please send help ASAP! SOS!

int main(int argc, char** argv){
	
	GameEngine* GE = new GameEngine("Test", 800, 600);
	GE->setBackground("c:/images/BG.bmp");
	GE->setSpriteSheet("c:/images/test.png");
	
	Player* player = new Player(0, 0, 32, 32);
	Mob* mob2 = new Mob(32,32);
	Mob* mob3 = new Mob(64, 64);
	Mob* mob4 = new Mob(96, 96);
	Mob* mob5 = new Mob(128, 128);
	Mob* mob6 = new Mob(320, 320);
	Mob* mob7 = new Mob(160, 160);
	Bullet* bullet = new Bullet(32, 0, 32, 32);
	//Sprite* sprite = new Sprite(posX, posY, texturePosX, texturePosY, "c:/images/test.bmp");
	

	GE->add(player, GE);
	GE->add(mob2,GE);
	GE->add(mob3, GE);
	GE->add(mob4,GE);
	GE->add(mob5,GE);
	GE->add(mob6, GE);
	GE->add(bullet, GE);
	
	
	GE->run();
	
	delete GE;
	return 0;
}
