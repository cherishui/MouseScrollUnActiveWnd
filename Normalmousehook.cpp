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
				
				// ��Ϣֱ�Ӵ��ݼ��ɡ� wParam��Ҫ�ع����ⰴ����Ϣ
				WPARAM wParam = MAKEWPARAM(currentVirtualKeys(), nWheelDelta);

				TRACE("Hook sending WM_MOUSEWHEEL message 0x%x mousePos:[%d, %d]  WheelDelta:%d \n", message, mousePos.x, mousePos.y, nWheelDelta);

				
#if 1			// �������������������������Ϣ�������οؼ�
				extern HWND g_hTreeCtrl;
				::SendMessage(g_hTreeCtrl, message, wParam, pointToDword(mousePos));
#else
				// �ѹ�����Ϣ���͸���굱ǰ��ͣ����
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
	// nCode: ���Ӻ���ʹ�õģ�����������δ������Ϣ��,�����С��0���ú���Ҫ���Ӻ������봫����Ϣ����һ�����ӡ�
	//			HC_ACTIONΪ0 , wParam��lParam���������Ϣ
	//			HC_NOREMOVE , wParam��lParam���������Ϣ�������Ϣ��δ����Ϣ�������Ƴ�����

	// wParam: �����Ϣ�Ķ���
	// lParam: ָ��  MOUSEHOOKSTRUCT ���� MOUSEHOOKSTRUCTEX �ṹָ��
	TRACE("nCode:0x%x, wParam:0x%x lParam:0x%x\n", nCode, wParam, lParam);

	bool eat = false; // Set to true if we don't want to pass the event to the application.
	if (nCode == HC_ACTION) { // If nCode < 0, do nothing as per Microsoft's recommendations.
		MOUSEHOOKSTRUCTEX const &eventInfo = *(MOUSEHOOKSTRUCTEX*)lParam;
		eat = processMouseMessage(wParam, eventInfo.mouseData, eventInfo.pt);
	}

	LRESULT res = CallNextHookEx((HHOOK)37, nCode, wParam, lParam); // first argument ignored
	return eat ? 1 : res; // nonzero return value prevents passing the event to the application
}