//system headers
//c/c++ lib headers
//custom headers
#include "UIImage.h"
#include "UIDbg.h"
#include "UIApp.h"
//macro

//global vars
extern "C"
{
    extern unsigned char *stbi_load_from_memory(unsigned char const *buffer, int len, int *x, int *y,
												int *comp, int req_comp);
	extern void     stbi_image_free(void *retval_from_stbi_load);

};
//any other declaration
#pragma comment(lib, "gdiplus.lib")
using namespace UILib;
//functions
UIImage::UIImage(tstring imageName) : m_Image(imageName.c_str())
{
	this->m_hBitmap			= 0;
	this->m_nX				= 0;
	this->m_nY				= 0;
	this->m_alphaChannel	= 0;
	this->m_dwMask			= 0;

	this->Load(imageName.c_str(), this->m_dwMask);

	Gdiplus::Color color(255,255,255);
	this->m_Image.GetHBITMAP(color, &this->m_hBitmap);

}

UIImage::~UIImage()
{
	if (0 != this->m_hBitmap)
	{
		::DeleteObject(this->m_hBitmap);
		m_hBitmap = 0;
	}
}

void UIImage::Draw(HDC hdcDest, UIPos dPos, UISize dSize)
{

	//::BitBlt(hdcDest, dPos.GetX(), dPos.GetY(), dSize.GetWidth(), dSize.GetHeigth(),
	//			 hdcBmp, 0, 0,  SRCCOPY);
	//::SelectObject(hdcBmp, hOldBitmap);

	 Gdiplus::Bitmap bmp(dSize.GetWidth(), dSize.GetHeight());

	 Gdiplus::Graphics bmpGraphics(&bmp);

	bmpGraphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
	
	bmpGraphics.DrawImage(&m_Image, dPos.GetX(), dPos.GetY(),  dSize.GetWidth(), dSize.GetHeight());

	/*Drawing on DC*/
	 Gdiplus::Graphics graphics(hdcDest);
	/*Important! Create a CacheBitmap object for quick drawing*/
	 Gdiplus::CachedBitmap cachedBmp(&bmp,&graphics);
	graphics.DrawCachedBitmap(&cachedBmp,0,0);
}

bool UIImage::Load(tstring imgFile, DWORD dwMask)
{
	bool	bRet	= false;
    LPBYTE	pData	= NULL;
    DWORD	dwSize	= 0;
	HANDLE	hFile	= 0;	
	
	do
	{
		hFile = ::CreateFile(imgFile.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL,
										 OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (NULL == hFile) break;
		
		dwSize = ::GetFileSize(hFile, NULL);
		if (0 == dwSize) {break;}

		pData = new BYTE[dwSize];
		DWORD dwRead = 0;
		::ReadFile(hFile, pData, dwSize, &dwRead, NULL);

		if (dwSize != dwRead) {break;}

		LPBYTE pImage = NULL;
		int x,y,n;
		pImage = stbi_load_from_memory(pData, dwSize, &x, &y, &n, 4);
		if (NULL == pImage) break;
		
		 BITMAPINFO bmi;
		::ZeroMemory(&bmi, sizeof(BITMAPINFO));
		bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bmi.bmiHeader.biWidth = x;
		bmi.bmiHeader.biHeight = -y;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biCompression = BI_RGB;
		bmi.bmiHeader.biSizeImage = x * y * 4;

		bool bAlphaChannel = false;
		LPBYTE pDest = NULL;
		HBITMAP hBitmap = ::CreateDIBSection(NULL, &bmi, DIB_RGB_COLORS, (void**)&pDest, NULL, 0);
		if( !hBitmap ) break;

		for( int i = 0; i < x * y; i++ ) 
		{
			pDest[i*4 + 3] = pImage[i*4 + 3];
			if( pDest[i*4 + 3] < 255 )
			{
				pDest[i*4] = (BYTE)(DWORD(pImage[i*4 + 2])*pImage[i*4 + 3]/255);
				pDest[i*4 + 1] = (BYTE)(DWORD(pImage[i*4 + 1])*pImage[i*4 + 3]/255);
				pDest[i*4 + 2] = (BYTE)(DWORD(pImage[i*4])*pImage[i*4 + 3]/255); 
				bAlphaChannel = true;
			}
			else
			{
				pDest[i*4] = pImage[i*4 + 2];
				pDest[i*4 + 1] = pImage[i*4 + 1];
				pDest[i*4 + 2] = pImage[i*4]; 
			}

			if( *(DWORD*)(&pDest[i*4]) == dwMask ) {
				pDest[i*4] = (BYTE)0;
				pDest[i*4 + 1] = (BYTE)0;
				pDest[i*4 + 2] = (BYTE)0; 
				pDest[i*4 + 3] = (BYTE)0;
				bAlphaChannel = true;
			}
		}

		stbi_image_free(pImage);

		this->m_hBitmap			= hBitmap;
		this->m_nX				= x;
		this->m_nY				= y;
		this->m_alphaChannel	= bAlphaChannel;

		bRet = true;
	}while(0);

	if (NULL != hFile) {::CloseHandle(hFile); hFile = NULL;}
	if (NULL != pData) {delete [] pData; pData = NULL; }

	return bRet;
}