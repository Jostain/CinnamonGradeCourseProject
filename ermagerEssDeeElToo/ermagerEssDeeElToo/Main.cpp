#include "GameEngine.h"
#include "Mob.h"
#include "Player.h"
#include "Player2.h"
#include "Bullet.h"



int main(int argc, char** argv){
	
	GameEngine* GE = new GameEngine("PewPew", 800, 600);
	GE->setBackground("BG.bmp");
	GE->setSpriteSheet("spriteSheet.png");
	
	Player* player = new Player(10, 300);
	Player2* player2 = new Player2(758, 300);
	Mob* mob = new Mob(300, 300);
	

	GE->add(player, GE);
	GE->add(player2, GE);
	GE->add(mob, GE);
	
	
	GE->run();
	
	delete GE;
	return 0;
}
