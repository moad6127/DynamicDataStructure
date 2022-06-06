#pragma once
#include "Actor.h"
class Point : public Actor
{
protected:

	const float GAME_BEGIN_X{ 100.0f };
	const float GAME_BEGIN_Y{ 150.0f };
	const float BOX_SIZE{ 64.0f };

	D2D1_RECT_F mPoint_Position;
	bool mCheck;

	ID2D1Bitmap* mpBoxOnPoint;

public:
	Point(D2DFramework* pFramework);
	virtual void Draw() override;

	inline D2D1_RECT_F GetRect() { return mPoint_Position; }
	inline void CheckTrue() { mCheck = true; }
	inline bool GetCheck() { return mCheck; }
};

