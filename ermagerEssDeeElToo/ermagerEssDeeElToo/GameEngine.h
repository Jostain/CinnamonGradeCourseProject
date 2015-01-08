#pragma once
#include "Main.h"
#include <iostream>
#include <SDL.h>
#include "Sprite.h"
#include "Actor.h"
#include <SDL_ttf.h>
class GameEngine
{
public:
	GameEngine(const char* title, int height, int width);

	~GameEngine();
	void run();
	std::string convertInt(int number);
	void setBackground(std::string);
	void setSpriteSheet(std::string path);
	void add(Sprite* sprite);
	void add(Actor* actor);
	void actions();
	bool intersect(SDL_Rect);
	void update();
};


