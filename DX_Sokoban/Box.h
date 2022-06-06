#pragma once
#include "Actor.h"
class Box : public Actor
{
protected:
	const float GAME_BEGIN_X{ 100.0f };
	const float GAME_BEGIN_Y{ 150.0f };
	const float BOX_SIZE{ 64.0f };


	D2D1_RECT_F mBox_Position;
	bool mMoveCheck;

public:

	Box(D2DFramework* pFramework);
	virtual void Draw() override;
	bool MoveCheck(WPARAM key);

	inline D2D1_RECT_F GetRect() { return mBox_Position; }
	inline void SetMoveCheck(bool check) { mMoveCheck = check; }
};

