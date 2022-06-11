#include "Text.h"

Text::Text(D2DFramework* pFramework)
{
	HRESULT hr;
	mpFramework = pFramework;
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

}

void Text::TextDraw(const wchar_t* text, UINT textSize, float x, float y, float right, float bottom)
{
	D2D1_RECT_F rc{ 0.0f,0.0f, right, bottom };
	auto pRT = mpFramework->GetRenderTarget();

	auto matTranslate = D2D1::Matrix3x2F::Translation(x, y);
	pRT->SetTransform(matTranslate);
	pRT->DrawText(
		text,
		textSize,
		mspWForamt.Get(),
		rc, mspBrush.Get()
	);

}

void Text::TextDraw(int count, float x, float y, float right, float bottom)
{
	D2D1_RECT_F rc{ 0.0f,0.0f, right,bottom };
	auto pRT = mpFramework->GetRenderTarget();

	auto matTranslate = D2D1::Matrix3x2F::Translation(x, y);

	pRT->SetTransform(matTranslate);

	pRT->DrawText(
		std::to_wstring(count).c_str(),
		static_cast<UINT32>(std::to_wstring(count).size()),
		mspWForamt.Get(),
		rc, mspBrush.Get()
	);
}
