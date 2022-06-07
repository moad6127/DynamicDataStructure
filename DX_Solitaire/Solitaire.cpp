
#include<vector>
#include<random>
#include<dwrite.h>
#include "Solitaire.h"

#pragma comment (lib,"dwrite.lib")

HRESULT Solitaire::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	HRESULT hr;
	hr = D2DFramework::Initialize(hInstance, title, width, height);
	ThrowIfFailed(hr);

	hr = mspRenderTarget->CreateSolidColorBrush(
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


	//예제에서  초기화 필요한것
	mActor_BG = std::make_unique<Actor>(this, L"Data/bg_blank.png");

	CreateCards();
	return S_OK;
}

void Solitaire::Release()
{
	mActor_BG.reset();
	for (auto& e : mCardList)
	{
		e.reset();
	}
	D2DFramework::Release();
}

void Solitaire::Render()
{
	HRESULT hr;

	mspRenderTarget->BeginDraw();

	mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));
	

	//예제에서 그릴것들
	mActor_BG->Draw();
	for (auto& e : mCardList)
	{
		e->Draw();
	}

	mspRenderTarget->DrawText(
		L"클릭수 :",
		6,
		mspWForamt.Get(),
		D2D1::RectF(895.0f, 20.0f, 1000.0f, 60.0f), mspBrush.Get()
	);
	mspRenderTarget->DrawText(
		std::to_wstring(mFlipCount).c_str(),
		static_cast<UINT>(std::to_wstring(mFlipCount).size()),
		mspWForamt.Get(),
		D2D1::RectF(895.0f, 60.0f, 1000.0f, 100.0f),
		mspBrush.Get()
	);

	hr = mspRenderTarget->EndDraw();
	if (hr == D2DERR_RECREATE_TARGET)
	{
		CreateDeviceResources();
	}
}


void Solitaire::onClick(int mouseX, int mouseY)
{
	Card* pCard{};
	for (auto& card : mCardList)
	{
		if (card->CheckClicked(
			static_cast<float>(mouseX),
			static_cast<float>(mouseY)))
		{
			pCard = card.get();
			break;
		}
	}
	if (pCard)
	{
		mFlipCount++;
		if (mpSelectedCrad == nullptr)
		{
			mpSelectedCrad = pCard;
		}
		else
		{
			if (pCard == mpSelectedCrad)
			{
				mpSelectedCrad = nullptr;
			}
			else if (pCard->GetType() == mpSelectedCrad->GetType())
			{

				//for (auto& card : mCardList)
				//{
				//	if (card->GetIndex() == pCard->GetIndex())
				//	{
				//		mCardList.remove(card);
				//		break;
				//	}
				//}
				//for (auto& card : mCardList)
				//{
				//	if (card->GetIndex() == mpSelectedCrad->GetIndex())
				//	{
				//		mCardList.remove(card);
				//		break;
				//	}
				//}
				mCardList.remove_if([&](auto& card)
					{
						return pCard->GetIndex() == card->GetIndex() || mpSelectedCrad->GetIndex() == card->GetIndex();
					});

				mpSelectedCrad = nullptr;
			}
			else
			{
				Render();
				Sleep(500);
				pCard->Flip(false);
				mpSelectedCrad->Flip(false);

				mpSelectedCrad = nullptr;
			}
		}
	}
}


void Solitaire::CreateCards()
{
	//TODO: 카드 섞기
	std::vector<TYPE> types;

	while (types.size() < static_cast<size_t>(BORAD_COLUM * BORAD_ROW))
	{
		int temp = types.size() % 6;
		switch (temp)
		{
		case 0:
			types.push_back(TYPE::Bear);
			types.push_back(TYPE::Bear);
			break;
		case 2:
			types.push_back(TYPE::Wolf);
			types.push_back(TYPE::Wolf);
			break;
		case 4:
			types.push_back(TYPE::Dragon);
			types.push_back(TYPE::Dragon);
			break;
		}
	}
	std::random_device rd;
	std::mt19937 gen(rd());

	std::shuffle(types.begin(), types.end(), gen);

	int index{};
	int posX{ 15 }, posY{ 10 };

	for (int x = 0; x < BORAD_COLUM; x++)
	{
		posY = 10;
		for (int y = 0; y < BORAD_ROW; y++)
		{
			mCardList.push_back(std::make_unique<Card>(this,index,types[index++],
				static_cast<float>(posX),
				static_cast<float>(posY)));
			posY += 140 + 10;
		}
		posX += 100 + 10;
	}
}

int Solitaire::GameLoop()
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
			if (msg.message == WM_LBUTTONUP)
			{
				this->onClick(LOWORD(msg.lParam), HIWORD(msg.lParam));
				Render();
				if (this->GetSize() == 0)
				{
					// 영어 메시지
					/*if (MessageBox(hwnd, L"GOOD! you have completed the game!! \n"
						L" You want to end the game?", L"END GAME", MB_ICONQUESTION | MB_YESNO) == IDYES)*/
						//한글 메시지
					if (MessageBox(this->GetWindowHandle(), L"게임이 끝났습니다! \n"
						L"게임을 종료 하시겠습니까?", L"END GAME", MB_ICONQUESTION | MB_YESNO) == IDYES)
					{
						DestroyWindow(this->GetWindowHandle());
					}
					else
					{
						//영어 메시지
						/*if (MessageBox(hwnd, L"Do you want to play the game again?", L"CHECK", MB_YESNO) == IDYES)*/
						//한글 메시지
						if (MessageBox(this->GetWindowHandle(), L"게임을 다시 하시겠습니까?", L"CHECK", MB_YESNO) == IDYES)
						{
							CreateCards();
							mFlipCount = 0;
						}
						else
						{
							DestroyWindow(this->GetWindowHandle());
						}
					}
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
