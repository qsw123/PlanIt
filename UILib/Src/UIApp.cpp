#pragma once
//system headers
//c/c++ lib headers
#include <cassert>
//custom headers
#include "UIApp.h"
//macro
//global vars
//any other declaration



//functions
using namespace UILib;

UIApp& UIApp::GetInstanceRef()
{
    static UIApp theInstance;

    return theInstance;;
}

bool UIApp::Init()
{
    bool bRet = true;

	HRESULT hr = ::CoInitialize(NULL); assert(SUCCEEDED(hr));
this->m_pDbg = UIDbgToFile::GetInstancePtr();
	this->m_pRes = UIRes::GetInstancePtr();
	this->m_pRes->Init();

	::LoadLibrary(TEXT("msimg32.dll"));

	
	if (NULL == this->m_pDbg) bRet = false;
	
    return bRet;
}

void UIApp::OnIdle()
{
}


void UIApp::Run()
{
    MSG     msg     = {0};


    while (1)
    {
        //如果有消息到来。解析并分配消息。
        if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            //是否为退出程序消息
            if (WM_QUIT == msg.message)
            {
                //增加日志信息
                break;
            }

            //其它消息解析后分配
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
        }
        //如果没有消息到来,做后台工作。
        else
        {
            this->OnIdle();
            
            ::Sleep(100); //让出cpu.
        }

    } //end: while(1)
}

int UIApp::Term()
{
    int     iRet = 0;

	assert(NULL != this->m_pDbg);
	delete this->m_pDbg;
	
	assert(NULL != this->m_pRes);
	delete this->m_pRes;

	::CoUninitialize();
    return iRet;
}