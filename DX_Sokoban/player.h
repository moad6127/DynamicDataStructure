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
	const float START_X{420.0f};
	const float START_Y{476.0f};
	Status mStatus;
	ID2D1Bitmap* mpBack;
	ID2D1Bitmap* mpLeft;
	ID2D1Bitmap* mpRight;
	ID2D1Bitmap* mpTempBitmap;

public:
	player(D2DFramework* pFramework);
	virtual void Draw() override;
	virtual void Move();

	inline Status GetStatus() { return mStatus; }
	inline void SetStatus(Status status) { mStatus = status; }



};

