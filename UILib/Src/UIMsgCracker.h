#pragma once


/****** Message crackers ****************************************************/

#define UI_HANDLE_MSG(message, fn)    \
    case (message): return UI_HANDLE_##message((wParam), (lParam), (fn))

/* void Cls_OnCompacting(UINT compactRatio) */
#define UI_HANDLE_WM_COMPACTING(wParam, lParam, fn) \
    ((fn)((UINT)(wParam)), 0L)
#define UI_FORWARD_WM_COMPACTING(compactRatio, fn) \
    (void)(fn)(WM_COMPACTING, (WPARAM)(UINT)(compactRatio), 0L)

/* void Cls_OnWinIniChange(LPCTSTR lpszSectionName) */
#define UI_HANDLE_WM_WININICHANGE(wParam, lParam, fn) \
    ((fn)((LPCTSTR)(lParam)), 0L)
#define UI_FORWARD_WM_WININICHANGE(lpszSectionName, fn) \
    (void)(fn)(WM_WININICHANGE, 0L, (LPARAM)(LPCTSTR)(lpszSectionName))

/* void Cls_OnSysColorChange() */
#define UI_HANDLE_WM_SYSCOLORCHANGE(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_SYSCOLORCHANGE(fn) \
    (void)(fn)(WM_SYSCOLORCHANGE, 0L, 0L)

/* BOOL Cls_OnQueryNewPalette() */
#define UI_HANDLE_WM_QUERYNEWPALETTE(wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(), 0L)
#define UI_FORWARD_WM_QUERYNEWPALETTE(fn) \
    (BOOL)(DWORD)(fn)(WM_QUERYNEWPALETTE, 0L, 0L)

/* void Cls_OnPaletteIsChanging(PaletteChange) */
#define UI_HANDLE_WM_PALETTEISCHANGING(wParam, lParam, fn) \
    ((fn)(()(wParam)), 0L)
#define UI_FORWARD_WM_PALETTEISCHANGING(PaletteChange, fn) \
    (void)(fn)(WM_PALETTEISCHANGING, (WPARAM)()(PaletteChange), 0L)

/* void Cls_OnPaletteChanged(PaletteChange) */
#define UI_HANDLE_WM_PALETTECHANGED(wParam, lParam, fn) \
    ((fn)(()(wParam)), 0L)
#define UI_FORWARD_WM_PALETTECHANGED(PaletteChange, fn) \
    (void)(fn)(WM_PALETTECHANGED, (WPARAM)()(PaletteChange), 0L)

/* void Cls_OnFontChange() */
#define UI_HANDLE_WM_FONTCHANGE(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_FONTCHANGE(fn) \
    (void)(fn)(WM_FONTCHANGE, 0L, 0L)

/* void Cls_OnSpoolerStatus(UINT status, int cJobInQueue) */
#define UI_HANDLE_WM_SPOOLERSTATUS(wParam, lParam, fn) \
    ((fn)((UINT)(wParam), (int)(short)LOWORD(lParam)), 0L)
#define UI_FORWARD_WM_SPOOLERSTATUS(status, cJobInQueue, fn) \
    (void)(fn)(WM_SPOOLERSTATUS, (WPARAM)(status), MAKELPARAM((cJobInQueue), 0))

/* void Cls_OnDevModeChange(LPCTSTR lpszDeviceName) */
#define UI_HANDLE_WM_DEVMODECHANGE(wParam, lParam, fn) \
    ((fn)((LPCTSTR)(lParam)), 0L)
#define UI_FORWARD_WM_DEVMODECHANGE(lpszDeviceName, fn) \
    (void)(fn)(WM_DEVMODECHANGE, 0L, (LPARAM)(LPCTSTR)(lpszDeviceName))

/* void Cls_OnTimeChange() */
#define UI_HANDLE_WM_TIMECHANGE(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_TIMECHANGE(fn) \
    (void)(fn)(WM_TIMECHANGE, 0L, 0L)

/* void Cls_OnPower(int code) */
#define UI_HANDLE_WM_POWER(wParam, lParam, fn) \
    ((fn)((int)(wParam)), 0L)
#define UI_FORWARD_WM_POWER(code, fn) \
    (void)(fn)(WM_POWER, (WPARAM)(int)(code), 0L)

/* BOOL Cls_OnQueryEndSession() */
#define UI_HANDLE_WM_QUERYENDSESSION(wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(), 0L)
#define UI_FORWARD_WM_QUERYENDSESSION(fn) \
    (BOOL)(DWORD)(fn)(WM_QUERYENDSESSION, 0L, 0L)

/* void Cls_OnEndSession(BOOL fEnding) */
#define UI_HANDLE_WM_ENDSESSION(wParam, lParam, fn) \
    ((fn)((BOOL)(wParam)), 0L)
#define UI_FORWARD_WM_ENDSESSION(fEnding, fn) \
    (void)(fn)(WM_ENDSESSION, (WPARAM)(BOOL)(fEnding), 0L)

/* void Cls_OnQuit(int exitCode) */
#define UI_HANDLE_WM_QUIT(wParam, lParam, fn) \
    ((fn)((int)(wParam)), 0L)
#define UI_FORWARD_WM_QUIT(exitCode, fn) \
    (void)(fn)(WM_QUIT, (WPARAM)(exitCode), 0L)

/* This message is in Windows 3.1 only */
/* void Cls_OnSystemError(int errCode) */
#define UI_HANDLE_WM_SYSTEMERROR(wParam, lParam, fn) 0L
#define UI_FORWARD_WM_SYSTEMERROR(errCode, fn) 0L

/* BOOL Cls_OnCreate(LPCREATESTRUCT lpCreateStruct) */
#define UI_HANDLE_WM_CREATE(wParam, lParam, fn) \
    ((fn)((LPCREATESTRUCT)(lParam)) ? 0L : (LRESULT)-1L)
#define UI_FORWARD_WM_CREATE(lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)(WM_CREATE, 0L, (LPARAM)(LPCREATESTRUCT)(lpCreateStruct))

/* BOOL Cls_OnNCCreate(LPCREATESTRUCT lpCreateStruct) */
#define UI_HANDLE_WM_NCCREATE(wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((LPCREATESTRUCT)(lParam))
#define UI_FORWARD_WM_NCCREATE(lpCreateStruct, fn) \
    (BOOL)(DWORD)(fn)(WM_NCCREATE, 0L, (LPARAM)(LPCREATESTRUCT)(lpCreateStruct))

/* void Cls_OnDestroy() */
#define UI_HANDLE_WM_DESTROY(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_DESTROY(fn) \
    (void)(fn)(WM_DESTROY, 0L, 0L)

/* void Cls_OnNCDestroy() */
#define UI_HANDLE_WM_NCDESTROY(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_NCDESTROY(fn) \
    (void)(fn)(WM_NCDESTROY, 0L, 0L)

/* void Cls_OnShowWindow(BOOL fShow, UINT status) */
#define UI_HANDLE_WM_SHOWWINDOW(wParam, lParam, fn) \
    ((fn)((BOOL)(wParam), (UINT)(lParam)), 0L)
#define UI_FORWARD_WM_SHOWWINDOW(fShow, status, fn) \
    (void)(fn)(WM_SHOWWINDOW, (WPARAM)(BOOL)(fShow), (LPARAM)(UINT)(status))

/* void Cls_OnSetRedraw(BOOL fRedraw) */
#define UI_HANDLE_WM_SETREDRAW(wParam, lParam, fn) \
    ((fn)((BOOL)(wParam)), 0L)
#define UI_FORWARD_WM_SETREDRAW(fRedraw, fn) \
    (void)(fn)(WM_SETREDRAW, (WPARAM)(BOOL)(fRedraw), 0L)

/* void Cls_OnEnable(BOOL fEnable) */
#define UI_HANDLE_WM_ENABLE(wParam, lParam, fn) \
    ((fn)((BOOL)(wParam)), 0L)
#define UI_FORWARD_WM_ENABLE(fEnable, fn) \
    (void)(fn)(WM_ENABLE, (WPARAM)(BOOL)(fEnable), 0L)

/* void Cls_OnSetText(LPCTSTR lpszText) */
#define UI_HANDLE_WM_SETTEXT(wParam, lParam, fn) \
    ((fn)((LPCTSTR)(lParam)), 0L)
#define UI_FORWARD_WM_SETTEXT(lpszText, fn) \
    (void)(fn)(WM_SETTEXT, 0L, (LPARAM)(LPCTSTR)(lpszText))

/* INT Cls_OnGetText(int cchTextMax, LPTSTR lpszText) */
#define UI_HANDLE_WM_GETTEXT(wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((int)(wParam), (LPTSTR)(lParam))
#define UI_FORWARD_WM_GETTEXT(cchTextMax, lpszText, fn) \
    (int)(DWORD)(fn)(WM_GETTEXT, (WPARAM)(int)(cchTextMax), (LPARAM)(LPTSTR)(lpszText))

/* INT Cls_OnGetTextLength() */
#define UI_HANDLE_WM_GETTEXTLENGTH(wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)()
#define UI_FORWARD_WM_GETTEXTLENGTH(fn) \
    (int)(DWORD)(fn)(WM_GETTEXTLENGTH, 0L, 0L)

/* BOOL Cls_OnWindowPosChanging(LPWINDOWPOS lpwpos) */
#define UI_HANDLE_WM_WINDOWPOSCHANGING(wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((LPWINDOWPOS)(lParam))
#define UI_FORWARD_WM_WINDOWPOSCHANGING(lpwpos, fn) \
    (BOOL)(DWORD)(fn)(WM_WINDOWPOSCHANGING, 0L, (LPARAM)(LPWINDOWPOS)(lpwpos))

/* void Cls_OnWindowPosChanged(const LPWINDOWPOS lpwpos) */
#define UI_HANDLE_WM_WINDOWPOSCHANGED(wParam, lParam, fn) \
    ((fn)((const LPWINDOWPOS)(lParam)), 0L)
#define UI_FORWARD_WM_WINDOWPOSCHANGED(lpwpos, fn) \
    (void)(fn)(WM_WINDOWPOSCHANGED, 0L, (LPARAM)(const LPWINDOWPOS)(lpwpos))

/* void Cls_OnMove(int x, int y) */
#define UI_HANDLE_WM_MOVE(wParam, lParam, fn) \
    ((fn)((int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam)), 0L)
#define UI_FORWARD_WM_MOVE(x, y, fn) \
    (void)(fn)(WM_MOVE, 0L, MAKELPARAM((x), (y)))

/* void Cls_OnSize(UINT state, int cx, int cy) */
#define UI_HANDLE_WM_SIZE(wParam, lParam, fn) \
    ((fn)((UINT)(wParam), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam)), 0L)
#define UI_FORWARD_WM_SIZE(state, cx, cy, fn) \
    (void)(fn)(WM_SIZE, (WPARAM)(UINT)(state), MAKELPARAM((cx), (cy)))

/* void Cls_OnClose() */
#define UI_HANDLE_WM_CLOSE(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_CLOSE(fn) \
    (void)(fn)(WM_CLOSE, 0L, 0L)

/* BOOL Cls_OnQueryOpen() */
#define UI_HANDLE_WM_QUERYOPEN(wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(), 0L)
#define UI_FORWARD_WM_QUERYOPEN(fn) \
    (BOOL)(DWORD)(fn)(WM_QUERYOPEN, 0L, 0L)

/* void Cls_OnGetMinMaxInfo(LPMINMAXINFO lpMinMaxInfo) */
#define UI_HANDLE_WM_GETMINMAXINFO(wParam, lParam, fn) \
    ((fn)((LPMINMAXINFO)(lParam)), 0L)
#define UI_FORWARD_WM_GETMINMAXINFO(lpMinMaxInfo, fn) \
    (void)(fn)(WM_GETMINMAXINFO, 0L, (LPARAM)(LPMINMAXINFO)(lpMinMaxInfo))

/* void Cls_OnPaint() */
#define UI_HANDLE_WM_PAINT(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_PAINT(fn) \
    (void)(fn)(WM_PAINT, 0L, 0L)

/* BOOL Cls_OnEraseBkgnd(HDC hdc) */
#define UI_HANDLE_WM_ERASEBKGND(wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((HDC)(wParam))
#define UI_FORWARD_WM_ERASEBKGND(hdc, fn) \
   (BOOL)(DWORD)(fn)(WM_ERASEBKGND, (WPARAM)(HDC)(hdc), 0L)

/* BOOL Cls_OnIconEraseBkgnd(HDC hdc) */
#define UI_HANDLE_WM_ICONERASEBKGND(wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((HDC)(wParam))
#define UI_FORWARD_WM_ICONERASEBKGND(hdc, fn) \
    (BOOL)(DWORD)(fn)(WM_ICONERASEBKGND, (WPARAM)(HDC)(hdc), 0L)

/* void Cls_OnNCPaint(HRGN hrgn) */
#define UI_HANDLE_WM_NCPAINT(wParam, lParam, fn) \
    ((fn)((HRGN)(wParam)), 0L)
#define UI_FORWARD_WM_NCPAINT(hrgn, fn) \
    (void)(fn)(WM_NCPAINT, (WPARAM)(HRGN)(hrgn), 0L)

/* UINT Cls_OnNCCalcSize(BOOL fCalcValidRects, NCCALCSIZE_PARAMS * lpcsp) */
#define UI_HANDLE_WM_NCCALCSIZE(wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((BOOL)(wParam), (NCCALCSIZE_PARAMS *)(lParam))
#define UI_FORWARD_WM_NCCALCSIZE(fCalcValidRects, lpcsp, fn) \
    (UINT)(DWORD)(fn)(WM_NCCALCSIZE, (WPARAM)(fCalcValidRects), (LPARAM)(NCCALCSIZE_PARAMS *)(lpcsp))

/* UINT Cls_OnNCHitTest(int x, int y) */
#define UI_HANDLE_WM_NCHITTEST(wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam))
#define UI_FORWARD_WM_NCHITTEST(x, y, fn) \
    (UINT)(DWORD)(fn)(WM_NCHITTEST, 0L, MAKELPARAM((x), (y)))

/* HICON Cls_OnQueryDragIcon() */
#define UI_HANDLE_WM_QUERYDRAGICON(wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)()
#define UI_FORWARD_WM_QUERYDRAGICON(fn) \
    (HICON)(UINT)(DWORD)(fn)(WM_QUERYDRAGICON, 0L, 0L)

#ifdef _INC_SHELLAPI
/* void Cls_OnDropFiles(HDROP hdrop) */
#define UI_HANDLE_WM_DROPFILES(wParam, lParam, fn) \
    ((fn)((HDROP)(wParam)), 0L)
#define UI_FORWARD_WM_DROPFILES(hdrop, fn) \
    (void)(fn)(WM_DROPFILES, (WPARAM)(HDROP)(hdrop), 0L)
#endif  /* _INC_SHELLAPI */

/* void Cls_OnActivate(UINT state, ActDeact, BOOL fMinimized) */
#define UI_HANDLE_WM_ACTIVATE(wParam, lParam, fn) \
    ((fn)((UINT)LOWORD(wParam), ()(lParam), (BOOL)HIWORD(wParam)), 0L)
#define UI_FORWARD_WM_ACTIVATE(state, ActDeact, fMinimized, fn) \
    (void)(fn)(WM_ACTIVATE, MAKEWPARAM((state), (fMinimized)), (LPARAM)()(ActDeact))

/* void Cls_OnActivateApp(BOOL fActivate, DWORD dwThreadId) */
#define UI_HANDLE_WM_ACTIVATEAPP(wParam, lParam, fn) \
    ((fn)((BOOL)(wParam), (DWORD)(lParam)), 0L)
#define UI_FORWARD_WM_ACTIVATEAPP(fActivate, dwThreadId, fn) \
    (void)(fn)(WM_ACTIVATEAPP, (WPARAM)(BOOL)(fActivate), (LPARAM)(dwThreadId))

/* BOOL Cls_OnNCActivate(BOOL fActive, ActDeact, BOOL fMinimized) */
#define UI_HANDLE_WM_NCACTIVATE(wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((BOOL)(wParam), 0L, 0L)
#define UI_FORWARD_WM_NCACTIVATE(fActive, ActDeact, fMinimized, fn) \
    (BOOL)(DWORD)(fn)(WM_NCACTIVATE, (WPARAM)(BOOL)(fActive), 0L)

/* void Cls_OnSetFocus(OldFocus) */
#define UI_HANDLE_WM_SETFOCUS(wParam, lParam, fn) \
    ((fn)(()(wParam)), 0L)
#define UI_FORWARD_WM_SETFOCUS(OldFocus, fn) \
    (void)(fn)(WM_SETFOCUS, (WPARAM)()(OldFocus), 0L)

/* void Cls_OnKillFocus(NewFocus) */
#define UI_HANDLE_WM_KILLFOCUS(wParam, lParam, fn) \
    ((fn)(()(wParam)), 0L)
#define UI_FORWARD_WM_KILLFOCUS(NewFocus, fn) \
    (void)(fn)(WM_KILLFOCUS, (WPARAM)()(NewFocus), 0L)

/* void Cls_OnKey(UINT vk, BOOL fDown, int cRepeat, UINT flags) */
#define UI_HANDLE_WM_KEYDOWN(wParam, lParam, fn) \
    ((fn)((UINT)(wParam), TRUE, (int)(short)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define UI_FORWARD_WM_KEYDOWN(vk, cRepeat, flags, fn) \
    (void)(fn)(WM_KEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((cRepeat), (flags)))

/* void Cls_OnKey(UINT vk, BOOL fDown, int cRepeat, UINT flags) */
#define UI_HANDLE_WM_KEYUP(wParam, lParam, fn) \
    ((fn)((UINT)(wParam), FALSE, (int)(short)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define UI_FORWARD_WM_KEYUP(vk, cRepeat, flags, fn) \
    (void)(fn)(WM_KEYUP, (WPARAM)(UINT)(vk), MAKELPARAM((cRepeat), (flags)))

/* void Cls_OnChar(TCHAR ch, int cRepeat) */
#define UI_HANDLE_WM_CHAR(wParam, lParam, fn) \
    ((fn)((TCHAR)(wParam), (int)(short)LOWORD(lParam)), 0L)
#define UI_FORWARD_WM_CHAR(ch, cRepeat, fn) \
    (void)(fn)(WM_CHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat),0))

/* void Cls_OnDeadChar(TCHAR ch, int cRepeat) */
#define UI_HANDLE_WM_DEADCHAR(wParam, lParam, fn) \
    ((fn)((TCHAR)(wParam), (int)(short)LOWORD(lParam)), 0L)
#define UI_FORWARD_WM_DEADCHAR(ch, cRepeat, fn) \
    (void)(fn)(WM_DEADCHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat),0))

/* void Cls_OnSysKey(UINT vk, BOOL fDown, int cRepeat, UINT flags) */
#define UI_HANDLE_WM_SYSKEYDOWN(wParam, lParam, fn) \
    ((fn)((UINT)(wParam), TRUE, (int)(short)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define UI_FORWARD_WM_SYSKEYDOWN(vk, cRepeat, flags, fn) \
    (void)(fn)(WM_SYSKEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((cRepeat), (flags)))

/* void Cls_OnSysKey(UINT vk, BOOL fDown, int cRepeat, UINT flags) */
#define UI_HANDLE_WM_SYSKEYUP(wParam, lParam, fn) \
    ((fn)((UINT)(wParam), FALSE, (int)(short)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define UI_FORWARD_WM_SYSKEYUP(vk, cRepeat, flags, fn) \
    (void)(fn)(WM_SYSKEYUP, (WPARAM)(UINT)(vk), MAKELPARAM((cRepeat), (flags)))

/* void Cls_OnSysChar(TCHAR ch, int cRepeat) */
#define UI_HANDLE_WM_SYSCHAR(wParam, lParam, fn) \
    ((fn)((TCHAR)(wParam), (int)(short)LOWORD(lParam)), 0L)
#define UI_FORWARD_WM_SYSCHAR(ch, cRepeat, fn) \
    (void)(fn)(WM_SYSCHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat), 0))

/* void Cls_OnSysDeadChar(TCHAR ch, int cRepeat) */
#define UI_HANDLE_WM_SYSDEADCHAR(wParam, lParam, fn) \
    ((fn)((TCHAR)(wParam), (int)(short)LOWORD(lParam)), 0L)
#define UI_FORWARD_WM_SYSDEADCHAR(ch, cRepeat, fn) \
    (void)(fn)(WM_SYSDEADCHAR, (WPARAM)(TCHAR)(ch), MAKELPARAM((cRepeat), 0))

/* void Cls_OnMouseMove(int x, int y, UINT keyFlags) */
#define UI_HANDLE_WM_MOUSEMOVE(wParam, lParam, fn) \
    ((fn)((int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define UI_FORWARD_WM_MOUSEMOVE(x, y, keyFlags, fn) \
    (void)(fn)(WM_MOUSEMOVE, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))

/* void Cls_OnLButtonDown(BOOL fDoubleClick, int x, int y, UINT keyFlags) */
#define UI_HANDLE_WM_LBUTTONDOWN(wParam, lParam, fn) \
    ((fn)(FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define UI_FORWARD_WM_LBUTTONDOWN(fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((fDoubleClick) ? WM_LBUTTONDBLCLK : WM_LBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))

/* void Cls_OnLButtonDown(BOOL fDoubleClick, int x, int y, UINT keyFlags) */
#define UI_HANDLE_WM_LBUTTONDBLCLK(wParam, lParam, fn) \
    ((fn)(TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)

/* void Cls_OnLButtonUp(int x, int y, UINT keyFlags) */
#define UI_HANDLE_WM_LBUTTONUP(wParam, lParam, fn) \
    ((fn)((int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define UI_FORWARD_WM_LBUTTONUP(x, y, keyFlags, fn) \
    (void)(fn)(WM_LBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))

/* void Cls_OnRButtonDown(BOOL fDoubleClick, int x, int y, UINT keyFlags) */
#define UI_HANDLE_WM_RBUTTONDOWN(wParam, lParam, fn) \
    ((fn)(FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define UI_FORWARD_WM_RBUTTONDOWN(fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((fDoubleClick) ? WM_RBUTTONDBLCLK : WM_RBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))

/* void Cls_OnRButtonDown(BOOL fDoubleClick, int x, int y, UINT keyFlags) */
#define UI_HANDLE_WM_RBUTTONDBLCLK(wParam, lParam, fn) \
    ((fn)(TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)

/* void Cls_OnRButtonUp(int x, int y, UINT flags) */
#define UI_HANDLE_WM_RBUTTONUP(wParam, lParam, fn) \
    ((fn)((int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define UI_FORWARD_WM_RBUTTONUP(x, y, keyFlags, fn) \
    (void)(fn)(WM_RBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))

/* void Cls_OnMButtonDown(BOOL fDoubleClick, int x, int y, UINT keyFlags) */
#define UI_HANDLE_WM_MBUTTONDOWN(wParam, lParam, fn) \
    ((fn)(FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define UI_FORWARD_WM_MBUTTONDOWN(fDoubleClick, x, y, keyFlags, fn) \
    (void)(fn)((fDoubleClick) ? WM_MBUTTONDBLCLK : WM_MBUTTONDOWN, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))

/* void Cls_OnMButtonDown(BOOL fDoubleClick, int x, int y, UINT keyFlags) */
#define UI_HANDLE_WM_MBUTTONDBLCLK(wParam, lParam, fn) \
    ((fn)(TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)

/* void Cls_OnMButtonUp(int x, int y, UINT flags) */
#define UI_HANDLE_WM_MBUTTONUP(wParam, lParam, fn) \
    ((fn)((int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define UI_FORWARD_WM_MBUTTONUP(x, y, keyFlags, fn) \
    (void)(fn)(WM_MBUTTONUP, (WPARAM)(UINT)(keyFlags), MAKELPARAM((x), (y)))

/* void Cls_OnMouseWheel(int xPos, int yPos, int zDelta, UINT fwKeys) */
#define UI_HANDLE_WM_MOUSEWHEEL(wParam, lParam, fn) \
    ((fn)((int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (int)(short)HIWORD(wParam), (UINT)(short)LOWORD(wParam)), 0L)
#define UI_FORWARD_WM_MOUSEWHEEL(xPos, yPos, zDelta, fwKeys, fn) \
    (void)(fn)(WM_MOUSEWHEEL, MAKEWPARAM((fwKeys),(zDelta)), MAKELPARAM((xPos),(yPos)))

/* void Cls_OnNCMouseMove(int x, int y, UINT codeHitTest) */
#define UI_HANDLE_WM_NCMOUSEMOVE(wParam, lParam, fn) \
    ((fn)((int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define UI_FORWARD_WM_NCMOUSEMOVE(x, y, codeHitTest, fn) \
    (void)(fn)(WM_NCMOUSEMOVE, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))

/* void Cls_OnNCLButtonDown(BOOL fDoubleClick, int x, int y, UINT codeHitTest) */
#define UI_HANDLE_WM_NCLBUTTONDOWN(wParam, lParam, fn) \
    ((fn)(FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define UI_FORWARD_WM_NCLBUTTONDOWN(fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((fDoubleClick) ? WM_NCLBUTTONDBLCLK : WM_NCLBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))

/* void Cls_OnNCLButtonDown(BOOL fDoubleClick, int x, int y, UINT codeHitTest) */
#define UI_HANDLE_WM_NCLBUTTONDBLCLK(wParam, lParam, fn) \
    ((fn)(TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)

/* void Cls_OnNCLButtonUp(int x, int y, UINT codeHitTest) */
#define UI_HANDLE_WM_NCLBUTTONUP(wParam, lParam, fn) \
    ((fn)((int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define UI_FORWARD_WM_NCLBUTTONUP(x, y, codeHitTest, fn) \
    (void)(fn)(WM_NCLBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)))

/* void Cls_OnNCRButtonDown(BOOL fDoubleClick, int x, int y, UINT codeHitTest) */
#define UI_HANDLE_WM_NCRBUTTONDOWN(wParam, lParam, fn) \
    ((fn)(FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define UI_FORWARD_WM_NCRBUTTONDOWN(fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((fDoubleClick) ? WM_NCRBUTTONDBLCLK : WM_NCRBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )

/* void Cls_OnNCRButtonDown(BOOL fDoubleClick, int x, int y, UINT codeHitTest) */
#define UI_HANDLE_WM_NCRBUTTONDBLCLK(wParam, lParam, fn) \
    ((fn)(TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)

/* void Cls_OnNCRButtonUp(int x, int y, UINT codeHitTest) */
#define UI_HANDLE_WM_NCRBUTTONUP(wParam, lParam, fn) \
    ((fn)((int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define UI_FORWARD_WM_NCRBUTTONUP(x, y, codeHitTest, fn) \
    (void)(fn)(WM_NCRBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )

/* void Cls_OnNCMButtonDown(BOOL fDoubleClick, int x, int y, UINT codeHitTest) */
#define UI_HANDLE_WM_NCMBUTTONDOWN(wParam, lParam, fn) \
    ((fn)(FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define UI_FORWARD_WM_NCMBUTTONDOWN(fDoubleClick, x, y, codeHitTest, fn) \
    (void)(fn)((fDoubleClick) ? WM_NCMBUTTONDBLCLK : WM_NCMBUTTONDOWN, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )

/* void Cls_OnNCMButtonDown(BOOL fDoubleClick, int x, int y, UINT codeHitTest) */
#define UI_HANDLE_WM_NCMBUTTONDBLCLK(wParam, lParam, fn) \
    ((fn)(TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)

/* void Cls_OnNCMButtonUp(int x, int y, UINT codeHitTest) */
#define UI_HANDLE_WM_NCMBUTTONUP(wParam, lParam, fn) \
    ((fn)((int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), 0L)
#define UI_FORWARD_WM_NCMBUTTONUP(x, y, codeHitTest, fn) \
    (void)(fn)(WM_NCMBUTTONUP, (WPARAM)(UINT)(codeHitTest), MAKELPARAM((x), (y)) )

/* int Cls_OnMouseActivate(TopLevel, UINT codeHitTest, UINT msg) */
#define UI_HANDLE_WM_MOUSEACTIVATE(wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)(()(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam))
#define UI_FORWARD_WM_MOUSEACTIVATE(TopLevel, codeHitTest, msg, fn) \
    (int)(DWORD)(fn)(WM_MOUSEACTIVATE, (WPARAM)()(TopLevel), MAKELPARAM((codeHitTest), (msg)))

/* void Cls_OnCancelMode() */
#define UI_HANDLE_WM_CANCELMODE(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_CANCELMODE(fn) \
    (void)(fn)(WM_CANCELMODE, 0L, 0L)

/* void Cls_OnTimer(UINT id) */
#define UI_HANDLE_WM_TIMER(wParam, lParam, fn) \
    ((fn)((UINT)(wParam)), 0L)
#define UI_FORWARD_WM_TIMER(id, fn) \
    (void)(fn)(WM_TIMER, (WPARAM)(UINT)(id), 0L)

/* void Cls_OnInitMenu(HMENU hMenu) */
#define UI_HANDLE_WM_INITMENU(wParam, lParam, fn) \
    ((fn)((HMENU)(wParam)), 0L)
#define UI_FORWARD_WM_INITMENU(hMenu, fn) \
    (void)(fn)(WM_INITMENU, (WPARAM)(HMENU)(hMenu), 0L)

/* void Cls_OnInitMenuPopup(HMENU hMenu, UINT item, BOOL fSystemMenu) */
#define UI_HANDLE_WM_INITMENUPOPUP(wParam, lParam, fn) \
    ((fn)((HMENU)(wParam), (UINT)LOWORD(lParam), (BOOL)HIWORD(lParam)), 0L)
#define UI_FORWARD_WM_INITMENUPOPUP(hMenu, item, fSystemMenu, fn) \
    (void)(fn)(WM_INITMENUPOPUP, (WPARAM)(HMENU)(hMenu), MAKELPARAM((item),(fSystemMenu)))

/* void Cls_OnMenuSelect(HMENU hmenu, int item, HMENU hmenuPopup, UINT flags) */
#define UI_HANDLE_WM_MENUSELECT(wParam, lParam, fn)                  \
    ((fn)((HMENU)(lParam),  \
    (HIWORD(wParam) & MF_POPUP) ? 0L : (int)(LOWORD(wParam)),           \
    (HIWORD(wParam) & MF_POPUP) ? GetSubMenu((HMENU)lParam, LOWORD(wParam)) : 0L, \
    (UINT)(((short)HIWORD(wParam) == -1) ? 0xFFFFFFFF : HIWORD(wParam))), 0L)
#define UI_FORWARD_WM_MENUSELECT(hmenu, item, hmenuPopup, flags, fn) \
    (void)(fn)(WM_MENUSELECT, MAKEWPARAM((item), (flags)), (LPARAM)(HMENU)((hmenu) ? (hmenu) : (hmenuPopup)))

/* DWORD Cls_OnMenuChar(UINT ch, UINT flags, HMENU hmenu) */
#define UI_HANDLE_WM_MENUCHAR(wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((UINT)(LOWORD(wParam)), (UINT)HIWORD(wParam), (HMENU)(lParam))
#define UI_FORWARD_WM_MENUCHAR(ch, flags, hmenu, fn) \
    (DWORD)(fn)(WM_MENUCHAR, MAKEWPARAM(flags, (WORD)(ch)), (LPARAM)(HMENU)(hmenu))

/* void Cls_OnCommand(int id, Ctl, UINT codeNotify) */
#define UI_HANDLE_WM_COMMAND(wParam, lParam, fn) \
    ((fn)((int)(LOWORD(wParam)), ()(lParam), (UINT)HIWORD(wParam)), 0L)
#define UI_FORWARD_WM_COMMAND(id, Ctl, codeNotify, fn) \
    (void)(fn)(WM_COMMAND, MAKEWPARAM((UINT)(id),(UINT)(codeNotify)), (LPARAM)()(Ctl))

/* void Cls_OnHScroll(Ctl, UINT code, int pos) */
#define UI_HANDLE_WM_HSCROLL(wParam, lParam, fn) \
    ((fn)(()(lParam), (UINT)(LOWORD(wParam)), (int)(short)HIWORD(wParam)), 0L)
#define UI_FORWARD_WM_HSCROLL(Ctl, code, pos, fn) \
    (void)(fn)(WM_HSCROLL, MAKEWPARAM((UINT)(int)(code),(UINT)(int)(pos)), (LPARAM)()(Ctl))

/* void Cls_OnVScroll(Ctl, UINT code, int pos) */
#define UI_HANDLE_WM_VSCROLL(wParam, lParam, fn) \
    ((fn)(()(lParam), (UINT)(LOWORD(wParam)),  (int)(short)HIWORD(wParam)), 0L)
#define UI_FORWARD_WM_VSCROLL(Ctl, code, pos, fn) \
    (void)(fn)(WM_VSCROLL, MAKEWPARAM((UINT)(int)(code), (UINT)(int)(pos)), (LPARAM)()(Ctl))

/* void Cls_OnCut() */
#define UI_HANDLE_WM_CUT(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_CUT(fn) \
    (void)(fn)(WM_CUT, 0L, 0L)

/* void Cls_OnCopy() */
#define UI_HANDLE_WM_COPY(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_COPY(fn) \
    (void)(fn)(WM_COPY, 0L, 0L)

/* void Cls_OnPaste() */
#define UI_HANDLE_WM_PASTE(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_PASTE(fn) \
    (void)(fn)(WM_PASTE, 0L, 0L)

/* void Cls_OnClear() */
#define UI_HANDLE_WM_CLEAR(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_CLEAR(fn) \
    (void)(fn)(WM_CLEAR, 0L, 0L)

/* void Cls_OnUndo() */
#define UI_HANDLE_WM_UNDO(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_UNDO(fn) \
    (void)(fn)(WM_UNDO, 0L, 0L)

/* HANDLE Cls_OnRenderFormat(UINT fmt) */
#define UI_HANDLE_WM_RENDERFORMAT(wParam, lParam, fn) \
    (LRESULT)(UINT_PTR)(HANDLE)(fn)((UINT)(wParam))
#define UI_FORWARD_WM_RENDERFORMAT(fmt, fn) \
    (HANDLE)(UINT_PTR)(fn)(WM_RENDERFORMAT, (WPARAM)(UINT)(fmt), 0L)

/* void Cls_OnRenderAllFormats() */
#define UI_HANDLE_WM_RENDERALLFORMATS(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_RENDERALLFORMATS(fn) \
    (void)(fn)(WM_RENDERALLFORMATS, 0L, 0L)

/* void Cls_OnDestroyClipboard() */
#define UI_HANDLE_WM_DESTROYCLIPBOARD(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_DESTROYCLIPBOARD(fn) \
    (void)(fn)(WM_DESTROYCLIPBOARD, 0L, 0L)

/* void Cls_OnDrawClipboard() */
#define UI_HANDLE_WM_DRAWCLIPBOARD(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_DRAWCLIPBOARD(fn) \
    (void)(fn)(WM_DRAWCLIPBOARD, 0L, 0L)

/* void Cls_OnPaintClipboard(CBViewer, const LPPAINTSTRUCT lpPaintStruct) */
#define UI_HANDLE_WM_PAINTCLIPBOARD(wParam, lParam, fn) \
    ((fn)(()(wParam), (const LPPAINTSTRUCT)GlobalLock((HGLOBAL)(lParam))), GlobalUnlock((HGLOBAL)(lParam)), 0L)
#define UI_FORWARD_WM_PAINTCLIPBOARD(CBViewer, lpPaintStruct, fn) \
    (void)(fn)(WM_PAINTCLIPBOARD, (WPARAM)()(CBViewer), (LPARAM)(LPPAINTSTRUCT)(lpPaintStruct))

/* void Cls_OnSizeClipboard(CBViewer, const LPRECT lprc) */
#define UI_HANDLE_WM_SIZECLIPBOARD(wParam, lParam, fn) \
    ((fn)(()(wParam), (const LPRECT)GlobalLock((HGLOBAL)(lParam))), GlobalUnlock((HGLOBAL)(lParam)), 0L)
#define UI_FORWARD_WM_SIZECLIPBOARD(CBViewer, lprc, fn) \
    (void)(fn)(WM_SIZECLIPBOARD, (WPARAM)()(CBViewer), (LPARAM)(LPRECT)(lprc))

/* void Cls_OnVScrollClipboard(CBViewer, UINT code, int pos) */
#define UI_HANDLE_WM_VSCROLLCLIPBOARD(wParam, lParam, fn) \
    ((fn)(()(wParam), (UINT)LOWORD(lParam), (int)(short)HIWORD(lParam)), 0L)
#define UI_FORWARD_WM_VSCROLLCLIPBOARD(CBViewer, code, pos, fn) \
    (void)(fn)(WM_VSCROLLCLIPBOARD, (WPARAM)()(CBViewer), MAKELPARAM((code), (pos)))

/* void Cls_OnHScrollClipboard(CBViewer, UINT code, int pos) */
#define UI_HANDLE_WM_HSCROLLCLIPBOARD(wParam, lParam, fn) \
    ((fn)(()(wParam), (UINT)LOWORD(lParam), (int)(short)HIWORD(lParam)), 0L)
#define UI_FORWARD_WM_HSCROLLCLIPBOARD(CBViewer, code, pos, fn) \
    (void)(fn)(WM_HSCROLLCLIPBOARD, (WPARAM)()(CBViewer), MAKELPARAM((code), (pos)))

/* void Cls_OnAskCBFormatName(int cchMax, LPTSTR rgchName) */
#define UI_HANDLE_WM_ASKCBFORMATNAME(wParam, lParam, fn) \
    ((fn)((int)(wParam), (LPTSTR)(lParam)), 0L)
#define UI_FORWARD_WM_ASKCBFORMATNAME(cchMax, rgchName, fn) \
    (void)(fn)(WM_ASKCBFORMATNAME, (WPARAM)(int)(cchMax), (LPARAM)(rgchName))

/* void Cls_OnChangeCBChain(Remove, Next) */
#define UI_HANDLE_WM_CHANGECBCHAIN(wParam, lParam, fn) \
    ((fn)(()(wParam), ()(lParam)), 0L)
#define UI_FORWARD_WM_CHANGECBCHAIN(Remove, Next, fn) \
    (void)(fn)(WM_CHANGECBCHAIN, (WPARAM)()(Remove), (LPARAM)()(Next))

/* BOOL Cls_OnSetCursor(Cursor, UINT codeHitTest, UINT msg) */
#define UI_HANDLE_WM_SETCURSOR(wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)(()(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam))
#define UI_FORWARD_WM_SETCURSOR(Cursor, codeHitTest, msg, fn) \
    (BOOL)(DWORD)(fn)(WM_SETCURSOR, (WPARAM)()(Cursor), MAKELPARAM((codeHitTest), (msg)))

/* void Cls_OnSysCommand(UINT cmd, int x, int y) */
#define UI_HANDLE_WM_SYSCOMMAND(wParam, lParam, fn) \
    ((fn)((UINT)(wParam), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam)), 0L)
#define UI_FORWARD_WM_SYSCOMMAND(cmd, x, y, fn) \
    (void)(fn)(WM_SYSCOMMAND, (WPARAM)(UINT)(cmd), MAKELPARAM((x), (y)))

/* Cls_MDICreate(const LPMDICREATESTRUCT lpmcs) */
#define UI_HANDLE_WM_MDICREATE(wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((LPMDICREATESTRUCT)(lParam))
#define UI_FORWARD_WM_MDICREATE(lpmcs, fn) \
    ()(UINT)(DWORD)(fn)(WM_MDICREATE, 0L, (LPARAM)(LPMDICREATESTRUCT)(lpmcs))

/* void Cls_MDIDestroy(Destroy) */
#define UI_HANDLE_WM_MDIDESTROY(wParam, lParam, fn) \
    ((fn)(()(wParam)), 0L)
#define UI_FORWARD_WM_MDIDESTROY(Destroy, fn) \
    (void)(fn)(WM_MDIDESTROY, (WPARAM)(Destroy), 0L)

/* NOTE: Usable only by MDI client windows */
/* void Cls_MDIActivate(BOOL fActive, Activate, Deactivate) */
#define UI_HANDLE_WM_MDIACTIVATE(wParam, lParam, fn) \
    ((fn)((BOOL)(lParam == (LPARAM)), ()(lParam), ()(wParam)), 0L)
#define UI_FORWARD_WM_MDIACTIVATE(fActive, Activate, Deactivate, fn) \
    (void)(fn)(WM_MDIACTIVATE, (WPARAM)(Deactivate), (LPARAM)(Activate))

/* void Cls_MDIRestore(Restore) */
#define UI_HANDLE_WM_MDIRESTORE(wParam, lParam, fn) \
    ((fn)(()(wParam)), 0L)
#define UI_FORWARD_WM_MDIRESTORE(Restore, fn) \
    (void)(fn)(WM_MDIRESTORE, (WPARAM)(Restore), 0L)

/* Cls_MDINext(Cur, BOOL fPrev) */
#define UI_HANDLE_WM_MDINEXT(wParam, lParam, fn) \
    (LRESULT)()(fn)(()(wParam), (BOOL)lParam)
#define UI_FORWARD_WM_MDINEXT(Cur, fPrev, fn) \
    ()(UINT_PTR)(fn)(WM_MDINEXT, (WPARAM)(Cur), (LPARAM)(fPrev))

/* void Cls_MDIMaximize(Maximize) */
#define UI_HANDLE_WM_MDIMAXIMIZE(wParam, lParam, fn) \
    ((fn)(()(wParam)), 0L)
#define UI_FORWARD_WM_MDIMAXIMIZE(Maximize, fn) \
    (void)(fn)(WM_MDIMAXIMIZE, (WPARAM)(Maximize), 0L)

/* BOOL Cls_MDITile(UINT cmd) */
#define UI_HANDLE_WM_MDITILE(wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((UINT)(wParam))
#define UI_FORWARD_WM_MDITILE(cmd, fn) \
    (BOOL)(DWORD)(fn)(WM_MDITILE, (WPARAM)(cmd), 0L)

/* BOOL Cls_MDICascade(UINT cmd) */
#define UI_HANDLE_WM_MDICASCADE(wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((UINT)(wParam))
#define UI_FORWARD_WM_MDICASCADE(cmd, fn) \
    (BOOL)(DWORD)(fn)(WM_MDICASCADE, (WPARAM)(cmd), 0L)

/* void Cls_MDIIconArrange() */
#define UI_HANDLE_WM_MDIICONARRANGE(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_MDIICONARRANGE(fn) \
    (void)(fn)(WM_MDIICONARRANGE, 0L, 0L)

/* Cls_MDIGetActive() */
#define UI_HANDLE_WM_MDIGETACTIVE(wParam, lParam, fn) \
    (LRESULT)(UINT_PTR)(fn)()
#define UI_FORWARD_WM_MDIGETACTIVE(fn) \
    ()(UINT_PTR)(fn)(WM_MDIGETACTIVE, 0L, 0L)

/* HMENU Cls_MDISetMenu(BOOL fRefresh, HMENU hmenuFrame, HMENU hmenuWindow) */
#define UI_HANDLE_WM_MDISETMENU(wParam, lParam, fn) \
    (LRESULT)(UINT_PTR)(fn)((BOOL)(wParam), (HMENU)(wParam), (HMENU)(lParam))
#define UI_FORWARD_WM_MDISETMENU(fRefresh, hmenuFrame, hmenuWindow, fn) \
    (HMENU)(UINT_PTR)(fn)(WM_MDISETMENU, (WPARAM)((fRefresh) ? (hmenuFrame) : 0), (LPARAM)(hmenuWindow))

/* void Cls_OnChildActivate() */
#define UI_HANDLE_WM_CHILDACTIVATE(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_CHILDACTIVATE(fn) \
    (void)(fn)(WM_CHILDACTIVATE, 0L, 0L)

/* BOOL Cls_OnInitDialog(Focus, LPARAM lParam) */
#define UI_HANDLE_WM_INITDIALOG(wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(BOOL)(fn)(()(wParam), lParam)
#define UI_FORWARD_WM_INITDIALOG(Focus, lParam, fn) \
    (BOOL)(DWORD)(fn)(WM_INITDIALOG, (WPARAM)()(Focus), (lParam))

/* Cls_OnNextDlgCtl(SetFocus, BOOL fNext) */
#define UI_HANDLE_WM_NEXTDLGCTL(wParam, lParam, fn) \
    (LRESULT)(UINT_PTR)()(fn)(()(wParam), (BOOL)(lParam))
#define UI_FORWARD_WM_NEXTDLGCTL(SetFocus, fNext, fn) \
    ()(UINT_PTR)(fn)(WM_NEXTDLGCTL, (WPARAM)()(SetFocus), (LPARAM)(fNext))

/* void Cls_OnParentNotify(UINT msg, Child, int idChild) */
#define UI_HANDLE_WM_PARENTNOTIFY(wParam, lParam, fn) \
    ((fn)((UINT)LOWORD(wParam), ()(lParam), (UINT)HIWORD(wParam)), 0L)
#define UI_FORWARD_WM_PARENTNOTIFY(msg, Child, idChild, fn) \
    (void)(fn)(WM_PARENTNOTIFY, MAKEWPARAM(msg, idChild), (LPARAM)(Child))

/* void Cls_OnEnterIdle(UINT source, Source) */
#define UI_HANDLE_WM_ENTERIDLE(wParam, lParam, fn) \
    ((fn)((UINT)(wParam), ()(lParam)), 0L)
#define UI_FORWARD_WM_ENTERIDLE(source, Source, fn) \
    (void)(fn)(WM_ENTERIDLE, (WPARAM)(UINT)(source), (LPARAM)()(Source))

/* UINT Cls_OnGetDlgCode(LPMSG lpmsg) */
#define UI_HANDLE_WM_GETDLGCODE(wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((LPMSG)(lParam))
#define UI_FORWARD_WM_GETDLGCODE(lpmsg, fn) \
    (UINT)(DWORD)(fn)(WM_GETDLGCODE, (lpmsg ? lpmsg->wParam : 0), (LPARAM)(LPMSG)(lpmsg))

/* HBRUSH Cls_OnCtlColor(HDC hdc, Child, int type) */
#define UI_HANDLE_WM_CTLCOLORMSGBOX(wParam, lParam, fn) \
    (LRESULT)(UINT_PTR)(HBRUSH)(fn)((HDC)(wParam), ()(lParam), CTLCOLOR_MSGBOX)
#define UI_FORWARD_WM_CTLCOLORMSGBOX(hdc, Child, fn) \
    (HBRUSH)(UINT_PTR)(fn)(WM_CTLCOLORMSGBOX, (WPARAM)(HDC)(hdc), (LPARAM)()(Child))

#define UI_HANDLE_WM_CTLCOLOREDIT(wParam, lParam, fn) \
    (LRESULT)(UINT_PTR)(HBRUSH)(fn)((HDC)(wParam), ()(lParam), CTLCOLOR_EDIT)
#define UI_FORWARD_WM_CTLCOLOREDIT(hdc, Child, fn) \
    (HBRUSH)(UINT_PTR)(fn)(WM_CTLCOLOREDIT, (WPARAM)(HDC)(hdc), (LPARAM)()(Child))

#define UI_HANDLE_WM_CTLCOLORLISTBOX(wParam, lParam, fn) \
    (LRESULT)(UINT_PTR)(HBRUSH)(fn)((HDC)(wParam), ()(lParam), CTLCOLOR_LISTBOX)
#define UI_FORWARD_WM_CTLCOLORLISTBOX(hdc, Child, fn) \
    (HBRUSH)(UINT_PTR)(fn)(WM_CTLCOLORLISTBOX, (WPARAM)(HDC)(hdc), (LPARAM)()(Child))

#define UI_HANDLE_WM_CTLCOLORBTN(wParam, lParam, fn) \
    (LRESULT)(UINT_PTR)(HBRUSH)(fn)((HDC)(wParam), ()(lParam), CTLCOLOR_BTN)
#define UI_FORWARD_WM_CTLCOLORBTN(hdc, Child, fn) \
    (HBRUSH)(UINT_PTR)(fn)(WM_CTLCOLORBTN, (WPARAM)(HDC)(hdc), (LPARAM)()(Child))

#define UI_HANDLE_WM_CTLCOLORDLG(wParam, lParam, fn) \
    (LRESULT)(UINT_PTR)(HBRUSH)(fn)((HDC)(wParam), ()(lParam), CTLCOLOR_DLG)
#define UI_FORWARD_WM_CTLCOLORDLG(hdc, Child, fn) \
    (HBRUSH)(UINT_PTR)(fn)(WM_CTLCOLORDLG, (WPARAM)(HDC)(hdc), (LPARAM)()(Child))

#define UI_HANDLE_WM_CTLCOLORSCROLLBAR(wParam, lParam, fn) \
    (LRESULT)(UINT_PTR)(HBRUSH)(fn)((HDC)(wParam), ()(lParam), CTLCOLOR_SCROLLBAR)
#define UI_FORWARD_WM_CTLCOLORSCROLLBAR(hdc, Child, fn) \
    (HBRUSH)(UINT_PTR)(fn)(WM_CTLCOLORSCROLLBAR, (WPARAM)(HDC)(hdc), (LPARAM)()(Child))

#define UI_HANDLE_WM_CTLCOLORSTATIC(wParam, lParam, fn) \
    (LRESULT)(UINT_PTR)(HBRUSH)(fn)((HDC)(wParam), ()(lParam), CTLCOLOR_STATIC)
#define UI_FORWARD_WM_CTLCOLORSTATIC(hdc, Child, fn) \
    (HBRUSH)(UINT_PTR)(fn)(WM_CTLCOLORSTATIC, (WPARAM)(HDC)(hdc), (LPARAM)()(Child))

/* void Cls_OnSetFont(Ctl, HFONT hfont, BOOL fRedraw) */
#define UI_HANDLE_WM_SETFONT(wParam, lParam, fn) \
    ((fn)((HFONT)(wParam), (BOOL)(lParam)), 0L)
#define UI_FORWARD_WM_SETFONT(hfont, fRedraw, fn) \
    (void)(fn)(WM_SETFONT, (WPARAM)(HFONT)(hfont), (LPARAM)(BOOL)(fRedraw))

/* HFONT Cls_OnGetFont() */
#define UI_HANDLE_WM_GETFONT(wParam, lParam, fn) \
    (LRESULT)(UINT_PTR)(HFONT)(fn)()
#define UI_FORWARD_WM_GETFONT(fn) \
    (HFONT)(UINT_PTR)(fn)(WM_GETFONT, 0L, 0L)

/* void Cls_OnDrawItem(const DRAWITEMSTRUCT * lpDrawItem) */
#define UI_HANDLE_WM_DRAWITEM(wParam, lParam, fn) \
    ((fn)((const DRAWITEMSTRUCT *)(lParam)), 0L)
#define UI_FORWARD_WM_DRAWITEM(lpDrawItem, fn) \
    (void)(fn)(WM_DRAWITEM, (WPARAM)(((const DRAWITEMSTRUCT *)lpDrawItem)->CtlID), (LPARAM)(const DRAWITEMSTRUCT *)(lpDrawItem))

/* void Cls_OnMeasureItem(MEASUREITEMSTRUCT * lpMeasureItem) */
#define UI_HANDLE_WM_MEASUREITEM(wParam, lParam, fn) \
    ((fn)((MEASUREITEMSTRUCT *)(lParam)), 0L)
#define UI_FORWARD_WM_MEASUREITEM(lpMeasureItem, fn) \
    (void)(fn)(WM_MEASUREITEM, (WPARAM)(((MEASUREITEMSTRUCT *)lpMeasureItem)->CtlID), (LPARAM)(MEASUREITEMSTRUCT *)(lpMeasureItem))

/* void Cls_OnDeleteItem(const DELETEITEMSTRUCT * lpDeleteItem) */
#define UI_HANDLE_WM_DELETEITEM(wParam, lParam, fn) \
    ((fn)((const DELETEITEMSTRUCT *)(lParam)), 0L)
#define UI_FORWARD_WM_DELETEITEM(lpDeleteItem, fn) \
    (void)(fn)(WM_DELETEITEM, (WPARAM)(((const DELETEITEMSTRUCT *)(lpDeleteItem))->CtlID), (LPARAM)(const DELETEITEMSTRUCT *)(lpDeleteItem))

/* int Cls_OnCompareItem(const COMPAREITEMSTRUCT * lpCompareItem) */
#define UI_HANDLE_WM_COMPAREITEM(wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((const COMPAREITEMSTRUCT *)(lParam))
#define UI_FORWARD_WM_COMPAREITEM(lpCompareItem, fn) \
    (int)(DWORD)(fn)(WM_COMPAREITEM, (WPARAM)(((const COMPAREITEMSTRUCT *)(lpCompareItem))->CtlID), (LPARAM)(const COMPAREITEMSTRUCT *)(lpCompareItem))

/* int Cls_OnVkeyToItem(UINT vk, Listbox, int iCaret) */
#define UI_HANDLE_WM_VKEYTOITEM(wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((UINT)LOWORD(wParam), ()(lParam), (int)(short)HIWORD(wParam))
#define UI_FORWARD_WM_VKEYTOITEM(vk, ListBox, iCaret, fn) \
    (int)(DWORD)(fn)(WM_VKEYTOITEM, MAKEWPARAM((vk), (iCaret)), (LPARAM)(ListBox))

/* int Cls_OnCharToItem(UINT ch, Listbox, int iCaret) */
#define UI_HANDLE_WM_CHARTOITEM(wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((UINT)LOWORD(wParam), ()(lParam), (int)(short)HIWORD(wParam))
#define UI_FORWARD_WM_CHARTOITEM(ch, ListBox, iCaret, fn) \
    (int)(DWORD)(fn)(WM_CHARTOITEM, MAKEWPARAM((UINT)(ch), (UINT)(iCaret)), (LPARAM)(ListBox))

/* void Cls_OnQueueSync() */
#define UI_HANDLE_WM_QUEUESYNC(wParam, lParam, fn) \
    ((fn)(), 0L)
#define UI_FORWARD_WM_QUEUESYNC(fn) \
    (void)(fn)(WM_QUEUESYNC, 0L, 0L)
#if (WINVER >= 0x030a)
/* void Cls_OnCommNotify(int cid, UINT flags) */
#define UI_HANDLE_WM_COMMNOTIFY(wParam, lParam, fn) \
    ((fn)((int)(wParam), (UINT)LOWORD(lParam)), 0L)
#define UI_FORWARD_WM_COMMNOTIFY(cid, flags, fn) \
    (void)(fn)(WM_COMMNOTIFY, (WPARAM)(cid), MAKELPARAM((flags), 0))
#endif

/* void Cls_OnDisplayChange(UINT bitsPerPixel, UINT cxScreen, UINT cyScreen) */
#define UI_HANDLE_WM_DISPLAYCHANGE(wParam, lParam, fn) \
    ((fn)((UINT)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(wParam)), 0L)
#define UI_FORWARD_WM_DISPLAYCHANGE(bitsPerPixel, cxScreen, cyScreen, fn) \
    (void)(fn)(WM_DISPLAYCHANGE, (WPARAM)(UINT)(bitsPerPixel), (LPARAM)MAKELPARAM((UINT)(cxScreen), (UINT)(cyScreen)))

/* BOOL Cls_OnDeviceChange(UINT uEvent, DWORD dwEventData) */
#define UI_HANDLE_WM_DEVICECHANGE(wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((UINT)(wParam), (DWORD)(wParam))
#define UI_FORWARD_WM_DEVICECHANGE(uEvent, dwEventData, fn) \
    (BOOL)(DWORD)(fn)(WM_DEVICECHANGE, (WPARAM)(UINT)(uEvent), (LPARAM)(DWORD)(dwEventData))

/* void Cls_OnContextMenu(Context, UINT xPos, UINT yPos) */
#define UI_HANDLE_WM_CONTEXTMENU(wParam, lParam, fn) \
    ((fn)(()(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define UI_FORWARD_WM_CONTEXTMENU(Context, xPos, yPos, fn) \
    (void)(fn)(WM_CONTEXTMENU, (WPARAM)()(Context), MAKELPARAM((UINT)(xPos), (UINT)(yPos)))

#define UI_HANDLE_WM_COPYDATA(wParam, lParam, fn) \
    ((fn)(()(wParam), (PCOPYDATASTRUCT)lParam), 0L)
#define UI_FORWARD_WM_COPYDATA(From, pcds, fn) \
    (BOOL)(UINT)(DWORD)(fn)(WM_COPYDATA, (WPARAM)(From), (LPARAM)(pcds))