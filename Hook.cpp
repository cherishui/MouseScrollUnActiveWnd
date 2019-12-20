#include "stdafx.h"
#include "hook.hpp"

Hook::Hook(int type, HOOKPROC proc)
:
	d_type(type),
	d_proc(proc),
	d_handle(NULL)
{
}

bool Hook::attach() {
	ASSERT(!attached());
	int nCurrentThreadId = GetCurrentThreadId();
	d_handle = SetWindowsHookEx(d_type, d_proc, NULL, nCurrentThreadId);
	return d_handle != NULL;
}

bool Hook::detach() {
	ASSERT(attached());
	bool success = true;
	if (!UnhookWindowsHookEx(d_handle))
		success = false;
	d_handle = NULL;
	return success;
}
