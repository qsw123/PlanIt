#pragma once

extern "C"
{
#include "../../3rd/lua523/include/lua.h"
#include "../../3rd/lua523/include/lualib.h"
#include "../../3rd/lua523/include/lauxlib.h"

typedef int(*PFLuaFuncType)(lua_State* pLuaState);
}

namespace UILib
{
	class UILua
	{
	public:
		UILua();
		~UILua();

		bool			AddFunction(const char* strFuncName, PFLuaFuncType pfLuaFunc);
		const char*		GetErrorString();
	private:
		lua_State* m_pLua;
		void(*m_pfErrorHandler)(const char* pError);
	};
}