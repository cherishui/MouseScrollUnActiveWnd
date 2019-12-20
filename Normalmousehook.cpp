#include "stdafx.h"
#include "tools.h"
#include "Normalmousehook.hpp"

NormalMouseHook::NormalMouseHook()
	:Hook(WH_MOUSE, &MouseProc)	
{

}

bool NormalMouseHook::processMouseMessage(UINT message, WPARAM mouseData, POINT const &mousePos) {
	switch (message) {
		case WM_LBUTTONDOWN:
		case WM_MBUTTONDOWN:
		case WM_RBUTTONDOWN:
			TRACE("Hook sending mouse-down message");
			return false;
		case WM_LBUTTONUP:
		case WM_MBUTTONUP:
		case WM_RBUTTONUP:
			TRACE("Hook sending mouse-up message");
			return false;
		case WM_MOUSEMOVE:
			return false;
		case WM_MOUSEWHEEL:
		case WM_MOUSEHWHEEL:
			{
				int nWheelDelta = GET_WHEEL_DELTA_WPARAM(mouseData);
				
				// 消息直接传递即可。 wParam需要重构虚拟按键消息
				WPARAM wParam = MAKEWPARAM(currentVirtualKeys(), nWheelDelta);

				TRACE("Hook sending WM_MOUSEWHEEL message 0x%x mousePos:[%d, %d]  WheelDelta:%d \n", message, mousePos.x, mousePos.y, nWheelDelta);

				
#if 1			// 不管在哪里滚动，都将滚动消息发给树形控件
				extern HWND g_hTreeCtrl;
				::SendMessage(g_hTreeCtrl, message, wParam, pointToDword(mousePos));
#else
				// 把滚动消息发送给鼠标当前悬停窗口
				HWND window = WindowFromPoint(mousePos);
				SendMessage(window, message, wParam, pointToDword(mousePos));
#endif
				return false;
			}
		default:
			return false;
	}
}

LRESULT CALLBACK NormalMouseHook::MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
	// nCode: 钩子函数使用的，用来决定如何处理该消息的,如果它小于0，该函数要钩子函数必须传递消息给下一个钩子。
	//			HC_ACTION为0 , wParam和lParam代表鼠标消息
	//			HC_NOREMOVE , wParam和lParam代表鼠标消息，鼠标消息尚未从消息队列中移除掉。

	// wParam: 鼠标消息的定义
	// lParam: 指向  MOUSEHOOKSTRUCT 或者 MOUSEHOOKSTRUCTEX 结构指针
	TRACE("nCode:0x%x, wParam:0x%x lParam:0x%x\n", nCode, wParam, lParam);

	bool eat = false; // Set to true if we don't want to pass the event to the application.
	if (nCode == HC_ACTION) { // If nCode < 0, do nothing as per Microsoft's recommendations.
		MOUSEHOOKSTRUCTEX const &eventInfo = *(MOUSEHOOKSTRUCTEX*)lParam;
		eat = processMouseMessage(wParam, eventInfo.mouseData, eventInfo.pt);
	}

	LRESULT res = CallNextHookEx((HHOOK)37, nCode, wParam, lParam); // first argument ignored
	return eat ? 1 : res; // nonzero return value prevents passing the event to the application
}