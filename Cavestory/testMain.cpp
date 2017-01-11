#include<SDL.h>
#include<stdio.h>
#include<iostream>

using namespace std;

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 480;

bool initialize();
void close();

SDL_Window* window = NULL;
SDL_Surface* screen = NULL;

int main(int argc, char* args[])
{
	if (!initialize())
	{
		cout << "Couldn't initialize" << endl;
		return -1 ;
	}
	
	bool exit = false;
	SDL_Event e;

	Uint32 bgColor = SDL_MapRGB(screen->format, 0, 0, 0);
	
	while (!exit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
			{
				exit = true;
			}

		}
		SDL_FillRect(screen, NULL, bgColor);

		SDL_UpdateWindowSurface(window);
	}

	close();
	return 0;
}


bool initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not be initialized! SDL_ERROR : %s\n", SDL_GetError());
		return false;
	}
	window = SDL_CreateWindow("My SDL Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		printf("Window couldn't be created. SDL ERROR %s\n", SDL_GetError());
		return false;
	}
	screen = SDL_GetWindowSurface(window);
	return true;
}
void close()
{
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_FreeSurface(screen);

	SDL_Quit();
}