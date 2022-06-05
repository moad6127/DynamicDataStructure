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
		mX, mY,
		static_cast<float>(mX + size.width),
		static_cast<float>(mY + size.height)
	};
	pRT->DrawBitmap(
		mpTempBitmap,
		rect,
		1.0f);
	

}

void player::Move()
{
}
