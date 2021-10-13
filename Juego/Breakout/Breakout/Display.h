#pragma once
#include "Point2D.h"
#include "resource.h"
#include <d2d1.h>
#include <dwrite.h>
#include <string>

class Display{



public:

	Display();

	~Display();

	void Initialize(ID2D1HwndRenderTarget* m_pRenderTarget);
	void Draw(ID2D1HwndRenderTarget* m_pRenderTarget);
	void refresh(ID2D1HwndRenderTarget* m_pRenderTarget, int value);
	int Value;

	private:

		ID2D1SolidColorBrush* m_pWhiteBrush;
		IDWriteFactory* m_pDWriteFactory;
		IDWriteTextFormat* m_pTextFormat;
		


};

