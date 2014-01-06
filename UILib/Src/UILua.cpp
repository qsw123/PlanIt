#include "cassert"

#include "UILua.h"


using namespace UILib;

UILua::UILua()
{
	this->m_pfErrorHandler		= NULL;
	this->m_pLua				= luaL_newstate();
	
	luaL_openlibs(this->m_pLua);
}

UILua::~UILua()
{
	if (NULL != this->m_pLua)
	{
		lua_close(this->m_pLua);
		this->m_pLua = NULL;
	}

	if (NULL != this->m_pfErrorHandler)
	{
		this->m_pfErrorHandler = NULL;
	}
}

bool UILua::AddFunction(const char* strFuncName, PFLuaFuncType pfLuaFunc)
{
	assert(NULL != strFuncName && NULL != pfLuaFunc);

	bool bRet = true;

	lua_register(this->m_pLua, strFuncName, pfLuaFunc);

	return bRet;
}

const char* UILua::GetErrorString()
{
	return luaL_checkstring(this->m_pLua, -1);
}