#include <SDL.h>
#include <iostream>

const int SCREEN_HEIGTH = 1024;
const int SCREEN_WIDTH = 768;

SDL_Window* ventana;
SDL_Renderer* renderer;
SDL_Rect rectangulo;
SDL_Event events;
bool gameOver = false;

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);


	rectangulo.x = 100;
	rectangulo.y = 100;
	rectangulo.h = 50;
	rectangulo.w = 25;

	ventana = SDL_CreateWindow("Programacion de graficos Tp2", 100, 100, SCREEN_WIDTH, SCREEN_HEIGTH, 0);
	if (ventana == nullptr)
		std::cout << "Failed to create window : " << SDL_GetError();

	renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
		std::cout << "Failed to create renderer : " << SDL_GetError();

	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGTH);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);


	while (!gameOver)
	{
		while (SDL_PollEvent(&events))
		{
			if (events.type == SDL_QUIT || events.key.keysym.sym == SDLK_ESCAPE)
				gameOver = true;

			if (events.key.keysym.sym == SDLK_RIGHT)
				rectangulo.x++;
			if (events.key.keysym.sym == SDLK_LEFT)
				rectangulo.x--;
			if (events.key.keysym.sym == SDLK_UP)
				rectangulo.y--;
			if (events.key.keysym.sym == SDLK_DOWN)
				rectangulo.y++;
		}



		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

		SDL_RenderFillRect(renderer, &rectangulo);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		SDL_RenderPresent(renderer);

	}

	return 0;
}