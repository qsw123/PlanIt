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
#include <D2D1.h>
#include <D2D1Helper.h>
#include <DWrite.h>
#include <Wincodec.h>
//c/c++ lib headers
//custom headers

//macro
//global vars
//any other declaration

namespace UILib
{
	class UIWndBase;
	class UIRender
	{
	public:
		UIRender();
		~UIRender();

		HRESULT Init(UIWndBase* pWnd);
		HRESULT CreateDeviceResource();
		void	OnRend();


		void DiscardResource();
	
	public:
		UIWndBase*				m_pWnd;
		ID2D1HwndRenderTarget*	m_pRenderTarget;
		ID2D1Bitmap*			m_pBitmap;
		ID2D1Bitmap*			m_pBitmap1;
	};
}