#include "BitmapManager.h"
#include "ComExecption.h"
#pragma comment (lib,"WindowsCodecs.lib")

using namespace std;
using namespace Microsoft::WRL;



HRESULT BitmapManager::Inintialize(ID2D1HwndRenderTarget* pRT)
{
	if (pRT == nullptr)
	{
		return E_FAIL;
	}
	mpRenderTarget = pRT;
	HRESULT hr = CoCreateInstance(
		CLSID_WICImagingFactory,
		nullptr,
		CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(mspWICFactory.GetAddressOf())
	);
	ThrowIfFailed(hr,"Can not Initialize COM!");

	return S_OK;
}

void BitmapManager::Release()
{
	for (auto& bitmap : mBitmapResources)
	{
		bitmap.second.Reset();
	}
	mBitmapResources.clear();
	mspWICFactory.Reset();

}

HRESULT BitmapManager::LoadWICBitmap(std::wstring filename, ID2D1Bitmap** ppBitmap)
{
    //Decoder 만들기
    Microsoft::WRL::ComPtr<IWICBitmapDecoder> bitmapDecoder;
    HRESULT hr;
    auto pRT{ mpRenderTarget };
    if (pRT == nullptr)
    {
        return E_FAIL;
    }

    auto pWICFactory{ mspWICFactory.Get()};
    if (pWICFactory == nullptr)
    {
        return E_FAIL;
    }

    hr = pWICFactory->CreateDecoderFromFilename(
        filename.c_str(),
        nullptr,
        GENERIC_READ,
        WICDecodeMetadataCacheOnLoad,
        bitmapDecoder.GetAddressOf()
    );
    ThrowIfFailed(hr);


    //Frame 만들기
    Microsoft::WRL::ComPtr<IWICBitmapFrameDecode> frame;
    hr = bitmapDecoder->GetFrame(0, frame.GetAddressOf());
    ThrowIfFailed(hr);

    //Converter 
    Microsoft::WRL::ComPtr<IWICFormatConverter> converter;
    hr = pWICFactory->CreateFormatConverter(converter.GetAddressOf());

    hr = converter->Initialize(
        frame.Get(),
        GUID_WICPixelFormat32bppPBGRA,
        WICBitmapDitherTypeNone,
        nullptr,
        0,
        WICBitmapPaletteTypeCustom
    );
    ThrowIfFailed(hr);

    //Bitmap
    hr = pRT->CreateBitmapFromWicBitmap(
        converter.Get(),
        ppBitmap
    );
    ThrowIfFailed(hr);

    return S_OK;
}

ID2D1Bitmap* BitmapManager::LoadBitmap(std::wstring filename)
{
    if(mspWICFactory == nullptr)
    {
        return nullptr;
    }
    auto result = mBitmapResources.insert({filename, nullptr});
    if (result.second)
    {
        auto spBitmap = ComPtr<ID2D1Bitmap>();
        LoadWICBitmap(filename, spBitmap.GetAddressOf());
        result.first->second = spBitmap;
    }
	return result.first->second.Get();
}
