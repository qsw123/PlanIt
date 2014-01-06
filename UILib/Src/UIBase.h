#pragma once
//system headers
#include <windows.h>
#include <windowsx.h>
//c/c++ lib headers
#include <string>
#include <fstream>
//custom headers
#include "UIConsole.h"
//macro
//global vars
//any other declaration

typedef std::basic_string<TCHAR> tstring; //使用关联容器时需要特例化std::less, 此特例化不能放在自己的命名空间内。使用#define tstring std::wstring无此问题
typedef std::basic_ofstream<TCHAR> tofstream;
template <> struct std::less<tstring> : public binary_function <tstring, tstring, bool>
{bool operator()(const tstring& key1, const tstring& key2) const{return key1 < key2;}};

namespace UILib
{
	
	

	class UIPos : public POINT
	{
	public:
		UIPos(long x_ = 0, long y_ = 0) { this->x = x_; this->y = y_; }
		UIPos(const POINT& src)			{ this->x = src.x; this->y = src.y; }
		UIPos(LPARAM lParam)			{ this->x = GET_X_LPARAM(lParam); this->y = GET_Y_LPARAM(lParam); }

		UIPos operator + (const UIPos& src)		{ return UIPos(this->x + src.x, this->y + src.y); }
		UIPos operator - (const UIPos& src)		{ return UIPos(this->x - src.x, this->y - src.y); }
		UIPos& operator += (const UIPos& src)	{ this->x += src.x; this->y += src.y; return *this; }
		UIPos& operator -= (const UIPos& src)	{ this->x -= src.x; this->y -= src.y; return *this; }

		void	SetX(long x_)	{ this->x = x_; }
		long	GetX()			{ return this->x; }
		void	SetY(long y_)	{ this->y = y_; }
		long	GetY()			{ return this->y; }
	};

	class UISize : public SIZE
	{
	public:
		UISize(long cx_ = 0, long cy_ = 0)	{ this->cx = cx_; this->cy = cy_; }
		UISize(const UISize& src)			{ this->cx = src.cx; this->cy = src.cy; }

		UISize operator + (const UISize& src)		{ return UISize(this->cx + src.cx, this->cy + src.cy); }
		UISize operator - (const UISize& src)		{ return UISize(this->cx < src.cx ? 0 : this->cx - src.cy, this->cy < src.cy ? 0 : this->cy - src.cy); }
		UISize& operator += (const UISize& src)		{ this->cx += src.cx; this->cy += src.cy; return *this; }
		UISize& operator -= (const UISize& src)		{ this->cx > src.cx ? this->cx -= src.cx : this->cx = 0; this->cy > src.cy ? this->cy -= src.cy : this->cy = 0; return *this; }

		void	SetWidth(long cx_)	{ this->cx = cx_; }
		long	GetWidth()			{ return this->cx; }
		void	SetHeight(long cy_)	{ this->cy = cy_; }
		long	GetHeight()			{ return this->cy; }

	};

}//namespace UILib