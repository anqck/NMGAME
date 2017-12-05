#include "AladdinGame.h"
#include "MenuScene.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
#define WINDOWS_WIDTH	800
#define WINDOWS_HEIGHT	600
#define FRAME_RATE		80

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	AladdinGame game(hInstance,L"Aladdin", WINDOWS_WIDTH, WINDOWS_HEIGHT, FALSE, FRAME_RATE);
	game.Initialize();
	game.Run();
}