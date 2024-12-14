#include "Ball.h"

void Ball::update()  
{
	move(speedx, speedy);
	
	if ((getPosition().x)<0)
		speedx=BALL_SPEED;
	else if((getPosition().x+2*12)>800)
		speedx=-BALL_SPEED;
	if(getPosition().y<0)
		speedy=BALL_SPEED; 
	else if((getPosition().y+2*12)>600)
		speedy=-BALL_SPEED; 
}