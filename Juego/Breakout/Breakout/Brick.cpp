#include "framework.h"
#include "Point2D.h"
#include "Brick.h"
#include "Ball.h"
#include "Engine.h"
#include "Display.h"
#include <iostream>

Brick::Brick(float xPos, float yPos,int tipo) : m_pGreenBrush(NULL)
{
	position.x = xPos;
	position.y = yPos;
	Type = tipo;
	
	

	if (Type == 1) { //comun
		color = 16776960; // Yellow
		health = 1;
		Point = 5 + 5 * health;
	}
	else if (Type == 2) {//doble
		color = 32768;//green
		health = 2;
		Point = 5 + 5 * health;
	}
	else if (Type == 3) {//triple
		color = 16711680;
		health = 3;
		Point = 5 + 5 * health;
	}


	else if (Type == 4) {//sorpresa

		sor =  1 + rand() % ((4 + 1) - 1);
		color = 8388736;//  Purple
		health = 1;
	}

	else if (Type == 5) {//profundo
		color = 16777215; // white
		health = 100;
	}

	
}

Brick::~Brick()
{
	SafeRelease(&m_pGreenBrush);
}

void Brick::Initialize(ID2D1HwndRenderTarget* m_pRenderTarget)
{		//D2D1::ColorF::Blue
	// Creates a blue brush for drawing
	Render = m_pRenderTarget;
	ChangeColor();
}

void Brick::ChangeColor() {
	Render->CreateSolidColorBrush(
		D2D1::ColorF(color),
		&m_pGreenBrush
	);
}

void Brick::BallCollision(Ball* ball, Display* display, Paddle* paddle)
{

	if (health > 0)
	{

		float brickTop = position.y - BRICK_HEIGHT / 2;
		float brickBottom = position.y + BRICK_HEIGHT / 2;
		float brickLeft = position.x - BRICK_WIDTH / 2;
		float brickRight = position.x + BRICK_WIDTH / 2;

		float ballTop = ball->position.y - 10;
		float ballBottom = ball->position.y + 10;
		float ballLeft = ball->position.x - 10;
		float ballRight = ball->position.x + 10;




		// If it's a collision
		if (ballTop < brickBottom && ballBottom > brickTop && ballRight > brickLeft && ballLeft < brickRight)
		{

			


			if (1==1)// (Type == 5 | ball->getprof() == 0)
			{
				float distanceX1 = abs(ballRight - brickLeft);
				float distanceX2 = abs(ballLeft - brickRight);
				float distanceY1 = abs(ballTop - brickBottom);
				float distanceY2 = abs(ballBottom - brickTop);

				// From bottom
				if (ball->speed.y < 0 && distanceY1 < distanceY2 && distanceY1 < distanceX1 && distanceY1 < distanceX2)
				{
					ball->speed.y = abs(ball->speed.y);

					health--;
				}
				// From top
				if (ball->speed.y > 0 && distanceY2 < distanceY1 && distanceY2 < distanceX1 && distanceY2 < distanceX2)
				{
					ball->speed.y = -abs(ball->speed.y);
					health--;
				}
				// From left
				if (ball->speed.x > 0 && distanceX1 < distanceX2 && distanceX1 < distanceY1 && distanceX1 < distanceY2)
				{
					ball->speed.x = -abs(ball->speed.x);
					health--;
				}
				// From right
				if (ball->speed.x < 0 && distanceX2 < distanceX1 && distanceX2 < distanceY1 && distanceX2 < distanceY2)
				{
					ball->speed.x = abs(ball->speed.x);
					health--;
				}
				if (health == 2) {
					color = 32768;
					ChangeColor();
				}
				if (health == 1) {
					color = 16776960;
					ChangeColor();
				}
				if (Type == 5) {
					color = 255;

				
					
				//	ball->setprof();
				//	ChangeColor();
				//	display->refresh(Render, ball->getprof());
				}

				if (Type == 4) {

					if (sor == 1) {
						paddle->setmod();
						ball->setmod();
					}
					else if (sor == 2) {
						paddle->dismod();
						ball->dismod();
					}
					else if (sor == 3) {
						
						ball->setspeed();
					}
					else if (sor == 4) {
						ball->disspeed();

					}
					
				}
				if (health == 0) {

					display->refresh(Render, Point);

					//std::cout << puntaje << endl;
				}

			}
			else {
				ball->disprof();
				display->refresh(Render, ball->getprof());
			}




		}

	}

}

void Brick::Draw(ID2D1HwndRenderTarget* m_pRenderTarget)
{
	if (health > 0)
	{

		// Draws a rectangle representing the brick
		D2D1_RECT_F rectangle1 = D2D1::RectF(
			position.x - BRICK_WIDTH / 2 + 1, position.y - BRICK_HEIGHT / 2 + 1,
			position.x + BRICK_WIDTH / 2 - 1, position.y + BRICK_HEIGHT / 2 - 1
		);
		m_pRenderTarget->FillRectangle(&rectangle1, m_pGreenBrush);

	}

}