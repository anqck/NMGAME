#include "KeyboardHelper.h"

KeyboardHelper*				KeyboardHelper::mInstance = NULL;

KeyboardHelper * KeyboardHelper::GetInstance()
{
	if (!mInstance)
		KeyboardHelper::mInstance = new KeyboardHelper();
	return KeyboardHelper::mInstance;
}

void KeyboardHelper::Initialize()
{
	HRESULT result;
	LPDIRECTINPUT8 dinput;
	result = DirectInput8Create(
		GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&dinput,
		NULL);

	// TO-DO: put in exception handling
	if (result != DI_OK) return;
	else GLOBAL::SetDirectInput(dinput);

	//trace(L"DirectInput has been created");
	LPDIRECTINPUTDEVICE8 keyboard;
	result = GLOBAL::GetDirectInput()->CreateDevice(
		GUID_SysKeyboard,
		&keyboard,
		NULL);

	// TO-DO: put in exception handling
	if (result != DI_OK) return;
	else GLOBAL::SetDirectInputKeyboard(keyboard);

	//trace(L"DirectInput keyboard has been created");

	// Set the data format to "keyboard format" - a predefined data format 
	//
	// A data format specifies which controls on a device we
	// are interested in, and how they should be reported.
	//
	// This tells DirectInput that we will be passing an array
	// of 256 bytes to IDirectInputDevice::GetDeviceState.

	result = GLOBAL::GetDirectInputKeyboard()->SetDataFormat(&c_dfDIKeyboard);

	//	trace(L"SetDataFormat for keyboard successfully");

	result = GLOBAL::GetDirectInputKeyboard()->SetCooperativeLevel(GLOBAL::GetHWND(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	//trace(L"SetCooperativeLevel for keyboard successfully");

	// IMPORTANT STEP TO USE BUFFERED DEVICE DATA!
	//
	// DirectInput uses unbuffered I/O (buffer size = 0) by default.
	// If you want to read buffered data, you need to set a nonzero
	// buffer size.
	//
	// Set the buffer size to DINPUT_BUFFERSIZE (defined above) elements.
	//
	// The buffer size is a DWORD property associated with the device.
	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = KEYBOARD_BUFFER_SIZE; // Arbitary buffer size

										 //trace(L"SetProperty for keyboard successfully");

	result = GLOBAL::GetDirectInputKeyboard()->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	if (result != DI_OK) return;

}

HRESULT KeyboardHelper::Acquire()
{
	return GLOBAL::GetDirectInputKeyboard()->Acquire();
}

HRESULT KeyboardHelper::Unacquire()
{
	return GLOBAL::GetDirectInputKeyboard()->Unacquire();
}

bool KeyboardHelper::IsKeyDown(int keyCode)
{
	//GLOBAL::GetDirectInputKeyboard()->Acquire();
	GLOBAL::GetDirectInputKeyboard()->GetDeviceState(sizeof(keyStates), (LPVOID)&keyStates);
	return (keyStates[keyCode] & 0x80) > 0;
}

KeyboardHelper::KeyboardHelper()
{
}
