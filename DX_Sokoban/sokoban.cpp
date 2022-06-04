#include "sokoban.h"

HRESULT sokoban::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{

	HRESULT hr;
	hr = D2DFramework::Initialize(hInstance, title, width, height);
	ThrowIfFailed(hr);

	mspGame_BG = std::make_unique<Actor>(this, L"Data/bg_blank.png");
	float posX{ GAME_BEGIN_X }, posY{ GAME_BEGIN_Y };

	for (int x = 1; x <= START_COLUM; x++)
	{
		posY = GAME_BEGIN_Y;
		for (int y = 1; y <= START_ROW; y++)
		{
			mspsokoban_BG.push_back(std::make_unique<Actor>(this, L"Data/Ground.png", posX, posY));
			posY += BOX_SIZE;
		}
		posX += BOX_SIZE;
	}

	return S_OK;
}

void sokoban::Release()
{
	mspGame_BG.reset();
	D2DFramework::Release();
}

void sokoban::Render()
{
	HRESULT hr;

	mspRenderTarget->BeginDraw();
	mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

	mspGame_BG->Draw();
	for (auto& e : mspsokoban_BG)
	{
		e->Draw();
	}

	mspRenderTarget->EndDraw();
}
