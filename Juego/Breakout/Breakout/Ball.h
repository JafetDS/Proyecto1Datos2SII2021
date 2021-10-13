#pragma once
#include <string>
#include "resource.h"
#include "Point2D.h"

#define RECOIL_X_MAX 300

class Ball
{
public:
	Ball();
	~Ball();

	void Reset();
	void Initialize(ID2D1HwndRenderTarget* m_pRenderTarget);
	void Advance(double elapsedTime);
	void CheckHitsPaddle(float paddleX);
	boolean IsOutside();
	void Draw(ID2D1HwndRenderTarget* m_pRenderTarget);
	int getprof();
	void setprof();
	void disprof();
	int Prof;
	int mod;
	void setmod();
	void dismod();
	Point2D position;
	Point2D speed;

	void setspeed();
	Point2D getspeed();
	void disspeed();
private:

	ID2D1SolidColorBrush* m_pRedBrush;
};
