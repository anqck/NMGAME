#include "Global.h"


HINSTANCE						GLOBAL::mHInstance = NULL;
HWND							GLOBAL::mHwnd = NULL;
bool							GLOBAL::misFullScreen = FALSE;
int								GLOBAL::mWindowsWidth;
int								GLOBAL::mWindowsHeight;
LPWSTR							GLOBAL::mGameName = L"TEST GAME";
int								GLOBAL::mFrameRate;
int								GLOBAL::mCurrentFrame = 0;
LPDIRECTINPUT8				GLOBAL::mDirectInput = NULL;
LPDIRECTINPUTDEVICE8		GLOBAL::mDirectInputKeyboard = NULL;


GLOBAL::GLOBAL()
{
	
}


GLOBAL::~GLOBAL()
{
}

LPDIRECTINPUT8 GLOBAL::GetDirectInput()
{
	return GLOBAL::mDirectInput;
}

void GLOBAL::SetDirectInput(LPDIRECTINPUT8 dinput)
{
	GLOBAL::mDirectInput = dinput;
}

LPDIRECTINPUTDEVICE8 GLOBAL::GetDirectInputKeyboard()
{
	return GLOBAL::mDirectInputKeyboard;
}

void GLOBAL::SetDirectInputKeyboard(LPDIRECTINPUTDEVICE8 dinputdev)
{
	GLOBAL::mDirectInputKeyboard = dinputdev;
}


