#pragma once
//system headers
//c/c++ lib headers
//custom headers
#include "UIBase.h"
//macro
//global vars
//any other declaration

namespace UILib
{
#ifndef Assert
#if defined(DEBUG) || defined(_DEBUG)
#define Assert(b) do{if (!(b)){::OutputDebugStringA(("Assert: " #b "\r\n"));}}while(0)
#else
#define Assert(b)
#endif
#endif

	class UIApp;
	class UIDbg
	{
	friend class UIApp; //只有UIAPP能释放DBG文件。
	public:
		virtual void Printf(TCHAR* szFormat, ...);

	protected:
		virtual void OutPut(tstring outStr) = 0;
		virtual void Format();

	protected:
		virtual ~UIDbg(){};
		static const int MAX_BUF_SIZE = 1024;
	};

	class UIDbgToConsole : public UIDbg
	{
	public:
		static UIDbgToConsole* GetInstancePtr();

	protected:
		void   OutPut(tstring outStr);

	private:
		UIDbgToConsole();
	private:
		CConsole m_Console;
	};

	class UIDbgToFile : public UIDbg
	{
	public:
		static UIDbgToFile* GetInstancePtr();

	public:
		~UIDbgToFile() {this->m_File.close();}
	protected:
		void OutPut(tstring outStr);
	
	private:
		UIDbgToFile(tstring fileName = TEXT("./debug/UILib_Debug.log"));

	private:
		tofstream	m_File;
		tstring		m_FileName;
	};

	#define DBG_PRINT UIApp::GetInstanceRef().m_pDbg->Printf(TEXT("L%d - %s"), __LINE__, TEXT(__FUNCTION__)); \
				  UIApp::GetInstanceRef().m_pDbg->Printf

#define DBG_PRINT_CON UIDbgToConsole::GetInstancePtr()->Printf(TEXT("L%d - %s"), __LINE__, TEXT(__FUNCTION__)); \
	UIDbgToConsole::GetInstancePtr()->Printf
};