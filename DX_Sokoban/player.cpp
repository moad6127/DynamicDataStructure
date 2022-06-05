#include "player.h"
#include"BitmapManager.h"
#include <sstream>

player::player(D2DFramework* pFramework) : Actor(pFramework, L"Data/Game_Player_base.png")
{
	mX = START_X;
	mY = START_Y;

	mStatus = Status::Front;
	mMoveCheck = true;

	mPlayer_Position.bottom = mY + BOX_SIZE;
	mPlayer_Position.left = mX;
	mPlayer_Position.right = mX + BOX_SIZE;
	mPlayer_Position.top = mY;

	mpBack = BitmapManager::Instance().LoadBitmap(L"Data/Game_Player_Back.png");
	mpLeft = BitmapManager::Instance().LoadBitmap(L"Data/Game_Player_Left.png");
	mpRight = BitmapManager::Instance().LoadBitmap(L"Data/Game_Player_Right.png");
	mpTempBitmap = mpBitmap;
	
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

	case 0x41:  //A
		if (mStatus != Status::Left)
		{
			mStatus = Status::Left;
		}
		else
		{
			if (mX != PLAYER_X_LEFT)
			{
				mX -= BOX_SIZE;
			}
			
			std::wostringstream oss;
			oss << mX << "," << mY << std::endl;
			OutputDebugString(oss.str().c_str());
		}
		break;
	case 0x57:	//W

		if (mStatus != Status::Back)
		{
			mStatus = Status::Back;
		}
		else
		{
			if (mY != PLAYER_Y_TOP)
			{
				mY -= BOX_SIZE ;
			}
			std::wostringstream oss;
			oss << mX << "," << mY << std::endl;
			OutputDebugString(oss.str().c_str());
		}
		break;
	case 0x53:	//S
		if (mStatus != Status::Front)
		{
			mStatus = Status::Front;
		}
		else
		{
			if (mY != PLAYER_Y_BOTTOM)
			{
				mY += BOX_SIZE;
			}
			std::wostringstream oss;
			oss << mX << "," << mY << std::endl;
			OutputDebugString(oss.str().c_str());
			
		}
		
		break;
	case 0x44:	//D
		if (mStatus != Status::Right)
		{
			mStatus = Status::Right;
		}
		else
		{
			if (mX != PLAYER_X_RIGHT)
			{
				mX += BOX_SIZE;
			}
			
			std::wostringstream oss;
			oss << mX << "," << mY << std::endl;
			OutputDebugString(oss.str().c_str());
		}
		break;
	default:
		break;
	}
	mPlayer_Position.bottom = mY + BOX_SIZE;
	mPlayer_Position.left = mX;
	mPlayer_Position.right = mX + BOX_SIZE;
	mPlayer_Position.top = mY;
}
