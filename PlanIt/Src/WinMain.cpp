//system headers
#include <windows.h>

//c/c++ lib headers

//custom headers
#include "CPub.h"
#include "UIApp.h"

//macro

//global vars

//any other declaration

//functions
using namespace UILib;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE /*hPreInst*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	int iRet = 0;
	// Ignore the return value because we want to run the program even in the
    // unlikely event that HeapSetInformation fails.
    HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);
	
	try
	{
		
	UIApp& app = UIApp::GetInstanceRef();

        app.SetHInstance(hInst);
		app.Init();

		UIWndBase mainWnd;
		mainWnd.Create();
		mainWnd.Show();

		app.Run();
		iRet = app.Term();
	}
	catch (UIException e)
	{
		e.What();
	}
	catch (...)
	{
		::MessageBox(0,0,0,0);
	}

	return iRet;
}