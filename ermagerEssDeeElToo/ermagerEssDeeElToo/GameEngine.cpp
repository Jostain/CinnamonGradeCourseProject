#include "Main.h"
#include <vector>




SDL_Window *window        = NULL;
SDL_Renderer *renderer    = NULL;
SDL_Texture *bmp_texture  = NULL;
SDL_Texture *Background_texture = NULL;
std::vector<Sprite*> spriteVector;
std::vector<Actor*> actorVector;


GameEngine::GameEngine(const char* title, int height, int width)
{
	// Innan vi använder biblioteket så måste det initialiseras.
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		//return 1;
	}

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		//return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		SDL_DestroyWindow(window);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		//return 1;
	}
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
	int nextSprite = 0;
	while (nextSprite < spriteVector.size())
	{
				
		SDL_Surface *bmp_surface = spriteVector[nextSprite]->draw();
		bmp_texture = SDL_CreateTextureFromSurface(renderer, bmp_surface);
		SDL_FreeSurface(bmp_surface);
		SDL_RenderCopy(renderer, bmp_texture, &spriteVector[nextSprite]->getTextureSize(), &spriteVector[nextSprite]->getTexturePosition());
		nextSprite++;
		
	}
	SDL_RenderPresent(renderer);

}
void GameEngine::run()
{
	bool program_is_running = true;
	while (program_is_running)
	{
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
	}
}
void GameEngine::setBackground(std::string path)
{
	std::string imagePath = path;
	SDL_Surface *bmp_surface = SDL_LoadBMP(imagePath.c_str());
	Background_texture = SDL_CreateTextureFromSurface(renderer, bmp_surface);
	SDL_FreeSurface(bmp_surface);
}


GameEngine::~GameEngine()

{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
