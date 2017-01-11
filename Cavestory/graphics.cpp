#include<SDL.h>
#include<SDL_image.h>
#include "graphics.h"
#include "globals.h"
/* Graphics Class
*Holds all graphics dealing with the game
*
*/

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->window, &this->renderer);
	SDL_SetWindowTitle(this->window, "Abu's Cavestory");
}
Graphics:: ~Graphics()
{
	SDL_DestroyWindow(this->window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath)
{
	if (this->spriteSheets.count(filePath) == 0)
	{
		this->spriteSheets[filePath] = IMG_Load(filePath.c_str());

	}

	return this->spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	SDL_RenderCopy(this->renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip()
{
	SDL_RenderPresent(this->renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(this->renderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
	return this->renderer;
}