#pragma once
//system headers
#include <tchar.H>
//c/c++ lib headers
#include <cassert>
//custom headers
#include "UIRender.h"
#include "UIDbg.h"
#include "UIRes.h"
#include "UIWndBase.h"
//macro
//global vars
//any other declaration
using namespace UILib;

UIRender::UIRender() : m_pWnd(NULL), m_pRenderTarget(NULL), m_pBitmap(NULL), m_pBitmap1(NULL)
{

}

UIRender::~UIRender()
{
	this->DiscardResource();
}

HRESULT UIRender::Init(UIWndBase* pWnd)
{
	HRESULT hr = S_OK;

	Assert(NULL != pWnd);

	this->m_pWnd = pWnd;

	hr = this->CreateDeviceResource();

	return hr;
}

HRESULT UIRender::CreateDeviceResource()
{
	HRESULT hr = S_OK;

	Assert(NULL != this->m_pWnd);

	if (!this->m_pRenderTarget)
	{
		D2D1_SIZE_U size = D2D1::SizeU(this->m_pWnd->GetSize().GetWidth(), this->m_pWnd->GetSize().GetHeight());
		hr = UIRes::GetInstancePtr()->m_pD2DFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(this->m_pWnd->GetHwnd(), size),
			&(this->m_pRenderTarget));

		if (!SUCCEEDED(hr)) return hr;
	}

	/*IWICFormatConverter* pConverter = UIRes::GetInstancePtr()->LoadBitmapFromFile(_T("D:/Ñ§Ï°×ÊÁÏ/Projects/VS2012/PlanIt/res/btn_mini_normal.png"), 0, 0);
	hr = m_pRenderTarget->CreateBitmapFromWicBitmap(
		pConverter,
		NULL,
		&m_pBitmap1
		);
		*/
	assert(SUCCEEDED(hr));
	return hr;
}

void UIRender::DiscardResource()
{
	SafeRelease(&(this->m_pRenderTarget));
}

void UIRender::OnRend()
{
	
	//if (!SUCCEEDED(hr)) return;
//	this->m_pRenderTarget->BeginDraw();

	this->m_pRenderTarget->SetAntialiasMode(D2D1_ANTIALIAS_MODE_FORCE_DWORD);
//	this->m_pRenderTarget->DrawBitmap(this->m_pBitmap, D2D1::RectF(0, 0, this->m_pWnd->GetSize().GetWidth(), this->m_pWnd->GetSize().GetHeight()));
	//this->m_pRenderTarget->DrawBitmap(this->m_pBitmap1, D2D1::RectF(0, 0, 30, 20));

	//this->m_pRenderTarget->EndDraw();


}