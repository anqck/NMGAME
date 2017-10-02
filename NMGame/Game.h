#pragma once

#include<Windows.h>
#include<d3d9.h>
#include "Global.h"
#include "Ultils.h"

using namespace std;
class GAME
{
public:
	GAME(HINSTANCE hInstance, LPWSTR Name, int windowsWidth, int windowsHeight, int IsFullScreen, int FrameRate);
	~GAME();

	void					Initialize();
	void					Run();

private:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void					InitWindows();
	void					InitDevice();
	virtual void			LoadResource();
	virtual void			RenderFrame();

	

};