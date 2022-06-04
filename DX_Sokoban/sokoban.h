#pragma once

#include<memory>
#include<list>

#include "D2DFramework.h"
#include "Actor.h"


class sokoban : public D2DFramework
{
	
protected:
	const int START_COLUM = 13;
	const int START_ROW = 7;
	const float BOX_SIZE{ 64.0f };
	const float GAME_BEGIN_X{ 100.0f };
	const float GAME_BEGIN_Y{ 200.0f };
	std::unique_ptr<Actor> mspGame_BG;
	std::list<std::unique_ptr<Actor>> mspsokoban_BG;


public:

	virtual HRESULT Initialize(HINSTANCE hInstance, LPCWSTR title = L"Sokoban Game",
		UINT width = 1024, UINT height = 768) override;

	virtual void Release() override;
	virtual void Render() override;
};

