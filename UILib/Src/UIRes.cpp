#pragma once
//system headers
//c/c++ lib headers
#include <cassert>
//custom headers
#include "UIRes.h"
#include "UIApp.h"
//macro
//global vars
//any other declaration
#pragma comment(lib, "gdiplus.lib")
using namespace UILib;

ULONG_PTR	UIRes::m_DGiplusToken = 0;


UIRes::UIRes() : m_pD2DFactory(NULL), m_pDWriteFactory(NULL), m_pWICFactory(NULL), m_pDWriteTextFormat(NULL)
{

}

UIRes::~UIRes()
{
	SafeRelease(&m_pD2DFactory);
	SafeRelease(&m_pDWriteFactory);
	SafeRelease(&m_pWICFactory);
	SafeRelease(&m_pDWriteTextFormat);

	Gdiplus::GdiplusShutdown(UIRes::m_DGiplusToken);
}

UIRes* UIRes::GetInstancePtr()
{
	static UIRes* pInst = NULL;

	if (NULL == pInst)
	{
		pInst = new UIRes();
	}

	return pInst;
}

bool UIRes::Init()
{
	bool bRet = true;

	Gdiplus::GdiplusStartupInput startupInput;

	Gdiplus::GdiplusStartup(&UIRes::m_DGiplusToken, &startupInput, NULL);

	if (!SUCCEEDED(this->CreateDeviceIndependResource())) bRet = false;

	assert(false != bRet);

	return bRet;
}


HRESULT UIRes::CreateDeviceIndependResource()
{
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &this->m_pD2DFactory); assert(SUCCEEDED(hr));
	if (!SUCCEEDED(hr)) return hr;

	hr = ::CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&(this->m_pWICFactory))); DBG_PRINT(TEXT("hr = %d"), hr);assert(SUCCEEDED(hr)); 
	if (!SUCCEEDED(hr)) return hr;

	hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(this->m_pDWriteFactory), reinterpret_cast<IUnknown **>(&this->m_pDWriteFactory)); assert(SUCCEEDED(hr));
	if (!SUCCEEDED(hr)) return hr;

	hr = this->m_pDWriteFactory->CreateTextFormat(L"Verdana", NULL, DWRITE_FONT_WEIGHT_NORMAL,
											      DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL,
												  12, L"", &(this->m_pDWriteTextFormat)); assert(SUCCEEDED(hr));
	if (!SUCCEEDED(hr)) return hr;
	this->m_pDWriteTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
	this->m_pDWriteTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

	return hr;

}

IWICFormatConverter* UIRes::LoadBitmapFromFile( tstring fileName,
												UINT destinationWidth,
												UINT destinationHeight
												)
{
	IWICBitmapDecoder *pDecoder = NULL;
	IWICBitmapFrameDecode *pSource = NULL;
	IWICStream *pStream = NULL;
	IWICFormatConverter *pConverter = NULL;
	IWICBitmapScaler *pScaler = NULL;

	tstring xxx = fileName;
	HRESULT hr = this->m_pWICFactory->CreateDecoderFromFilename(
		fileName.c_str(),
		NULL,
		GENERIC_READ,
		WICDecodeMetadataCacheOnLoad,
		&pDecoder
		);
	DBG_PRINT(TEXT("file: %s"), xxx.c_str());
	assert(SUCCEEDED(hr));

	if (SUCCEEDED(hr))
	{
		// Create the initial frame.
		hr = pDecoder->GetFrame(0, &pSource);
	}

	assert(SUCCEEDED(hr));

	if (SUCCEEDED(hr))
	{

		// Convert the image format to 32bppPBGRA
		// (DXGI_FORMAT_B8G8R8A8_UNORM + D2D1_ALPHA_MODE_PREMULTIPLIED).
		hr = this->m_pWICFactory->CreateFormatConverter(&pConverter);

	}
	
	assert(SUCCEEDED(hr));

	if (SUCCEEDED(hr))
	{
		
		// If a new width or height was specified, create an
		// IWICBitmapScaler and use it to resize the image.
		if (destinationWidth != 0 || destinationHeight != 0)
		{
			UINT originalWidth, originalHeight;
			hr = pSource->GetSize(&originalWidth, &originalHeight);

			assert(SUCCEEDED(hr));

			if (SUCCEEDED(hr))
			{
				if (destinationWidth == 0)
				{
					FLOAT scalar = static_cast<FLOAT>(destinationHeight) / static_cast<FLOAT>(originalHeight);
					destinationWidth = static_cast<UINT>(scalar * static_cast<FLOAT>(originalWidth));
				}
				else if (destinationHeight == 0)
				{
					FLOAT scalar = static_cast<FLOAT>(destinationWidth) / static_cast<FLOAT>(originalWidth);
					destinationHeight = static_cast<UINT>(scalar * static_cast<FLOAT>(originalHeight));
				}

				hr = this->m_pWICFactory->CreateBitmapScaler(&pScaler);

				assert(SUCCEEDED(hr));

				if (SUCCEEDED(hr))
				{
					hr = pScaler->Initialize(
						pSource,
						destinationWidth,
						destinationHeight,
						WICBitmapInterpolationModeCubic
						);
				}

				assert(SUCCEEDED(hr));

				if (SUCCEEDED(hr))
				{
					hr = pConverter->Initialize(
						pScaler,
						GUID_WICPixelFormat32bppPBGRA,
						WICBitmapDitherTypeNone,
						NULL,
						0.f,
						WICBitmapPaletteTypeMedianCut
						);
				}
			}
		}
		else // Don't scale the image.
		{
			hr = pConverter->Initialize(
				pSource,
				GUID_WICPixelFormat32bppPBGRA,
				WICBitmapDitherTypeNone,
				NULL,
				0.f,
				WICBitmapPaletteTypeMedianCut
				);
		}
	}

	assert(SUCCEEDED(hr));

	SafeRelease(&pDecoder);
	SafeRelease(&pSource);
	SafeRelease(&pStream);
	//SafeRelease(&pConverter);
	SafeRelease(&pScaler);

	pConverter = SUCCEEDED(hr) ? pConverter : NULL;
	return pConverter;
}

void UIRes::AddImage(tstring imgName, Ptr_Img_Type pImg)
{
	assert(NULL != pImg);

	/*insert方式不覆盖，[]方式才覆盖
	Img_Map_Iterator it = this->m_ImgStore.find(imgName);

	// if found, dont add
	if (this->m_ImgStore.end() != it)
	{
		return;
	}

	// not found, add it*/
	this->m_ImgStore.insert(std::pair<tstring, Ptr_Img_Type>(imgName, pImg));

	std::pair<Img_Map_Iterator, bool> ret;

	//assert(true == ret.second);
}

void UIRes::RemoveImage(tstring imgName)
{
	Img_Map_Iterator it = this->m_ImgStore.find(imgName);

	// if found, dont add
	if (this->m_ImgStore.end() != it)
	{
		this->m_ImgStore.erase(it);
	}
}

UIRes::Ptr_Img_Type UIRes::FindImage(tstring imgName)
{
	Ptr_Img_Type pImgOut = NULL;

	Img_Map_Iterator it = this->m_ImgStore.find(imgName);
	if (this->m_ImgStore.end() != it)
	{
		pImgOut = it->second;
	}

	//assert(NULL != pImgOut);
	return pImgOut;
}

