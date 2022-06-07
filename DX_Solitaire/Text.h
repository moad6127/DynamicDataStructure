#pragma once
#include "Actor.h"
#include<dwrite.h>
#include<string>
class Text : public Actor
{
	Microsoft::WRL::ComPtr<IDWriteFactory> mspDWriteFactroy;
	Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> mspBrush;
	Microsoft::WRL::ComPtr<IDWriteTextFormat> mspWForamt;
	std::wstring mText;

	float mRight;
	float mBottom;

public:
	Text(D2DFramework* pFramework, float x, float y,float right,float bottom,const wchar_t* text);
	void Draw() override;
	void Draw(int count);
};

