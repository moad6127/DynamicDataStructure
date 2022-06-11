#include "sokoban.h"

#pragma comment (lib,"dwrite.lib")

HRESULT sokoban::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	HRESULT hr;
	hr = D2DFramework::Initialize(hInstance, title, width, height);
	ThrowIfFailed(hr);

	
	/*hr = mspRenderTarget->CreateSolidColorBrush(
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
	ThrowIfFailed(hr);*/
	
	GameStart();
	mspText = std::make_unique<Text>(this);
	return S_OK;
}

void sokoban::Release()
{
	Reset();
	D2DFramework::Release();
}

void sokoban::Render()
{

	mspRenderTarget->BeginDraw();
	mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));
	

	Check(mspSokoban_Box, mspSokoban_Point);
	std::wstring text_Move{ L"이동은 W,A,S,D" };
	std::wstring text_BoxCount{ L"남은 Box의 수 :" };
	std::wstring text_Reset{ L"Reset은 R키 꾹!" };
	mspText->TextDraw(text_Move.c_str(), static_cast<UINT> (text_Move.size()), 0.0f, 0.0f, 100.0f, 100.0f);
	//mspRenderTarget->DrawText(
	//	text_Move.c_str(),
	//	static_cast<UINT32>(text_Move.size()),
	//	mspWForamt.Get(),
	//	D2D1::RectF(0.0f, 0.0f, 100.0f, 100.0f),
	//	mspBrush.Get()

	//);

	mspText->TextDraw(text_BoxCount.c_str(),
		static_cast<UINT> (text_BoxCount.size()),
		700.0f, 10.0f, 900.0f, 100.0f);
	//mspRenderTarget->DrawText(
	//	text_BoxCount.c_str(),
	//	static_cast<UINT32>(text_BoxCount.size()),
	//	mspWForamt.Get(),
	//	D2D1::RectF(700.0f, 10.0f, 900.0f, 100.0f),
	//	mspBrush.Get()
	//);
	
	mspText->TextDraw(static_cast<int>(mspSokoban_Box.size()), 900.0f, 0.0f, 900.0f, 100.0f);
	//mspRenderTarget->DrawTextW(
	//	std::to_wstring(mspSokoban_Box.size()).c_str(),
	//	static_cast<UINT32>(mspSokoban_Box.size()),
	//	mspWForamt.Get(),
	//	D2D1::RectF(1000.0f, 0.0f, 900.0f, 100.0f),
	//	mspBrush.Get()
	//);
	
	mspText->TextDraw(text_Reset.c_str(), static_cast<UINT>(text_Reset.size()), 400.0f, 0.0f, 900.0f, 100.0f);
	//mspRenderTarget->DrawTextW(
	//	text_Reset.c_str(),
	//	static_cast<UINT32>(text_Reset.size()),
	//	mspWForamt.Get(),
	//	D2D1::RectF(400.0f, 0.0f, 900.0f, 100.0f),
	//	mspBrush.Get()
	//);
	mspRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	for (auto& e : mspSokoban_BG)
	{
		e->Draw();
	}
	for (auto& e : mspSokoban_Block)
	{
		e->Draw();
	}

	for (auto& e : mspSokoban_Box)
	{
		e->Draw();
	}
	for (auto& e : mspSokoban_Point)
	{
		e->Draw();
	}

	mspSokoban_Player->Draw();
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
				if (msg.wParam == 0x52)
				{
					resetCount++;
					if (resetCount > 5)
					{
						Reset();
						GameStart();
					}
				}
				else if (MoveBox(msg.wParam))
				{
					mspSokoban_Player->Move(msg.wParam);
				}
				
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

bool sokoban::MoveBox(WPARAM key)
{
	bool output;
	for (auto& e : mspSokoban_Box)
	{
		D2D1_RECT_F boxRect{ e->GetRect() };
		D2D1_RECT_F playerRect{ mspSokoban_Player->GetRect() };

		switch (mspSokoban_Player->GetStatus())
		{
		case Status::Front:
			if ((boxRect.top == playerRect.bottom && boxRect.left == playerRect.left ) && key ==0x53)
			{
				e->Move(mspSokoban_Box, key);
				output = false;
			}
			break;
		case Status::Back:
			if ((boxRect.bottom == playerRect.top && boxRect.left == playerRect.left) && key == 0x57)
			{
				e->Move(mspSokoban_Box, key);
				output = false;
			}
			break;
		case Status::Left:
			if( (boxRect.right == playerRect.left && boxRect.top == playerRect.top) && key == 0x41)
			{
				e->Move(mspSokoban_Box, key);
				output = false;
			}
			break;
		case Status::Right:
			if ((boxRect.left == playerRect.right && boxRect.top == playerRect.top) &&key == 0x44)
			{
				e->Move(mspSokoban_Box, key);
				output = false;
			}
			break;
		}
	}

	output = true;
	return output;
}

void sokoban::Check(std::list<std::unique_ptr<Box>>& boxList, std::list<std::unique_ptr<Point>>& pointList)
{
	for (auto& point : pointList)
	{
		for (auto& box : boxList)
		{
			if ((point->GetRect().top == box->GetRect().top && point->GetRect().left == box->GetRect().left)
				&& !(point->GetCheck()))
			{
				point->CheckTrue();
				boxList.remove(box);
				return;
			}
		}
	}
	if (boxList.empty())
	{
		if (MessageBox(this->GetWindowHandle(), L"게임이 끝났습니다! \n"
			L"게임을 종료 하시겠습니까?", L"END GAME", MB_ICONQUESTION | MB_YESNO) == IDYES)
		{
			DestroyWindow(this->GetWindowHandle());
		}
		else
		{
			if (MessageBox(this->GetWindowHandle(), L"게임을 다시 하시겠습니까?", L"CHECK", MB_YESNO) == IDYES)
			{
				Reset();
				GameStart();
			}
			else
			{
				DestroyWindow(this->GetWindowHandle());
			}
		}
	}
}

void sokoban::GameStart()
{
	resetCount = 0;
	float posX{ GAME_BEGIN_X }, posY{ GAME_BEGIN_Y };

	for (int x = 0; x < START_COLUM; x++)
	{
		posY = GAME_BEGIN_Y;
		for (int y = 0; y < START_ROW; y++)
		{
			if (posX == GAME_BEGIN_X || posY == GAME_BEGIN_Y ||
				x == (START_COLUM - 1) || y == (START_ROW - 1))
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
	

	for (int i = 0; i < 3; i++)
	{
		mspSokoban_Box.push_back(std::make_unique<Box>(this));
		mspSokoban_Point.push_back(std::make_unique<Point>(this));
	}
	mspSokoban_Player = std::make_unique<player>(this);
	mPlayerStatus = mspSokoban_Player->GetStatus();
}

void sokoban::Reset()
{
	mspSokoban_Player.reset();
	for (auto& e : mspSokoban_Point)
	{
		e.reset();
	}
	mspSokoban_Point.clear();
	for (auto& e : mspSokoban_Box)
	{
		e.reset();
	}
	mspSokoban_Box.clear();

	for (auto& e : mspSokoban_Block)
	{
		e.reset();
	}
	mspSokoban_Block.clear();

	for (auto& e : mspSokoban_BG)
	{
		e.reset();
	}
	mspSokoban_BG.clear();
}
