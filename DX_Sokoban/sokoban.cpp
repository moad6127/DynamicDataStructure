#include "sokoban.h"

HRESULT sokoban::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{



	HRESULT hr;
	hr = D2DFramework::Initialize(hInstance, title, width, height);
	ThrowIfFailed(hr);

	float posX{ GAME_BEGIN_X }, posY{ GAME_BEGIN_Y };

	for (int x = 0; x < START_COLUM; x++)
	{
		posY = GAME_BEGIN_Y;
		for (int y = 0; y < START_ROW; y++)
		{
			if (posX == GAME_BEGIN_X || posY == GAME_BEGIN_Y ||
				x == (START_COLUM-1) || y == (START_ROW-1))
			{
				mspSokoban_Block.push_back(std::make_unique<Actor>(this, L"Data/Game_Block.png", posX, posY));
			}
			else
			{
				mspSokoban_BG.push_back(std::make_unique<Actor>(this, L"Data/Game_Ground.png", posX, posY));
			}
			posY += BOX_SIZE;
		}
		posX += BOX_SIZE;
	}
	mspSokoban_Player = std::make_unique<player>(this);

	for (int i = 0; i < 5; i++)
	{
		mspSokoban_Box.push_back(std::make_unique<Box>(this));
	}
	return S_OK;
}

void sokoban::Release()
{
	for (auto& e : mspSokoban_Box)
	{
		e.reset();
	}
	mspSokoban_Player.reset();

	for (auto& e : mspSokoban_Block)
	{
		e.reset();
	}

	for (auto& e : mspSokoban_BG)
	{
		e.reset();
	}



	D2DFramework::Release();
}

void sokoban::Render()
{
	HRESULT hr;

	mspRenderTarget->BeginDraw();
	mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));
	mspRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());



	for (auto& e : mspSokoban_BG)
	{
		e->Draw();
	}
	for (auto& e : mspSokoban_Block)
	{
		e->Draw();
	}
	mspSokoban_Player->Draw();
	for (auto& e : mspSokoban_Box)
	{
		e->Draw();
	}

	mspRenderTarget->EndDraw();
}

int sokoban::GameLoop()
{
	MSG msg{};
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
			{
				break;
			}
			if (msg.message == WM_KEYDOWN)
			{
				mspSokoban_Player->Move(msg.wParam);
			}
		}
		else
		{
			Render();
		}
	}
	Release();

	return static_cast<int>(msg.wParam);
}
