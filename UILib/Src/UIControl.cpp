//system headers

//c/c++ lib headers
#include <cassert>
//custom headers
#include "UIControl.h"
#include "UIDbg.h"
#include "UIApp.h"
//macro

//global vars

//any other declaration

//functions
using namespace UILib;

UIControl::UIControl(UIPos pos, UISize size, UIRender* pRender, UICONTROL_STATUS status/*=*/) : m_Pos(pos), m_Size(size), m_pRender(pRender), m_Status(status)
{
	::memset(this->m_Images, 0, sizeof (UIRes::Ptr_Img_Type) * UIControl::END_INVALID);
}

void UIControl::SetStatusImage(UICONTROL_STATUS status, tstring imgName)
{
	assert(status >= UIControl::NORMAL && status < UIControl::END_INVALID);
	UIRes*				pRes = UIRes::GetInstancePtr();
	UIRes::Ptr_Img_Type pImg = pRes->FindImage(imgName);
	DBG_PRINT(TEXT("nxxxxo found: %d"), this->m_Status);
	if (NULL != pImg)
	{//图片已载入，无需重新载入。
		DBG_PRINT(TEXT("no found: %d"), this->m_Status);
		return;
	}
	else
	{
		DBG_PRINT(TEXT("found: %d %s"), this->m_Status, imgName.c_str());
		pImg = pRes->LoadBitmapFromFile(imgName);
		assert(NULL != pImg);

		pRes->AddImage(imgName, pImg);
	}

	//this->m_Images[status] = pImg;

	HRESULT hr = this->m_pRender->m_pRenderTarget->CreateBitmapFromWicBitmap(pImg, NULL, &(this->m_Images[status]));
	assert(SUCCEEDED(hr));
}

void UIControl::SetStatus(UICONTROL_STATUS status)
{
	assert(status >= UIControl::NORMAL && status < UIControl::END_INVALID);

	this->m_Status = status;
}

ID2D1Bitmap* UIControl::GetImage()
{
	return this->m_Images[this->m_Status];
}

void UIControl::Show(UIRender* pRender)
{
	DBG_PRINT(TEXT("status: %d"), this->m_Status);
	pRender->m_pRenderTarget->DrawBitmap(this->GetImage(), D2D1::RectF(this->m_Pos.GetX(), this->m_Pos.GetY(), this->m_Size.GetWidth(), this->m_Size.GetWidth()));
}

void UIControl::ReSize(UISize newSize)
{
	this->m_Size = newSize;
}