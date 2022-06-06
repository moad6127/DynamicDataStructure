#pragma once
#include "Actor.h"
#include<list>
class Box : public Actor
{
protected:
	const float BOX_Y_TOP{ 214.0f };
	const float BOX_Y_BOTTOM{ 598.0f };
	const float BOX_X_LEFT{ 164.0f };
	const float BOX_X_RIGHT{ 804.0f };
	const float GAME_BEGIN_X{ 100.0f };
	const float GAME_BEGIN_Y{ 150.0f };
	const float BOX_SIZE{ 64.0f };


	D2D1_RECT_F mBox_Position;
	bool mMoveCheck;

public:

	Box(D2DFramework* pFramework);
	virtual void Draw() override;
	void Move(std::list<std::unique_ptr<Box>>& checklist, WPARAM key);

	bool MoveCheck(std::list<std::unique_ptr<Box>>& checklist, WPARAM key);


	inline D2D1_RECT_F GetRect() { return mBox_Position; }
	inline void SetMoveCheck(bool check) { mMoveCheck = check; }
};

