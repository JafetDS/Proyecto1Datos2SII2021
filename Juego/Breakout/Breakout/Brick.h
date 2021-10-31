#pragma once

#include "resource.h"
#include "Point2D.h"
#include "Ball.h"
#include "Display.h"
#include "Paddle.h"
#include <string>
using namespace std;


#define BRICK_WIDTH 40
#define BRICK_HEIGHT 20

class Brick
{
public:
	Brick(float xPos, float yPos, int tipo);
	~Brick();

	void Initialize(ID2D1HwndRenderTarget* m_pRenderTarget);
	void Draw(ID2D1HwndRenderTarget* m_pRenderTarget);
	void BallCollision(Ball* ball, Display* display, Paddle* paddle);
	void ChangeColor();
	

	Point2D position;
	int health;
	int Type;
	int color;
	int Point;
	int sor;
	int contpass;
private:

	ID2D1SolidColorBrush* m_pGreenBrush;
	ID2D1HwndRenderTarget* Render;
};

