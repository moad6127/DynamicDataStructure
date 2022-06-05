#pragma once
#include "Actor.h"

enum class Status {
	Front,
	Back,
	Left,
	Right
};
class player : public Actor
{
protected:
	const float PLAYER_Y_TOP{ 214.0f };
	const float PLAYER_Y_BOTTOM{ 598.0f };
	const float PLAYER_X_LEFT{ 164.0f };
	const float PLAYER_X_RIGHT{ 804.0f };
	const float BOX_SIZE{ 64.0f };
	const float START_X{548.0f};
	const float START_Y{470.0f};
	Status mStatus;
	bool mMoveCheck;

	ID2D1Bitmap* mpBack;
	ID2D1Bitmap* mpLeft;
	ID2D1Bitmap* mpRight;
	ID2D1Bitmap* mpTempBitmap;



public:
	player(D2DFramework* pFramework);
	virtual void Draw() override;
	virtual void Move(WPARAM key);

	void MoveCheck();


	inline Status GetStatus() { return mStatus; }
	inline void SetStatus(Status status) { mStatus = status; }



};

