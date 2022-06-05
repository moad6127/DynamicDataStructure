#pragma once

#include<memory>
#include<list>

#include "D2DFramework.h"
#include "player.h"
#include "Box.h"


class sokoban : public D2DFramework
{
	
protected:
	const int START_COLUM = 13;
	const int START_ROW = 9;
	const float BOX_SIZE{ 64.0f };
	const float GAME_BEGIN_X{ 100.0f };
	const float GAME_BEGIN_Y{ 150.0f };

	std::list<std::unique_ptr<Actor>> mspSokoban_BG;
	std::list<std::unique_ptr<Actor>> mspSokoban_Block;
	std::unique_ptr<player> mspSokoban_Player;
	std::list<std::unique_ptr<Box>> mspSokoban_Box;



public:

	virtual HRESULT Initialize(HINSTANCE hInstance, LPCWSTR title = L"Sokoban Game",
		UINT width = 1024, UINT height = 768) override;

	virtual void Release() override;
	virtual void Render() override;

	virtual int GameLoop() override;
};

