#include "Card.h"

#include"BitmapManager.h"

Card::Card(D2DFramework* pFramework, int index, TYPE type, float x , float y) : Actor(pFramework,L"Data/bg_blank.png")
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
	pCardBack = BitmapManager::Instance().LoadBitmap(filename);
}

void Card::Draw()
{
	//TODO 뒷면이면 뒷배경 앞면이면 타입에따라서 이미지


	if (mIsFront)
	{
		
	}
}

void Card::Flip(bool isFront)
{
    //TODO
	mIsFront = isFront;
}

bool Card::CheckClicked(float x, float y)
{
    //TODO
	if (x >= mX && x <= (mX + mpBitmap->GetSize().width) &&
		y >= mY && y <= (mY + mpBitmap->GetSize().height))
	{
		Flip(!mIsFront);
		return true;
	}
    return false;
}
