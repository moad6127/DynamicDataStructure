#include "Point.h"
#include "BitmapManager.h"
#include <random>

Point::Point(D2DFramework* pFramework) :Actor(pFramework, L"Data/Game_Position.png")
{

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> distX(1, 11);
	std::uniform_int_distribution<>distY(1, 7);

	mX = (GAME_BEGIN_X + static_cast<float> (distX(gen)) * BOX_SIZE);
	mY = (GAME_BEGIN_Y + static_cast<float> (distY(gen)) * BOX_SIZE);

	mPoint_Position.bottom = mY + BOX_SIZE;
	mPoint_Position.left = mX;
	mPoint_Position.right = mX + BOX_SIZE;
	mPoint_Position.top = mY;

	mCheck = false;
	mpBoxOnPoint = BitmapManager::Instance().LoadBitmap(L"Data/Game_Point.png");
}

void Point::Draw()
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
	if (mCheck)
	{
		pRT->DrawBitmap(
			mpBoxOnPoint,
			rect,
			1.0f);
	}
	else
	{
		pRT->DrawBitmap(
			mpBitmap,
			rect,
			1.0f);
	}

}
