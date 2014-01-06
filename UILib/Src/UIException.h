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
	class UIException
		{
		public:
			UIException(tstring info = TEXT("")){ this->m_InfoStr = info;}

		public:
			void What() {::MessageBox(0, m_InfoStr.c_str(), 0, 0);};

		private:
			tstring m_InfoStr;
		};
}//namespace UILib