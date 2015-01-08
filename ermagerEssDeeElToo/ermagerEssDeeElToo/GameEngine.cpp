#include "GameEngine.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <string>






SDL_Window *window        = NULL;
SDL_Renderer *renderer    = NULL;
SDL_Texture *Background_texture = NULL;
SDL_Texture *spriteSheet_texture = NULL;
SDL_Texture *FPStexture = NULL;
TTF_Font *FPSFont = NULL;
SDL_Color FPSColor = { 0, 0, 0 };
std::vector<Sprite*> spriteVector;
std::vector<Actor*> actorVector;
int FPS;


GameEngine::GameEngine(const char* title, int height, int width)
{
	if (TTF_Init() != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}
	// Innan vi använder biblioteket så måste det initialiseras.
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		SDL_DestroyWindow(window);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	FPSFont = TTF_OpenFont("c:/images/dirtyheadline.ttf", 128);
}
void GameEngine::add(Sprite* sprite)
{
	spriteVector.push_back(sprite);
}
void GameEngine::add(Actor* actor)
{
	actorVector.push_back(actor);
	spriteVector.push_back(actor);
}

void GameEngine::actions()
{
	int nextActor = 0;
	while (nextActor < actorVector.size())
	{
		actorVector[nextActor]->act();
		nextActor++;
	}
}
void GameEngine::update()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, Background_texture, NULL, NULL);
	SDL_Rect dimension;
	SDL_Rect position;
	dimension.x = 0;
	dimension.y = 0;
	dimension.w = 32;
	dimension.h = 32;

	//position.x = X;
	//position.y = Y;
	//position.w = textureHeight;
	//position.h = textureWidth;
	std::string FPS_string = static_cast<std::ostringstream*>(&(std::ostringstream() << FPS))->str();
	SDL_Surface* FPSSurface = TTF_RenderText_Solid(FPSFont, FPS_string.c_str(), FPSColor);//<--Exception
	FPStexture = SDL_CreateTextureFromSurface(renderer, FPSSurface);
	SDL_FreeSurface(FPSSurface);
	SDL_RenderCopy(renderer, FPStexture, NULL, &dimension);
	SDL_DestroyTexture(FPStexture);

	int nextSprite = 0;
	while (nextSprite < spriteVector.size())
	{	
		SDL_RenderCopy(renderer, spriteSheet_texture, &spriteVector[nextSprite]->getDimension(), &spriteVector[nextSprite]->getPosition());
		nextSprite++;
	}
	SDL_RenderPresent(renderer);

}
void GameEngine::run()
{	
	int frame = 0;
	bool program_is_running = true;
	while (program_is_running)
	{
		int begining = SDL_GetTicks();
		SDL_Event event;	// Skapa en händelselyssnare
		while (SDL_PollEvent(&event))	// Hämtar nästa event i event-kön, annars returneras 0.
		{
			
			switch (event.type) {
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
					program_is_running = false;
				break;
			case SDL_QUIT:
				program_is_running = false;
				break;
			}
		}
		actions();
		update();
		
		int tick = SDL_GetTicks() - begining;
		
		while (tick < 33)
		{
			tick = SDL_GetTicks() - begining;
		}
		frame++;
		if (frame = 30)
		{
			FPS = SDL_GetTicks() - begining;
			frame = 0;
		}
		
		
	}
}
void GameEngine::setBackground(std::string path)
{
	std::string imagePath = path;
	SDL_Surface *bmp_surface = SDL_LoadBMP(imagePath.c_str());
	Background_texture = SDL_CreateTextureFromSurface(renderer, bmp_surface);
	SDL_FreeSurface(bmp_surface);
}
void GameEngine::setSpriteSheet(std::string path)
{
	std::string imagePath = path;
	SDL_Surface *bmp_surface = SDL_LoadBMP(imagePath.c_str());
	spriteSheet_texture = SDL_CreateTextureFromSurface(renderer, bmp_surface);
	SDL_FreeSurface(bmp_surface);
}

std::string convertInt(int number)
{
	std::stringstream ss;//create a stringstream
	ss << number;//add number to the stream
	return ss.str();//return a string with the contents of the stream
}
GameEngine::~GameEngine()

{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
