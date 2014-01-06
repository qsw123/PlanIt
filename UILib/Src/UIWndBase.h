#pragma once
//system headers
//c/c++ lib headers
//custom headers
#include "UIBase.h"
#include "UIRender.h"
#include "UIControl.h"
//macro

//global vars

//any other declaration

namespace UILib
{

	class UIWndBase
	{
	public:
		static LRESULT CALLBACK DefWndProc(HWND, UINT, WPARAM, LPARAM);

	public:
		virtual BOOL		OnCreate(LPCREATESTRUCT lpCreateStruct);
		virtual void		OnClose();
		virtual bool		OnEraseBkGnd(HDC hdc){return true;}
		virtual void		OnPaint();
		virtual void		OnSize(UINT state, int cx, int cy);
		virtual void		OnLButtonDown(BOOL fDoubleClick, int x, int y, UINT keyFlags);

	public:
		bool				Create();
		int					Show();
		virtual	LRESULT		WndProc(UINT, WPARAM, LPARAM);

	public:
		tstring		GetName() const			{ return this->m_Name; }
		long		GetStyle()				{ return WS_OVERLAPPEDWINDOW; }
		UIPos		GetPos()				{ return this->m_Pos; }
		UISize		GetSize()				{ return this->m_Size; }

		HWND		GetHwnd()				{ return this->m_hWnd; }
		UIWndBase*	GetParentPtr() const	{ return this->m_pParent; }


	protected: 
		bool		        GetProfile(tstring profileName = TEXT(""));
		void		        GetDefaultProfile();
        virtual HINSTANCE   GetHinstance() { return ::GetModuleHandle(0); };

	public:
		UIWndBase();
		~UIWndBase();

	protected:
		virtual tstring		GetClassName()  { return tstring(TEXT("UIWnd_"));}
		virtual bool		RegisgerClass();

	private:
		HWND		m_hWnd;
		UIWndBase*	m_pParent;

		//props
		tstring		m_Name;
		UIPos		m_Pos;
		UISize		m_Size;
		UIRender	m_Render;

		UIControl*	m_pRootControl;
	};


	

}//namespace UILib