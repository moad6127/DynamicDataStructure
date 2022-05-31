#include "Card.h"

#include"BitmapManager.h"

Card::Card(D2DFramework* pFramework, TYPE type, int index) : Actor(pFramework, L"card_back.png")
{
    mType = type;
    mIndex = index;
    mIsFront = false;


}

void Card::Draw()
{
	//TODO �޸��̸� �޹�� �ո��̸� Ÿ�Կ����� �̹���
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

	if (mIsFront)
	{
		mpBitmap = BitmapManager::Instance().LoadBitmap(filename);
	}
}

void Card::Flip(bool isFront)
{
    //TODO
}

bool Card::CheckClicked(float x, float y)
{
    //TODO
    return false;
}
