#include "AladdinGame.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
#define WINDOWS_WIDTH	800
#define WINDOWS_HEIGHT	600
#define FRAME_RATE		60

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	AladdinGame game(hInstance,L"Aladdin", WINDOWS_WIDTH, WINDOWS_HEIGHT, FALSE, FRAME_RATE);
	game.Initialize();

	MSG msg;
	int done = 1;
	DWORD frameStart = GetTickCount();
	DWORD delta;
	while (done)
	{
		DWORD tick_per_frame = 1000 / GLOBAL::GetFrameRate();
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				done = 0;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		DWORD now = GetTickCount();
		delta = now - frameStart;
		if (delta >= tick_per_frame)
		{
			game.Run();
			frameStart = now;
		}
	}
}