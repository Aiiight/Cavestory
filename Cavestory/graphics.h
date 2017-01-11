#ifndef GRAPHICS_H
#define GRAPHICS_H
/* Graphics Class
*Holds all graphics dealing with the game
*
*/

#include<map>
#include<string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
public:
	Graphics();
	~Graphics();

	// loadImage: loads an image into the spriteSheets map if it doesn't already exist
	//so each image will only ever be loaded once
	//returnsimage from map regardless of whetheror not it was just loaded
	SDL_Surface* loadImage(const std::string &filePath);

	//blitSurface draws a texture to a certain part of the screen
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	//renders everything to the screen
	void flip();

	//clears everything from the screen
	void clear();
	//returns renderer 
	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	
	std::map<std::string, SDL_Surface*> spriteSheets;
};

#endif