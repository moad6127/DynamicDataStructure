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

	ID2D1Bitmap* pCardFront;


public:
	Card(D2DFramework* pFramework, int index , TYPE type, float x, float y);

	virtual void Draw() override;
	void Flip(bool isFront);
	bool CheckClicked(int x, int y);
	inline void SetX(float x) { mX = x; }
	inline void SetY(float y) { mY = y; }
	inline TYPE GetType() { return mType; }
	inline int GetIndex() { return mIndex; }

};

