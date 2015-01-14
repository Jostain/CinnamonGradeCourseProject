#include "GameEngine.h"
#include "Mob.h"
#include "Player.h"
#include "Player2.h"
#include "Bullet.h"

//I've been held captive - Please send help ASAP! SOS!

int main(int argc, char** argv){
	
	GameEngine* GE = new GameEngine("Test", 800, 600);
	GE->setBackground("BG.bmp");
	GE->setSpriteSheet("test.png");
	
	Player* player = new Player(10, 300);
	Player2* player2 = new Player2(758, 300);
	

	GE->add(player, GE);
	GE->add(player2, GE);
	
	
	GE->run();
	
	delete GE;
	return 0;
}
