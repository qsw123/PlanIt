#pragma once
//system headers
//c/c++ lib headers

//custom headers
#include "UIBase.h"
#include "UIRes.h"
#include "UIRender.h"
//macro
//global vars
//any other declaration
namespace UILib
{
	class UIControl
	{
	public:
		enum UICONTROL_STATUS
		{
			NORMAL		=	0, //init
			HOVER		=	1, 
			INACTIVE	=	2, 
			ACTIVE		=	3,

			END_INVALID,	// 结束，不作为状态
		};

	public:
		UIControl(UIPos pos, UISize size, UIRender* pRender, UICONTROL_STATUS status = UIControl::NORMAL);

		ID2D1Bitmap*	GetImage();

		void			Show(UIRender* pRender);
		void			SetStatus(UICONTROL_STATUS status);
		void			SetStatusImage(UICONTROL_STATUS status, tstring imgName);
		void			ReSize(UISize newSize);


	private:
		UIPos					m_Pos;
		UISize					m_Size;
		UICONTROL_STATUS		m_Status;
		ID2D1Bitmap*			m_Images[END_INVALID];
		UIRender*				m_pRender;
	};
}//namespace UILib