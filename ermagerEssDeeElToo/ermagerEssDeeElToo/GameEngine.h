#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
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
	void removeSprite(int);
	void removeActor(int);
	void actions();
	void update();
	void end(){ endRun = true; }
	
	std::vector<Actor*> intersections(SDL_Rect);//needs implementation
	
	bool intersect(SDL_Rect a, SDL_Rect b);
	bool getUp(){ return up; }
	bool getDown(){ return down; }
	bool getRight(){ return right; }
	bool getLeft(){ return left; }
private:
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	bool endRun = false;

};


#endif