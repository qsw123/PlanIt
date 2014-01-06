#pragma once

#ifndef WINVER
#define WINVER 0X700
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x700
#endif

//#define WIN32_LEAN_AND_MEAN
//system headers
#include <Windows.h>
#include <GdiPlus.h>
#include <D2D1.h>
#include <D2D1Helper.h>
#include <DWrite.h>
#include <Wincodec.h>
//c/c++ lib headers
#include <map>
//custom headers
#include "UIBase.h"
//macro
//global vars
//any other declaration

namespace UILib
{
	template <class Interface>
	inline void SafeRelease(Interface** ppInterface)
	{
		if (NULL != *ppInterface)
		{
			(*ppInterface)->Release();
			(*ppInterface) = NULL;
		}
	}


	class UIRes
	{
	public:
		typedef IWICFormatConverter							Img_TYPE, *Ptr_Img_Type;
		typedef std::map<tstring, Ptr_Img_Type>				Img_Map;
		typedef std::map<tstring, Ptr_Img_Type>::iterator	Img_Map_Iterator;

	public:
		static	UIRes*	GetInstancePtr();

		bool	Init();

		Ptr_Img_Type	LoadBitmapFromFile(tstring fileName, UINT destinationWidth = 0, UINT destinationHeight = 0);

		Ptr_Img_Type	FindImage(tstring imgName);
		void			AddImage(tstring imgName, Ptr_Img_Type pImg);
		void			RemoveImage(tstring imgName);

		~UIRes();
	private:
		UIRes();
		HRESULT		CreateDeviceIndependResource();

	public:
		static ULONG_PTR		m_DGiplusToken;

		ID2D1Factory*			m_pD2DFactory;
		IWICImagingFactory*		m_pWICFactory;
		IDWriteFactory*			m_pDWriteFactory;
		IDWriteTextFormat*		m_pDWriteTextFormat;

		Img_Map					m_ImgStore;
	};

}//namespace UILib
