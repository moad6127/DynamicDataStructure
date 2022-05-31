
#include<vector>
#include<random>
#include "Solitaire.h"

HRESULT Solitaire::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	HRESULT hr;
	hr = D2DFramework::Initialize(hInstance, title, width, height);
	ThrowIfFailed(hr);


	//��������  �ʱ�ȭ �ʿ��Ѱ�
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

	//�������� �׸��͵�
	mActor_BG->Draw();
	for (auto& e : mCardList)
	{
		e->Draw();
	}

	hr = mspRenderTarget->EndDraw();
	if (hr == D2DERR_RECREATE_TARGET)
	{
		CreateDeviceResources();
	}
}

void Solitaire::onClick(int mouseX, int mouseY)
{
}

void Solitaire::CreateCards()
{
	//TODO: ī�� ����
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


