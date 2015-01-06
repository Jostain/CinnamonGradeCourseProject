#include "GameEngine.h"


int main(int argc, char** argv){
	
	GameEngine* gameEngine = new GameEngine("Test", 800, 600);
	gameEngine->setBackground("c:/images/BG.bmp");
	
	Sprite* sprite = new Sprite(64, 64, 64, 64,"c:/images/test.bmp");
	Sprite* sprite2 = new Sprite(32, 32, 32, 32, "c:/images/test.bmp");
	//Sprite* sprite = new Sprite(posX, posY, texturePosX, texturePosY, "c:/images/test.bmp");
	
	gameEngine->add(sprite);
	gameEngine->add(sprite2);
	//remove middle one
	gameEngine->run();
	
	delete gameEngine;
	return 0;
}
