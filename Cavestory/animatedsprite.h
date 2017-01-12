#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include<map>
#include<string>
#include<vector>
#include "sprite.h"
#include"globals.h"

class Graphics;

/* holds logic for animating sprites*/

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphcs, const std::string &filePath, int sourceX, int sourceY, int width, int height,
		float posX, float posY, float timeToUpdate);

	void playAnimation(std::string animation, bool once = false);

	void update(int elapsedTime);

	void draw(Graphics &graphics, int x, int y);


	// void setupAnimation: required function that sets up all animations for a sptire
	

protected:
	double timeToUpdate;
	bool currentAnimationOnce;
	std::string currentAnimation;

	//addanimation adds an animation to the map o fanimations for the sprite
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

	void resetAnimations();

	void stopAnimation();

	void setVisible(bool visible);

	virtual void animationDone(std::string currentAnimation) = 0;

	virtual void setupAnimation() = 0;

private:
	std::map<std::string, std::vector<SDL_Rect> > animations;
	std::map<std::string, Vector2> offsets;

	int frameIndex;
	double timeElapsed = 0;
	bool visible;
};

#endif