#include "Solitaire.h"

HRESULT Solitaire::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	HRESULT hr;
	hr = D2DFramework::Initialize(hInstance, title, width, height);
	ThrowIfFailed(hr);


	//예제에서  초기화 필요한것
	mActor_BG = std::make_unique<Actor>(this, L"bg_blank.png");
	for (int i = 0; i < 40; i++)
	{
		mCardList.push_back(std::make_unique<Actor>(this));
	}
	return S_OK;
}

void Solitaire::Release()
{
	mActor_BG.reset();
	for (auto& e : mCardList)
	{
		e.reset();
	}
	D2DFramework::Release();
}

void Solitaire::Render()
{
	HRESULT hr;

	mspRenderTarget->BeginDraw();

	mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

	//예제에서 그릴것들
	mActor_BG->Draw();
	for (auto& e : mCardList)
	{
		e->Draw();
	}

	hr = mspRenderTarget->EndDraw();
	if (hr == D2DERR_RECREATE_TARGET)
	{
		CreateDeviceResources();
	}
}

void Solitaire::onClick(int mouseX, int mouseY)
{
}

void Solitaire::CreateCards()
{
}
