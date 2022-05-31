#pragma once


#include "Actor.h"


class Card : public Actor
{
	enum class TYPE
	{
		Wolf,
		Dragon,
		Bear
	};

	
	int mIndex;
	bool mIsFront;
	TYPE mType;


public:
	Card(D2DFramework* pFramework, TYPE type, int index);

	virtual void Draw() override;
	void Flip(bool isFront);
	bool CheckClicked(float x, float y);

};

