#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

class GLOBAL
{
public:
	GLOBAL();
	~GLOBAL();
	static	HINSTANCE						GethInstance() { return GLOBAL::mHInstance; }
	static	void							SethInstance(HINSTANCE hInstance) { GLOBAL::mHInstance = hInstance; }

	static	HWND							GetHWND() { return GLOBAL::mHwnd; }
	static	void							SetHWND(HWND hwnd) { GLOBAL::mHwnd = hwnd; }

	static	LPDIRECT3D9						GetDirect() { return GLOBAL::mDirect; }
	static	void							SetDirect(LPDIRECT3D9 direct) { GLOBAL::mDirect = direct; }

	static	LPDIRECT3DDEVICE9				GetDirectDevice() { return GLOBAL::mDirectDevice; }
	static	void							SetDirectDevice(LPDIRECT3DDEVICE9 device) { GLOBAL::mDirectDevice = device; }

	static	LPDIRECT3DSURFACE9				GetBackBuffer() { return GLOBAL::mBackBuffer; }
	static	void							SetBackBuffer(LPDIRECT3DSURFACE9 backbuffer) { GLOBAL::mBackBuffer = backbuffer; }

	static	LPD3DXSPRITE					GetSpriteHandler() { return GLOBAL::mSpriteHandler; }
	static	void							SetSpriteHandler(LPD3DXSPRITE spriteHandler) { GLOBAL::mSpriteHandler = spriteHandler; }

	static	bool							GetFullScreen() { return GLOBAL::isFullScreen; }
	static	void							SetFullScreen(bool fullscreen) { GLOBAL::isFullScreen = fullscreen; }

	static	int								GetWindowsWidth() { return GLOBAL::mWindowsWidth; }
	static	void							SetWindowsWidth(int width) { GLOBAL::mWindowsWidth = width; }

	static	int								GetWindowsHeight() { return GLOBAL::mWindowsHeight; }
	static	void							SetWindowsHeight(int height) { GLOBAL::mWindowsHeight = height; }

	static	LPWSTR							GetGameName() { return GLOBAL::mGameName; }
	static	void							SetGameName(LPWSTR name) { GLOBAL::mGameName = name; }

	static	int								GetFrameRate() { return GLOBAL::mFrameRate; }
	static	void							SetFrameRate(int frameRate) { GLOBAL::mFrameRate = frameRate; }

	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
private:
	static	HINSTANCE						mHInstance;
	static	HWND							mHwnd;
	static	LPDIRECT3D9						mDirect;
	static	LPDIRECT3DDEVICE9				mDirectDevice;
	static	LPDIRECT3DSURFACE9				mBackBuffer; 
	static	LPD3DXSPRITE					mSpriteHandler; 
	static	bool							isFullScreen;
	static	int								mWindowsWidth;
	static	int								mWindowsHeight;
	static	LPWSTR							mGameName;
	static	int								mFrameRate; 
	static	int								mCurrentFrame;
};

