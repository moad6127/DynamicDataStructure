#pragma once

#include<memory>
#include<list>
#include<dwrite.h>


#include"D2DFramework.h"
#include"Card.h"
#include"Text.h"


class Solitaire : public D2DFramework
{
protected:

	std::unique_ptr<Actor> mActor_BG;
	std::list<std::unique_ptr<Card>> mCardList;
	const int BORAD_COLUM = 8;
	const int BORAD_ROW = 5;

	Card* mpSelectedCrad;

	Microsoft::WRL::ComPtr<IDWriteFactory> mspDWriteFactroy;
	Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> mspBrush;
	Microsoft::WRL::ComPtr<IDWriteTextFormat> mspWForamt;
	std::unique_ptr<Text> mspText_Click;
	std::unique_ptr<Text> mspText_ClickCount;

	int mFlipCount;
	

public:
	virtual HRESULT Initialize(HINSTANCE hInstance, LPCWSTR title = L"Buggy House",
		UINT width = 1024, UINT height = 768) override;

	virtual void Release() override;
	virtual void Render() override;

	void onClick(int mouseX, int mouseY);

	void CreateCards();
	virtual int GameLoop() override;
	inline size_t GetSize() { return mCardList.size(); }
};

