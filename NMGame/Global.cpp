#include "Global.h"


HINSTANCE						GLOBAL::mHInstance = NULL;
HWND							GLOBAL::mHwnd = NULL;
LPDIRECT3D9						GLOBAL::mDirect = NULL;
LPDIRECT3DDEVICE9				GLOBAL::mDirectDevice = NULL;
LPDIRECT3DSURFACE9				GLOBAL::mBackBuffer = NULL;
bool							GLOBAL::misFullScreen = FALSE;
int								GLOBAL::mWindowsWidth;
int								GLOBAL::mWindowsHeight;
LPWSTR							GLOBAL::mGameName = L"TEST GAME";
int								GLOBAL::mFrameRate;
int								GLOBAL::mCurrentFrame = 0;
LPD3DXSPRITE					GLOBAL::mAladdinSpriteHandler = NULL;
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


