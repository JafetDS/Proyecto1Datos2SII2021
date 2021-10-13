#include "Display.h"
#include <iostream>

Display::Display()
{
	Value = 0;

}

Display::~Display()
{
}

void Display::Initialize(ID2D1HwndRenderTarget* m_pRenderTarget)
{

	DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(m_pDWriteFactory),
		reinterpret_cast<IUnknown**>(&m_pDWriteFactory)
	);

	m_pDWriteFactory->CreateTextFormat(
		L"Verdana",
		NULL,
		DWRITE_FONT_WEIGHT_NORMAL,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		50,
		L"", //locale
		&m_pTextFormat
	);

	m_pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);

	//m_pTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

	m_pRenderTarget->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::White),
		&m_pWhiteBrush
	);
}

void Display::Draw(ID2D1HwndRenderTarget* m_pRenderTarget)
{
	
	std::wstring text = std::to_wstring(Value);
	std::wcin >> text;
    static const WCHAR *sc_helloWorld = text.c_str();
    D2D1_SIZE_F renderTargetSize = m_pRenderTarget->GetSize();
    m_pRenderTarget->DrawText(
        sc_helloWorld,
        text.size() ,
        m_pTextFormat,
        D2D1::RectF(0, 0, renderTargetSize.width, renderTargetSize.height),
        m_pWhiteBrush
    );
}


void Display::refresh(ID2D1HwndRenderTarget* m_pRenderTarget, int value) {

	Value = (int)(Value + value);
	//Value = value;


}