#pragma once

#include<memory>
#include<list>

#include "D2DFramework.h"
#include "Actor.h"


class sokoban : public D2DFramework
{
protected:
	std::unique_ptr<Actor> mspSokoban_BG;


public:

	virtual HRESULT Initialize(HINSTANCE hInstance, LPCWSTR title = L"Sokoban Game",
		UINT width = 1024, UINT height = 768) override;

	virtual void Release() override;
	virtual void Render() override;
};

