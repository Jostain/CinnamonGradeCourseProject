#pragma once
#include "Main.h"
#include <iostream>
#include <SDL.h>
#include "Sprite.h"
#include "Actor.h"
class GameEngine
{
public:
	GameEngine(const char* title, int height, int width);
	~GameEngine();
	void run();
	void setBackground(std::string);
	void add(Sprite* sprite);
	void add(Actor* actor);
	bool intersect(SDL_Rect);
	void update();
};


