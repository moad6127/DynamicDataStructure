#pragma once

#include<d2d1.h>
#include<wrl/client.h>

#include"ComExecption.h"


class D2DFramework
{
private:
	const LPCWSTR WINDOWS_CLASSNAME{ L"MyD2DWindowClass" };

protected:
	HWND mHwnd;
	Microsoft::WRL::ComPtr<ID2D1Factory>			mspD2DFactory{};
	Microsoft::WRL::ComPtr<ID2D1HwndRenderTarget>	mspRenderTarget{};

protected:
	HRESULT InitWindow(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height);
	virtual HRESULT InitD2D(HWND hwnd);
	virtual HRESULT CreateDeviceResources();

public:
	virtual HRESULT Initialize(HINSTANCE hInstance, LPCWSTR title =L"D2DFramwork",UINT width = 1024, UINT height = 768);
	virtual void Release();
	virtual void Render();
	virtual int GameLoop();
	
	void ShowErrorMsg(LPCWSTR msg, HRESULT error = 0, LPCWSTR title = L"ERROR");
	static LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
	ID2D1HwndRenderTarget* GetRenderTarget() { return mspRenderTarget.Get(); }
	inline HWND GetWindowHandle() const { return mHwnd; }
};

