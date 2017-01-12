#ifndef PLAYER_H
#define PLAYER_H

#include"animatedsprite.h"
#include"globals.h"

class Graphics;

class Player : public AnimatedSprite
{
public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	//moves player left by -dx
	void moveLeft();

	//moves player right by dx
	void moveRight();

	//stops moving player 
	void stopMoving();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimation();
private:
	float dx, dy;

	Direction facing;
};


#endif // !PLAYER_H
