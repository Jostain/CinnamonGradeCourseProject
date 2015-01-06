#include <SDL.h>
#include <iostream>
int main(int argc, char** argv){
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Error" << SDL_GetError();
	}

	SDL_Window *window = SDL_CreateWindow("Balloon", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

	if (window == nullptr){
		std::cout << "You done goofed" << SDL_GetError();
		return 1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		SDL_DestroyWindow(window);
		std::cout << "SDL_Error" << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Surface *bmp_surface = SDL_LoadBMP("c: / images / gubbe.bmp");
	SDL_Texture *bmp_texture = SDL_CreateTextureFromSurface(renderer, bmp_surface);

	SDL_FreeSurface(bmp_surface);

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, bmp_texture, NULL,NULL);
	SDL_RenderPresent(renderer);

	SDL_Delay(5000);
	SDL_Quit();
   return 0;
}
