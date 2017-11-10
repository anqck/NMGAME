#pragma once

#include<Windows.h>
#include<d3d9.h>
#include <dinput.h>
#include <vector>

#include "GraphicsHelper.h"
#include "Global.h"
#include "Ultils.h"
#include "SceneManager.h"
#include "KeyboardHelper.h"
#include "ViewPort.h"



#define KEY_DOWN(code) ( IsKeyDown(code) )
#define KEYBOARD_BUFFER_SIZE	1024

using namespace std;
class GAME
{
protected:

	DWORD _DeltaTime;

	vector<IScene*>			mListSence;



	virtual void		RenderFrame(float DeltaTime);	
	virtual void		Update(float DeltaTime);
	virtual void		LoadResource();
	virtual void		ProcessInput(int Delta);
	void				AddScene(IScene *sence);

public:
	GAME(HINSTANCE hInstance, LPWSTR Name, int windowsWidth, int windowsHeight, int IsFullScreen, int FrameRate);
	~GAME();

	void				Initialize();
	void				Run();



private:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void				InitWindows();
	void				InitDevice();
	void				_RenderFrame();
};