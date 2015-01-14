#include "GameEngine.h"
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "Actor.h"





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
	// Innan vi anv�nder biblioteket s� m�ste det initialiseras.
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

void GameEngine::add(Sprite* sprite, GameEngine* GE)
{
	spriteVector.push_back(sprite);
}
void GameEngine::add(Actor* actor, GameEngine* GE)
{
	actor->connectToEngine(GE);
	actorVector.push_back(actor);
	spriteVector.push_back(actor);
}
void GameEngine::removeSprite(int sprite)
{
	int nextSprite = 0;
	while (nextSprite < actorVector.size())
	{
		std::cout << sprite << std::endl;
		if (spriteVector[nextSprite]->getID() == sprite)
			spriteVector.erase(spriteVector.begin() + nextSprite);
			
		break;
	}
}
void GameEngine::removeActor(int actor)
{
	int nextActor = 0;
	while (nextActor < actorVector.size())
	{
		std::cout << "test1" << std::endl;
		if (spriteVector[nextActor]->getID() == actor){
			
			actorVector.erase(actorVector.begin() + nextActor);
		
		if (spriteVector[nextActor]->getID() == actor)
			std::cout << "test2" << std::endl;
		spriteVector.erase(spriteVector.begin() + nextActor);

			break;
		}
	}

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
		SDL_RenderCopy(renderer, spriteSheet_texture, &spriteVector[nextSprite]->getSprite(), &spriteVector[nextSprite]->getPosition());
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
		SDL_Event event;	// Skapa en h�ndelselyssnare
		while (SDL_PollEvent(&event))	// H�mtar n�sta event i event-k�n, annars returneras 0.
		{
			
			switch (event.type) {

			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
					//program_is_running = false;
				break;
				if (event.key.keysym.sym == SDLK_UP)
					up = true;
				//break;
				if (event.key.keysym.sym == SDLK_DOWN)
					down = true;
				//break;
				if (event.key.keysym.sym == SDLK_RIGHT)
					right = true;
				//break;
				if (event.key.keysym.sym == SDLK_LEFT)
					left = true;
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_ESCAPE)
					//program_is_running = false;
					break;
				if (event.key.keysym.sym == SDLK_UP)
					up = false;
				//break;
				if (event.key.keysym.sym == SDLK_DOWN)
					down = false;
				//break;
				if (event.key.keysym.sym == SDLK_RIGHT)
					right = false;
				//break;
				if (event.key.keysym.sym == SDLK_LEFT)
					left = false;
				break;
			case SDL_QUIT:
				program_is_running = false;
				break;
			}
		}
		
		actions();// act metod hos alla actors
		update();//m�la ut alla sprites som finns
		
		
		//Frames Per Second kontroll.
		int tick = SDL_GetTicks() - begining;//felstavat
		
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
		
		if (endRun == true)
		{ 
			program_is_running = false; 
		}
			
	}
}
void GameEngine::setBackground(std::string path)
{
	std::string imagePath = path;
	SDL_Surface *bmp_surface = IMG_Load(imagePath.c_str());
	Background_texture = SDL_CreateTextureFromSurface(renderer, bmp_surface);
	SDL_FreeSurface(bmp_surface);
}
void GameEngine::setSpriteSheet(std::string path)
{
	std::string imagePath = path;
	SDL_Surface *bmp_surface = IMG_Load(imagePath.c_str());
	spriteSheet_texture = SDL_CreateTextureFromSurface(renderer, bmp_surface);

	SDL_FreeSurface(bmp_surface);
}

std::string convertInt(int number)
{
	std::stringstream ss;//create a stringstream
	ss << number;//add number to the stream
	return ss.str();//return a string with the contents of the stream
}
std::vector<Actor*> GameEngine::intersections(SDL_Rect sprite)
{
	std::vector<Actor*> intesectionsVector;
	int nextActor = 0;
	while (nextActor < actorVector.size())
	{
		SDL_Rect position = actorVector[nextActor]->getPosition();
		if (intersect(sprite, position))
		{
			intesectionsVector.push_back(actorVector[nextActor]);
		}
		nextActor++;
	}
	return intesectionsVector;
}
bool GameEngine::intersect(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;

	std::vector<Actor*> intersectVector; 
}
GameEngine::~GameEngine()

{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
