//system headers
#include <windowsx.h>
#include <TCHAR.H>
//c/c++ lib headers
#include <cassert>
//custom headers
#include "UIWndBase.h"
#include "UIMsgCracker.h"
#include "UIException.h"
#include "UIDbg.h"
#include "UIApp.h"
#include "UIImage.h"

//macro

//global vars

//any other declaration

//functions
using namespace UILib;

void UIWndBase::OnClose()
{
	::PostQuitMessage(0);
}

void UIWndBase::OnPaint()
{
	PAINTSTRUCT ps;
	::BeginPaint(this->m_hWnd, &ps);

	this->m_Render.m_pRenderTarget->BeginDraw();
	this->m_Render.m_pRenderTarget->Clear();

	this->m_pRootControl->Show(&(this->m_Render));
	this->m_Render.OnRend();

	this->m_Render.m_pRenderTarget->EndDraw();

	::EndPaint(this->m_hWnd, &ps);
}

void UIWndBase::OnSize(UINT state, int cx, int cy)
{
	this->m_Size.SetWidth(cx);
	this->m_Size.SetHeight(cy);

	if (m_Render.m_pRenderTarget)
	{
		D2D1_SIZE_U size;
		size.width = cx;
		size.height = cy;

		// Note: This method can fail, but it's okay to ignore the
		// error here -- it will be repeated on the next call to
		// EndDraw.
		m_Render.m_pRenderTarget->Resize(size);
	}

	this->m_pRootControl->ReSize(UISize(cx, cy));
}

BOOL UIWndBase::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	BOOL bRet = true;

	this->m_pRootControl = new UIControl(UIPos(0, 0), UISize(this->GetSize().GetWidth(), this->GetSize().GetHeight()), &(this->m_Render));
	this->m_pRootControl->SetStatusImage(UIControl::NORMAL, _T("./res/blue.png"));
	this->m_pRootControl->SetStatusImage(UIControl::ACTIVE, _T("./res/wood.jpg"));

	return bRet;
}

void UIWndBase::OnLButtonDown(BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
	
	this->m_pRootControl->SetStatus(UIControl::ACTIVE);
	::InvalidateRect(this->m_hWnd, NULL, TRUE);
}


LRESULT UIWndBase::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT lRet = 0L;
	
	switch(uMsg)
	{
		UI_HANDLE_MSG(WM_CREATE,		OnCreate);
		UI_HANDLE_MSG(WM_CLOSE,			OnClose);
		UI_HANDLE_MSG(WM_ERASEBKGND,	OnEraseBkGnd);
		UI_HANDLE_MSG(WM_PAINT,			OnPaint);
		UI_HANDLE_MSG(WM_SIZE,			OnSize);
		UI_HANDLE_MSG(WM_LBUTTONDOWN,	OnLButtonDown);

	default:
		break;
	}

	return ::DefWindowProc(this->m_hWnd, uMsg, wParam, lParam);
}


UIWndBase::UIWndBase() : m_pRootControl(NULL)
{
    if (!this->GetProfile())
	{
		this->GetDefaultProfile();
	}
}

UIWndBase::~UIWndBase()
{

}

LRESULT CALLBACK UIWndBase::DefWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	UIWndBase* pThis = NULL;

	switch (uMsg)
	{
	case WM_NCCREATE:
		{
			assert(!::IsBadReadPtr((void*)lParam, sizeof (CREATESTRUCT)));
			LPCREATESTRUCT lpCs = reinterpret_cast<LPCREATESTRUCT> (lParam);
			
			pThis = static_cast<UIWndBase*>(lpCs->lpCreateParams);
			pThis->m_hWnd = hWnd;
			pThis->m_Render.Init(pThis);
			::SetWindowLongPtr(hWnd, GWL_USERDATA, reinterpret_cast<LPARAM>(pThis));
			
			break;
		}

	default:
		{
			pThis = reinterpret_cast<UIWndBase*>(::GetWindowLongPtr(hWnd, GWL_USERDATA));
			break;
		}
	}//switch
	
	if (NULL != pThis)
	{
		return pThis->WndProc(uMsg, wParam, lParam);
	}


	return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
}






bool UIWndBase::GetProfile(tstring profileName)
{
    bool bRet = false;

    return bRet;
}

void UIWndBase::GetDefaultProfile()
{
    this->m_hWnd	= NULL;
    this->m_Name	= TEXT("UIWndBase");
    this->m_Pos		= UIPos(CW_USEDEFAULT, CW_USEDEFAULT);
    this->m_pParent = NULL;
    this->m_Size	= UISize(800, 600);
    this->m_hWnd	= 0;
}

bool UIWndBase::RegisgerClass()
{
	bool		bRet = false;
	tstring		className = this->GetClassName();
	WNDCLASSEX	wndClsEx;

	if (::GetClassInfoEx(this->GetHinstance(), className.c_str(), &wndClsEx))
	{
		bRet = true;;
	}
	else
	{
		::memset(&wndClsEx, 0, sizeof (WNDCLASSEX));
		
		wndClsEx.cbSize			=	sizeof (WNDCLASSEX);
		wndClsEx.hInstance		=	this->GetHinstance();
		wndClsEx.lpfnWndProc	=	UIWndBase::DefWndProc;
		wndClsEx.lpszClassName	=	className.c_str();
		wndClsEx.hbrBackground	=	GetStockBrush(NULL_BRUSH);
		wndClsEx.style			= CS_VREDRAW | CS_HREDRAW;

		if(::RegisterClassEx(&wndClsEx))
		{
			bRet = true;
		}
	}
	
	return bRet;
}


bool UIWndBase::Create()
{
	if (!this->RegisgerClass()) 
	{
		return false;
	}

	this->m_hWnd = ::CreateWindowEx(0, this->GetClassName().c_str(), this->GetName().c_str(), this->GetStyle(), 
									this->GetPos().GetX(), this->GetPos().GetY(), this->GetSize().GetWidth(), this->GetSize().GetHeight(), 
									this->GetParentPtr() == NULL ? 0 : this->GetParentPtr()->GetHwnd(), 0,
									this->GetHinstance(), this);
	return this->m_hWnd != NULL;
}

int UIWndBase::Show()
{
	return ::ShowWindow(this->m_hWnd, SW_SHOWNA);
}