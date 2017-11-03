#include "Game.h"
#include "Global.h"

GAME::GAME(HINSTANCE hInstance, LPWSTR Name, int windowsWidth, int windowsHeight, int IsFullScreen, int FrameRate)
{
	GLOBAL::SethInstance(hInstance);
	GLOBAL::SetGameName(Name);
	GLOBAL::SetWindowsWidth(windowsWidth);
	GLOBAL::SetWindowsHeight(windowsHeight);
	GLOBAL::SetFrameRate(FrameRate);
}

GAME::~GAME()
{
	if (GLOBAL::GetDirect())
		GLOBAL::GetDirect()->Release();

	if (GLOBAL::GetDirectDevice())
		GLOBAL::GetDirectDevice()->Release();

	if (GLOBAL::GetBackBuffer())
		GLOBAL::GetBackBuffer()->Release();
}
void GAME::Initialize()
{
	this->InitWindows();
	//this->InitDevice();
	GraphicsHelper::GetInstance()->Initialize();
	KeyboardHelper::GetInstance()->Initialize();
	this->LoadResource();	
}

void GAME::Run()
{
	MSG msg;
	int done = 1;
	DWORD frameStart = GetTickCount();

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
		_DeltaTime = now - frameStart;
		if (_DeltaTime >= tick_per_frame)
		{
			frameStart = now;
			Update(_DeltaTime);
			_RenderFrame();	
			
		}

		//_ProcessKeyBoard();
		ProcessInput(_DeltaTime);
		
	}
}

LRESULT GAME::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		return 0;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	case WM_KEYDOWN:
	{
		SceneManager::GetInstance()->GetCurrentScene()->OnKeyDown(wParam);
		break;
	}
	case WM_KEYUP:
	{
		SceneManager::GetInstance()->GetCurrentScene()->OnKeyUp(wParam);
		break;
	}
		
	} // End switch
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void GAME::InitWindows()
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = GLOBAL::GethInstance();

	wc.lpfnWndProc = (WNDPROC)GAME::WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = GLOBAL::GetGameName();
	wc.hIconSm = NULL;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, TEXT(" The program requires Windows"), GLOBAL::GetGameName(), MB_ICONERROR);
		return;
	}

	GLOBAL::SetHWND(
		CreateWindow(GLOBAL::GetGameName(), // Tên lớp cửa sổ
			GLOBAL::GetGameName(), // Tiêu đề cửa sổ
			WS_OVERLAPPEDWINDOW, // Kiểu cửa sổ
			CW_USEDEFAULT, // Tọa độ x
			CW_USEDEFAULT, // Tọa độ y
			GLOBAL::GetWindowsWidth(), // Chiều ngang
			GLOBAL::GetWindowsHeight(), // Chiều dọc
			NULL, // Cửa sổ cha
			NULL, // Thực đơn
			GLOBAL::GethInstance(), // Định danh
			NULL)); // Tham số

	ShowWindow(GLOBAL::GetHWND(), SW_SHOWNORMAL);
	UpdateWindow(GLOBAL::GetHWND());
}

void GAME::InitDevice()
{
	//GLOBAL::SetDirect(Direct3DCreate9(D3D_SDK_VERSION));
	//D3DPRESENT_PARAMETERS	d3dpp;

	//ZeroMemory(&d3dpp, sizeof(d3dpp));

	//d3dpp.Windowed = GLOBAL::GetFullScreen()?FALSE:TRUE;

	//d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	//d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	//d3dpp.BackBufferCount = 1;
	//d3dpp.BackBufferHeight = GLOBAL::GetWindowsHeight();
	//d3dpp.BackBufferWidth = GLOBAL::GetWindowsWidth();

	//LPDIRECT3DDEVICE9 device;

	//GLOBAL::GetDirect()->CreateDevice(
	//	D3DADAPTER_DEFAULT,
	//	D3DDEVTYPE_HAL,
	//	GLOBAL::GetHWND(),
	//	D3DCREATE_SOFTWARE_VERTEXPROCESSING,
	//	&d3dpp,
	//	&device);

	//GLOBAL::SetDirectDevice(device);

	//if (!GLOBAL::GetDirectDevice())
	//{
	//	MessageBox(NULL, L"Can't create Direct Device", L"Error", MB_OK | MB_ERR_INVALID_CHARS);
	//	return;
	//}

	//LPDIRECT3DSURFACE9 backbuffer;

	//GLOBAL::GetDirectDevice()->GetBackBuffer(
	//	0,
	//	0,
	//	D3DBACKBUFFER_TYPE_MONO,
	//	&backbuffer);

	//GLOBAL::SetBackBuffer(backbuffer);

	//LPD3DXSPRITE spriteHandler;

	//if (D3DXCreateSprite(GLOBAL::GetDirectDevice(), &spriteHandler) != D3D_OK)
	//{
	//	MessageBox(NULL, L"Can't create spritehandler!", L"Error", MB_OK | MB_ERR_INVALID_CHARS);
	//	return;
	//}

	//GLOBAL::SetSpriteHandler(spriteHandler);


}


void GAME::LoadResource()
{
	
}

void GAME::_RenderFrame()
{
	
	if (GraphicsHelper::GetInstance()->GetDirectDevice()->BeginScene())
	{
		
		RenderFrame( _DeltaTime);

		GraphicsHelper::GetInstance()->GetDirectDevice()->EndScene();
	}
	GraphicsHelper::GetInstance()->GetDirectDevice()->Present(NULL, NULL, NULL, NULL);
}

void GAME::RenderFrame(float DeltaTime)
{

	if (GraphicsHelper::GetInstance()->GetDirectDevice()->BeginScene())
	{

		GraphicsHelper::GetInstance()->GetDirectDevice()->EndScene();
	}
	GraphicsHelper::GetInstance()->GetDirectDevice()->Present(NULL, NULL, NULL, NULL);
}

void GAME::Update(float DeltaTime)
{
	
}



void GAME::ProcessInput(int Delta){}

void GAME::AddScene(IScene * sence)
{
	this->mListSence.push_back(sence);
	//sence->LoadResource();
}




