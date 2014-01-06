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
        //�������Ϣ������������������Ϣ��
        if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            //�Ƿ�Ϊ�˳�������Ϣ
            if (WM_QUIT == msg.message)
            {
                //������־��Ϣ
                break;
            }

            //������Ϣ���������
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
        }
        //���û����Ϣ����,����̨������
        else
        {
            this->OnIdle();
            
            ::Sleep(100); //�ó�cpu.
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