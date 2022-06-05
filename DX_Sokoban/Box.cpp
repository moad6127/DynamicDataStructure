#include "Box.h"

#include <random>
Box::Box(D2DFramework* pFramework) :Actor(pFramework, L"Data/Game_Box.png")
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> distX(1, 11);
	std::uniform_int_distribution<>distY(1,7 );

	mX = (GAME_BEGIN_X + static_cast<float> (distX(gen)) * BOX_SIZE);
	mY = (GAME_BEGIN_Y + static_cast<float> (distY(gen)) * BOX_SIZE);
	mBox_Top = mY;
	mBox_Bottom = mY + BOX_SIZE;
	mBox_Left = mX;
	mBox_Right = mX + BOX_SIZE;
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
}
