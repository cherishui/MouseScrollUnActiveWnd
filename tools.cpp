#include "stdafx.h"
#include "tools.h"

DWORD pointToDword(POINT const &pt) {
	return (((pt).y << 16) | ((pt).x & 0xFFFF));
}

POINT dwordToPoint(DWORD dw) {
	POINT pt = { GET_X_LPARAM(dw), GET_Y_LPARAM(dw) };
	return pt;
}

DWORD currentVirtualKeys() {
	DWORD ret = 0;
	if (GetAsyncKeyState(VK_CONTROL) & 0x8000) ret |= MK_CONTROL;
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) ret |= MK_LBUTTON;
	if (GetAsyncKeyState(VK_MBUTTON) & 0x8000) ret |= MK_MBUTTON;
	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) ret |= MK_RBUTTON;
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000) ret |= MK_SHIFT;
	if (GetAsyncKeyState(VK_XBUTTON1) & 0x8000) ret |= MK_XBUTTON1;
	if (GetAsyncKeyState(VK_XBUTTON2) & 0x8000) ret |= MK_XBUTTON2;
	return ret;
}


void showSystemError(HWND parent, DWORD error, LPCTSTR title) {
	PVOID msg;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, error, 0, (LPTSTR)&msg, 0, NULL);
	MessageBox(parent, (LPCTSTR)msg, title, MB_OK | MB_ICONERROR);
	LocalFree(msg);
}
