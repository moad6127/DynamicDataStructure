#include "Text.h"

#pragma comment (lib,"dwrite.lib")

Text::Text(D2DFramework* pFramework, float x, float y, float width, float height,const wchar_t* text) :Actor(pFramework, L"Data/card_back.png")
{

	HRESULT hr;
	auto pRT = mpFramework->GetRenderTarget();
	hr = pRT->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::Red), mspBrush.GetAddressOf()
	);
	ThrowIfFailed(hr);

	hr = DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(IDWriteFactory),
		reinterpret_cast<IUnknown**> (mspDWriteFactroy.GetAddressOf())
	);
	ThrowIfFailed(hr);
	hr = mspDWriteFactroy->CreateTextFormat(
		L"Gabriola",
		NULL,
		DWRITE_FONT_WEIGHT_HEAVY,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		30,
		L"test",
		mspWForamt.GetAddressOf());
	ThrowIfFailed(hr);
	mX = x;
	mY = y;
	mRight = width;
	mBottom = height;
	mText = text;
}

void Text::Draw()
{
	D2D1_RECT_F rc{ 0.0f,0.0f, mRight,mBottom };
	auto pRT = mpFramework->GetRenderTarget();

	auto matTranslate = D2D1::Matrix3x2F::Translation(mX, mY);
	pRT->SetTransform(matTranslate);
	pRT->DrawText(
		mText.c_str(),
		static_cast<UINT>(mText.size()),
		mspWForamt.Get(),
		rc, mspBrush.Get()
	);
	
}

void Text::Draw(int count)
{
	D2D1_RECT_F rc{ 0.0f,0.0f, mRight,mBottom };
	auto pRT = mpFramework->GetRenderTarget();

	auto matTranslate = D2D1::Matrix3x2F::Translation(mX, mY);
	pRT->SetTransform(matTranslate);
	pRT->DrawText(
		std::to_wstring(count).c_str(),
		static_cast<UINT32>(std::to_wstring(count).size()),
		mspWForamt.Get(),
		rc, mspBrush.Get()
	);
}
