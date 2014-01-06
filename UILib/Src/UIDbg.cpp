//system headers
//c/c++ lib headers
//custom headers
#include "UIDbg.h"
#include "UIException.h"
//macro

//global vars
//any other declaration
using namespace UILib;


//functions
void UIDbg::Printf(TCHAR* szFormat, ...)
{
	TCHAR			szMsg[MAX_BUF_SIZE] = {0};
	va_list			pArg;

	va_start(pArg, szFormat);
	::wvsprintf(szMsg, szFormat, pArg);
	va_end(pArg);

	this->Format();
	this->OutPut(szMsg);
}

void UIDbg::Format()
{
}

UIDbgToConsole* UIDbgToConsole::GetInstancePtr()
{
	static UIDbgToConsole* pInst = NULL;

	if (NULL == pInst)
	{
		pInst = new UIDbgToConsole();
		pInst->m_Console.Create();
	}

	return pInst;
}

UIDbgToConsole::UIDbgToConsole()
{
	if (!this->m_Console.Create()) throw (UIException(TEXT("create console failed.")));;
}

void UIDbgToConsole::OutPut(tstring outStr)
{
	this->m_Console.Write((outStr + TEXT("\r\n")).c_str());
}

UIDbgToFile* UIDbgToFile::GetInstancePtr()
{
	static UIDbgToFile* pInst = NULL;

	if (NULL == pInst)
	{
		pInst = new UIDbgToFile();
	}

	return pInst;
}

UIDbgToFile::UIDbgToFile(tstring fileName /*= TEXT("./debug/1.log")*/) : m_FileName(fileName)
{
	
	this->m_File.open(this->m_FileName.c_str(), std::ios::trunc);
	if (!this->m_File.is_open()) throw (UIException(TEXT("open debug file failed.")));
}

void UIDbgToFile::OutPut(tstring outStr)
{
	this->m_File << outStr << std::endl;
//m_File.flush();
}


