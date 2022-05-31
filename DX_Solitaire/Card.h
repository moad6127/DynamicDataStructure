#pragma once


#include "Actor.h"

enum class TYPE
{
	Wolf,
	Dragon,
	Bear
};
class Card : public Actor
{
	int mIndex;
	bool mIsFront;
	TYPE mType;

	ID2D1Bitmap* pCardBack;


public:
	Card(D2DFramework* pFramework, int index , TYPE type, float x, float y);

	virtual void Draw() override;
	void Flip(bool isFront);
	bool CheckClicked(float x, float y);
	inline void SetX(float x) { mX = x; }
	inline void SetY(float y) { mY = y; }

};

