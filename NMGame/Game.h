#pragma once

#include<Windows.h>
#include<d3d9.h>
#include <dinput.h>

#include "Global.h"
#include "Ultils.h"


#define KEY_DOWN(code) ( IsKeyDown(code) )
#define KEYBOARD_BUFFER_SIZE	1024

using namespace std;
class GAME
{
protected:
	BYTE  _KeyStates[256];

	// Buffered keyboard data
	DIDEVICEOBJECTDATA _KeyEvents[KEYBOARD_BUFFER_SIZE];

	LPDIRECTINPUT8       _di;		// The DirectInput object         
	LPDIRECTINPUTDEVICE8 _Keyboard;	// The keyboard device 

	DWORD _DeltaTime;

	virtual void		RenderFrame(int Delta);	

public:
	GAME(HINSTANCE hInstance, LPWSTR Name, int windowsWidth, int windowsHeight, int IsFullScreen, int FrameRate);
	~GAME();

	void				Initialize();
	void				Run();

	int					IsKeyDown(int KeyCode);
	virtual void		OnKeyDown(int KeyCode);
	virtual void		OnKeyUp(int KeyCode);

	void				 _ProcessKeyBoard();

private:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void				InitWindows();
	void				InitDevice();
	void				InitKeyboard();
	virtual void		LoadResource();
	void				_RenderFrame();
	virtual void		ProcessInput( int Delta);
	
	
	

};