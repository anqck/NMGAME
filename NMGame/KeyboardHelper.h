#pragma once

#include"Global.h"

#include<Windows.h>


#define KEYBOARD_BUFFER_SIZE	1024

class KeyboardHelper
{
public:
	static KeyboardHelper*		GetInstance();
	void						Initialize();
	HRESULT						Acquire();
	HRESULT						Unacquire();
	bool						IsKeyDown(int keyCode);
private:
	KeyboardHelper();
	~KeyboardHelper();
	static KeyboardHelper*			mInstance;
	char						keyStates[256];
};
