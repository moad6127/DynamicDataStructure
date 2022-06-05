#include "player.h"
#include"BitmapManager.h"


player::player(D2DFramework* pFramework) : Actor(pFramework, L"Data/Game_Player_base.png")
{
	mX = START_X;
	mY = START_Y;
	mpTempBitmap = mpBitmap;
	mStatus = Status::Front;
	mpBack = BitmapManager::Instance().LoadBitmap(L"Data/Game_Player_Back.png");
	mpLeft = BitmapManager::Instance().LoadBitmap(L"Data/Game_Player_Left.png");
	mpRight = BitmapManager::Instance().LoadBitmap(L"Data/Game_Player_Right.png");
	
}

void player::Draw()
{
	auto pRT = mpFramework->GetRenderTarget();
	auto size = mpBitmap->GetPixelSize();
	switch (mStatus)
	{
	case Status::Front:
		mpTempBitmap = mpBitmap;
		break;
	case Status::Back:
		mpTempBitmap = mpBack;
		break;
	case Status::Left:
		mpTempBitmap = mpLeft;
		break;
	case Status::Right:
		mpTempBitmap = mpRight;
		break;
	}
	D2D1_RECT_F rect{
		0.0f, 0.0f,
		static_cast<float>(0.0f + size.width),
		static_cast<float>(0.0f + size.height)
	};

	auto matTranslate = D2D1::Matrix3x2F::Translation(mX, mY);

	pRT->SetTransform(matTranslate);
	pRT->DrawBitmap(
		mpTempBitmap,
		rect,
		1.0f);
	

}

void player::Move(WPARAM key)
{
	switch (key)
	{

	case 0x41: 
		if (!(mStatus == Status::Left))
		{
			mStatus = Status::Left;
		}
		else
		{
			mX -= BOX_SIZE;
		}
		break;
	case 0x57:	

		if (!(mStatus == Status::Back))
		{
			mStatus = Status::Back;
		}
		else
		{
			mY -= BOX_SIZE;
		}
		break;
	case 0x53:	
		if (!(mStatus == Status::Front))
		{
			mStatus = Status::Front;
		}
		else
		{
			mY += BOX_SIZE;
		}
		
		break;
	case 0x44:	
		if (!(mStatus == Status::Right))
		{
			mStatus = Status::Right;
		}
		else
		{
			mX += BOX_SIZE;
		}
		break;
	default:
		break;
	}
}
