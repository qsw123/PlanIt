#pragma once
//system headers
#include <windows.h>
//c/c++ lib headers
//custom headers
#include "UIBase.h"
#include "UIRes.h"
#include "UIDbg.h"
//macro
//global vars
//any other declaration

namespace UILib
{
#ifndef HINST_THISCOMPONENT
	EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif
    class UIApp
    {
    public:
        static  UIApp& GetInstanceRef();

    public:
        void    SetHInstance(HINSTANCE hInst) { this->m_hInst = hInst; }
        void    Run();
        int     Term();
        bool    Init();

    protected:
        virtual void OnIdle();

    private:
        UIApp()                             {}
        UIApp(const UIApp& src)             {}
        UIApp operator = (const UIApp& src) {}

    private:
        HINSTANCE	m_hInst;

	public:
		UIDbg*		m_pDbg;
		UIRes*		m_pRes;
    };
}//namespace UILib