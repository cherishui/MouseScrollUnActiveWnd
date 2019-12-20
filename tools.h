#pragma once

DWORD pointToDword(POINT const &pt);
POINT dwordToPoint(DWORD dw);
DWORD currentVirtualKeys();
void showSystemError(HWND parent, DWORD error, LPCTSTR title);