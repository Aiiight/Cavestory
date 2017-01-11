#include "input.h"

/*
	Input class; keeps track of keyboard state
*/

//this function gets called at each new frame to reset keys that are no longer relevant
void Input::beginNewFrame()
{
	this->pressedKeys.clear();
	this->releasedKeys.clear();
}

//this gets called when a key has been pressed
void Input::keyDownEvent(const SDL_Event&event)
{
	this->pressedKeys[event.key.keysym.scancode] = true;
	this->heldKeys[event.key.keysym.scancode] = true;
}

//this gets called when a key is released

void Input::keyUpEvent(const SDL_Event & event)
{
	this->releasedKeys[event.key.keysym.scancode] = true;
	this->heldKeys[event.key.keysym.scancode] = false;
}

//Check if certain key was pressed
bool Input::wasKeyPressed(SDL_Scancode key)
{
	return this->pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key)
{
	return this->releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key)
{
	return this->heldKeys[key];
}