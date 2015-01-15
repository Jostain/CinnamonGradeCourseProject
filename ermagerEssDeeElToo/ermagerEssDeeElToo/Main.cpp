#include "GameEngine.h"
#include "Mob.h"
#include "Player.h"
#include "Bullet.h"



int main(int argc, char** argv){
	
	GameEngine* GE = new GameEngine("PewPew", 800, 600);//skapa motor
	GE->setBackground("BG.bmp");//definiera en bakgrund
	GE->setSpriteSheet("spriteSheet.png");//definiera ett spriteSheet
	
	Player* player = new Player(10, 300,0);//skapa player 1
	Player* player2 = new Player(758, 300,1);//skapa player 2
	Mob* mob = new Mob(300, 300);//skapa mob
	
	//lägg till samtliga i motorn
	GE->add(player, GE);
	GE->add(player2, GE);
	GE->add(mob, GE);
	
	//kör spelet
	GE->run();
	
	delete GE;
	return 0;
}
