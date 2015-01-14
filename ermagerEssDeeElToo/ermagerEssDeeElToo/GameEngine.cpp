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
SDL_Color FPSColor = { 7, 7, 7 };
std::vector<Sprite*> spriteVector;
std::vector<Actor*> actorVector;
int FPS;

/*initierar alla bibliotek som krävs för att köra programmet*/
GameEngine::GameEngine(const char* title, int height, int width)
{
	if (TTF_Init() != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}
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
	FPSFont = TTF_OpenFont("dirtyheadline.ttf", 128);
}
/*lägger till en Sprite till motorn så att dom ritas ut*/
void GameEngine::add(Sprite* sprite, GameEngine* GE)
{
	spriteVector.push_back(sprite);
}
/*lägger till en Actor så att den ritas och kan agera(act())*/
void GameEngine::add(Actor* actor, GameEngine* GE)
{
	actor->connectToEngine(GE);
	actorVector.push_back(actor);
	spriteVector.push_back(actor);
}
/*tar bort sprite från motorn så att den inte längre målas ut.*/
void GameEngine::removeSprite(int sprite)
{
	int nextSprite = 0;
	while (nextSprite < actorVector.size())
	{
			if (spriteVector[nextSprite]->getID() == sprite)

				spriteVector.erase(spriteVector.begin() + nextSprite);

		}
		nextSprite++;
	}
/*tar bort Actor från motorn så att den inte längre behandlas av motorn */
void GameEngine::removeActor(int actor)
{
	int nextActor = 0;
	while (nextActor < actorVector.size())
	{
		std::cout << nextActor << std::endl;
		if (spriteVector[nextActor]->getID() == actor){
			
			actorVector.erase(actorVector.begin() + nextActor);
		
		if (spriteVector[nextActor]->getID() == actor)
			
		spriteVector.erase(spriteVector.begin() + nextActor);

		}
		nextActor++;
	}

}
/*/utför act() på alla Actors som finns i motorn*/
void GameEngine::actions()
{
	int nextActor = 0;
	while (nextActor < actorVector.size())
	{
		actorVector[nextActor]->act();
		nextActor++;
	}
}
/*målar ut alla sprites och actors som finns i motorn*/
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

	
	std::string FPS_string = static_cast<std::ostringstream*>(&(std::ostringstream() << FPS))->str();
	SDL_Surface* FPSSurface = TTF_RenderText_Solid(FPSFont, FPS_string.c_str(), FPSColor);
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
/*startar motorns loop*/
void GameEngine::run()
{	
	int frame = 0;
	bool program_is_running = true;
	while (program_is_running)
	{
		int beginning = SDL_GetTicks();
		SDL_Event event;
		while (SDL_PollEvent(&event))	// Hämtar nästa event i event-kön
		{
			
			switch (event.type) {

			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
					
				break;
				if (event.key.keysym.sym == SDLK_w)
					W = true;
				if (event.key.keysym.sym == SDLK_s)
					S = true;
				if (event.key.keysym.sym == SDLK_a)
					A = true;
				if (event.key.keysym.sym == SDLK_d)
					D = true;
				if (event.key.keysym.sym == SDLK_KP_0)
					zero = true;
				if (event.key.keysym.sym == SDLK_SPACE)
					space = true;
				if (event.key.keysym.sym == SDLK_UP)
					up = true;
				
				if (event.key.keysym.sym == SDLK_DOWN)
					down = true;
				
				if (event.key.keysym.sym == SDLK_RIGHT)
					right = true;
				
				if (event.key.keysym.sym == SDLK_LEFT)
					left = true;
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_w)
					W = false;
				if (event.key.keysym.sym == SDLK_s)
					S = false;
				if (event.key.keysym.sym == SDLK_a)
					A = false;
				if (event.key.keysym.sym == SDLK_d)
					D = false;
				if (event.key.keysym.sym == SDLK_KP_0)
					zero = false;
				if (event.key.keysym.sym == SDLK_SPACE)
					space = false;
				if (event.key.keysym.sym == SDLK_ESCAPE)
					break;
				if (event.key.keysym.sym == SDLK_UP)
					up = false;
				if (event.key.keysym.sym == SDLK_DOWN)
					down = false;
				if (event.key.keysym.sym == SDLK_RIGHT)
					right = false;
				if (event.key.keysym.sym == SDLK_LEFT)
					left = false;
				break;
			case SDL_QUIT:
				program_is_running = false;
				break;
			}
		}
		
		actions();// act metod hos alla actors
		update();//måla ut alla sprites som finns
		
		
		//Frames Per Second kontroll.
		int tick = SDL_GetTicks() - beginning;
		
		while (tick < 33)
		{
			tick = SDL_GetTicks() - beginning;
		}
		frame++;
		if (frame = 30)
		{
			FPS = SDL_GetTicks() - beginning;
			frame = 0;
		}
		
		//om någon actor har begärt att programmet avslutas så avslutas loopen
		if (endRun == true)
		{ 
			program_is_running = false; 
		}
			
	}
}
/*sätter en backgrund enligt en filväg*/
void GameEngine::setBackground(std::string path)
{
	std::string imagePath = path;
	SDL_Surface *bmp_surface = IMG_Load(imagePath.c_str());
	Background_texture = SDL_CreateTextureFromSurface(renderer, bmp_surface);
	SDL_FreeSurface(bmp_surface);
}
/*sätter ett spriteSheet enligt en filväg*/
void GameEngine::setSpriteSheet(std::string path)
{
	std::string imagePath = path;
	SDL_Surface *bmp_surface = IMG_Load(imagePath.c_str());
	spriteSheet_texture = SDL_CreateTextureFromSurface(renderer, bmp_surface);

	SDL_FreeSurface(bmp_surface);
}
/*hjälpmetod för att konvertera en int till en string*/
std::string convertInt(int number)
{
	std::stringstream ss;
	ss << number;
	return ss.str();
}
/*returnerar en vector med alla actors som krockar med en angiven SDL_Rect*/
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
/*hjälp metod till intersections och svarar på om en Rect krockar med en annan Rect*/
bool GameEngine::intersect(SDL_Rect a, SDL_Rect b)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

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

	return true;

	std::vector<Actor*> intersectVector; 
}
/*avslutar motorn*/
GameEngine::~GameEngine()

{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
