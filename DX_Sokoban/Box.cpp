#include "Box.h"

#include <random>
Box::Box(D2DFramework* pFramework) :Actor(pFramework, L"Data/Game_Box.png")
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> distX(2, 10);
	std::uniform_int_distribution<>distY(2,6 );

	mX = (GAME_BEGIN_X + static_cast<float> (distX(gen)) * BOX_SIZE);
	mY = (GAME_BEGIN_Y + static_cast<float> (distY(gen)) * BOX_SIZE);

	mBox_Position.bottom	= mY + BOX_SIZE;
	mBox_Position.left		= mX;
	mBox_Position.right		= mX + BOX_SIZE;
	mBox_Position.top		= mY;

	mMoveCheck = true;


}

void Box::Draw()
{
	auto pRT = mpFramework->GetRenderTarget();
	auto size = mpBitmap->GetPixelSize();

	D2D1_RECT_F rect{
	0.0f, 0.0f,
	static_cast<float>(0.0f + size.width),
	static_cast<float>(0.0f + size.height)
	};
	auto matTranslate = D2D1::Matrix3x2F::Translation(mX, mY);

	pRT->SetTransform(matTranslate);
	pRT->DrawBitmap(
		mpBitmap,
		rect,
		1.0f);

	mBox_Position.bottom = mY + BOX_SIZE;
	mBox_Position.left = mX;
	mBox_Position.right = mX + BOX_SIZE;
	mBox_Position.top = mY;

}

void Box::Move(std::list<std::unique_ptr<Box>>& checklist, WPARAM key)
{
	switch (key)
	{
	case 0x41://A
		if (MoveCheck(checklist,key))
		{
			mX -= BOX_SIZE;
		}
		break;
	case 0x57://W

		if (MoveCheck(checklist, key))
		{
			mY -= BOX_SIZE;
		}
		
		break;
	case 0x53://S

		if (MoveCheck(checklist, key))
		{
			mY += BOX_SIZE;
		}
		
		break;
	case 0x44://D

		if (MoveCheck(checklist, key))
		{
			mX += BOX_SIZE;
		}
		
		break;

	default:
		break;
	}
}

bool Box::MoveCheck(std::list<std::unique_ptr<Box>>& checklist, WPARAM key)
{

	switch (key)
	{
	case 0x41://A
		for (auto& e : checklist)
		{
			if ((e->GetX() == (mX - BOX_SIZE) && e->GetY() == mY) || mX == BOX_X_LEFT)
			{
				return false;
			}
		}

		break;
	case 0x57://W
		for (auto& e : checklist)
		{
			if ((e->GetY() == (mY - BOX_SIZE) && e->GetX() == mX) || mY == BOX_Y_TOP)
			{
				return false;
			}
		}
		

		break;
	case 0x53://S
		for (auto& e : checklist)
		{
			if ((e->GetY() == (mY + BOX_SIZE) && e->GetX() == mX) || mY == BOX_Y_BOTTOM)
			{
				return false;
			}
		}
		

		break;
	case 0x44://D
		for (auto& e : checklist)
		{
			if ((e->GetX() == (mX + BOX_SIZE) && e->GetY() == mY) || mX == BOX_X_RIGHT)
			{
				return false;
			}
		}

	default:
		break;
	}
	return true;
}
