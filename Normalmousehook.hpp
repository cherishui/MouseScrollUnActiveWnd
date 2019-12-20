#ifndef HOOKS_H
#define HOOKS_H

#include "hook.hpp"

class NormalMouseHook : public Hook {
	public:
		NormalMouseHook();
	private:
		static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
		static bool processMouseMessage(UINT message, WPARAM mouseData, POINT const &mousePos);
};

#endif
