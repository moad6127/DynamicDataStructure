#pragma once
#include "Actor.h"
class Box : public Actor
{
protected:
	const float GAME_BEGIN_X{ 100.0f };
	const float GAME_BEGIN_Y{ 150.0f };
	const float BOX_SIZE{ 64.0f };
	float mBox_Top;
	float mBox_Bottom;
	float mBox_Left;
	float mBox_Right;

	bool mMoveCheck;

public:

	Box(D2DFramework* pFramework);
	virtual void Draw() override;
	bool MoveCheck();
};

