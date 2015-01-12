#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
class Sprite;
class Actor;
class GameEngine
{
public:
	GameEngine(const char* title, int height, int width);

	~GameEngine();
	void run();
	std::string convertInt(int number);
	void setBackground(std::string);
	void setSpriteSheet(std::string path);
	void add(Sprite* sprite, GameEngine* GE);
	void add(Actor* actor, GameEngine* GE);
	void actions();
	bool intersect(SDL_Rect);
	void update();
	int getMouseX();//needs implementation
	int getMouseY();//needs implementation
	std::vector<Actor*> intersect(GameEngine* gameEngine);//needs implementation
	bool getUp(){ return up; }
	bool getDown(){ return down; }
	bool getRight(){ return right; }
	bool getLeft(){ return left; }
private:
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;

};


#endif