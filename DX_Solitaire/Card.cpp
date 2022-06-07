#include "Card.h"

#include"BitmapManager.h"

Card::Card(D2DFramework* pFramework, int index, TYPE type, float x , float y) : Actor(pFramework,L"Data/card_back.png")
{
    mType = type;
    mIndex = index;
    mIsFront = false;
	mX = x;
	mY = y;
	std::wstring filename(L"Data/card_creature_");
	switch (mType)
	{
	case TYPE::Wolf:
		filename += L"wolf.png";
		break;

	case TYPE::Dragon:
		filename += L"dragon.png";
		break;

	case TYPE::Bear:
		filename += L"bear.png";
		break;
	}
	pCardFront = BitmapManager::Instance().LoadBitmap(filename);
}

void Card::Draw()
{
	auto pRT = mpFramework->GetRenderTarget();
	auto size = mpBitmap->GetPixelSize();
	D2D1_RECT_F rect{
	0.0f, 0.0f,
	static_cast<float>(0.0f+ size.width),
	static_cast<float>(0.0f + size.height)
	};
	auto matTranslate = D2D1::Matrix3x2F::Translation(mX, mY);
	pRT->SetTransform( matTranslate);
	//TODO 뒷면이면 뒷배경 앞면이면 타입에따라서 이미지
	if (mIsFront)
	{
		pRT->DrawBitmap(pCardFront, rect, mOpacity);
	}
	else
	{
		pRT->DrawBitmap(mpBitmap, rect, mOpacity);
	}
	
}

void Card::Flip(bool isFront)
{
	mIsFront = isFront;
}

bool Card::CheckClicked(float x, float y)
{
	if (x >= mX && x <= (mX + mpBitmap->GetSize().width) &&
		y >= mY && y <= (mY + mpBitmap->GetSize().height))
	{
		Flip(!(mIsFront));
		return true;
	}
    return false;
}
