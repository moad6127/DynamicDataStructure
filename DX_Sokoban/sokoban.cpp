#include "sokoban.h"

HRESULT sokoban::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{

	HRESULT hr;
	hr = D2DFramework::Initialize(hInstance, title, width, height);
	ThrowIfFailed(hr);

	mspSokoban_BG = std::make_unique<Actor>(this, L"Data/bg_blank.png");

	return S_OK;
}

void sokoban::Release()
{
	mspSokoban_BG.reset();
	D2DFramework::Release();
}

void sokoban::Render()
{
	HRESULT hr;

	mspRenderTarget->BeginDraw();
	mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

	mspSokoban_BG->Draw();

	mspRenderTarget->EndDraw();
}
