#pragma once

#include<Windows.h>
#include<dinput.h>
#include<d3d9.h>
#include<d3dx9.h>

#define WORLD_X 10494
#define WORLD_Y 10494  //Thế giới hình vuông cho việc chia QuadTree
//#define WORLD_Y 688*2.5

#define MAP_WIDTH 10494
#define MAP_HEIGHT 1720

struct TransformObject
{
	TransformObject() : mPosition(D3DXVECTOR3(0, 0, 0)), mTranslation(D3DXVECTOR2(0, 0)) {};
	D3DXVECTOR3					mPosition;
	D3DXVECTOR3					mTranslation;
};

enum Direction
{
	Left,
	Right,
	Up,
	Down,
	None
};


class GLOBAL
{
	//typedef int(*FPTR)(int a);
public:
	
	GLOBAL();
	~GLOBAL();
	static	HINSTANCE						GethInstance() { return GLOBAL::mHInstance; }
	static	void							SethInstance(HINSTANCE hInstance) { GLOBAL::mHInstance = hInstance; }

	static	HWND							GetHWND() { return GLOBAL::mHwnd; }
	static	void							SetHWND(HWND hwnd) { GLOBAL::mHwnd = hwnd; }

	static	bool							GetFullScreen() { return GLOBAL::misFullScreen; }
	static	void							SetFullScreen(bool fullscreen) { GLOBAL::misFullScreen = fullscreen; }

	static	int								GetWindowsWidth() { return GLOBAL::mWindowsWidth; }
	static	void							SetWindowsWidth(int width) { GLOBAL::mWindowsWidth = width; }

	static	int								GetWindowsHeight() { return GLOBAL::mWindowsHeight; }
	static	void							SetWindowsHeight(int height) { GLOBAL::mWindowsHeight = height; }

	static	LPWSTR							GetGameName() { return GLOBAL::mGameName; }
	static	void							SetGameName(LPWSTR name) { GLOBAL::mGameName = name; }

	static	int								GetFrameRate() { return GLOBAL::mFrameRate; }
	static	void							SetFrameRate(int frameRate) { GLOBAL::mFrameRate = frameRate; }



	static LPDIRECTINPUT8		GetDirectInput();
	static void					SetDirectInput(LPDIRECTINPUT8 dinput);
	
	static LPDIRECTINPUTDEVICE8	GetDirectInputKeyboard();
	static void					SetDirectInputKeyboard(LPDIRECTINPUTDEVICE8 dinputdev);
	//static	FPTR							cb;
	

	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
private:
	static	HINSTANCE						mHInstance;
	static	HWND							mHwnd;
	static	bool							misFullScreen;
	static	int								mWindowsWidth;
	static	int								mWindowsHeight;
	static	LPWSTR							mGameName;
	static	int								mFrameRate; 
	static	int								mCurrentFrame;
	static LPDIRECTINPUT8					mDirectInput;
	static LPDIRECTINPUTDEVICE8				mDirectInputKeyboard;
};

