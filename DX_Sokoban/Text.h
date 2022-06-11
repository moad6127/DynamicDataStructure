#pragma once

#include "D2DFramework.h"

#include<dwrite.h>
class Text
{
	D2DFramework* mpFramework;
	Microsoft::WRL::ComPtr<IDWriteFactory> mspDWriteFactroy;
	Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> mspBrush;
	Microsoft::WRL::ComPtr<IDWriteTextFormat> mspWForamt;


public:
	Text(D2DFramework* pFramework);
	void TextDraw(const wchar_t* text, UINT textSize, float x, float y, float right, float bottom);
	void TextDraw(int count, float x, float y, float right, float bottom);
};

