#include "Game.h"
#include "Global.h"

void GAME::_ProcessKeyBoard()
{
	// Collect all key states first
	_Keyboard->GetDeviceState(sizeof(_KeyStates), _KeyStates);

	if (IsKeyDown(DIK_ESCAPE))
	{
		//trace(L"Escape key pressed!");
		PostMessage(GLOBAL::GetHWND(), WM_QUIT, 0, 0);
	}

	// Collect all buffered events
	//DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	//HRESULT hr = _Keyboard->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), _KeyEvents, &dwElements, 0);

	//// Scan through all data, check if the key is pressed or released
	//for (DWORD i = 0; i < dwElements; i++)
	//{
	//	int KeyCode = _KeyEvents[i].dwOfs;
	//	int KeyState = _KeyEvents[i].dwData;
	//	if ((KeyState & 0x80) > 0)
	//		OnKeyDown(KeyCode);
	//	else
	//		OnKeyUp(KeyCode);
	//}
}

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
	this->InitDevice();
	this->InitKeyboard();
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

		_ProcessKeyBoard();
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
	GLOBAL::SetDirect(Direct3DCreate9(D3D_SDK_VERSION));
	D3DPRESENT_PARAMETERS	d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = GLOBAL::GetFullScreen()?FALSE:TRUE;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferHeight = GLOBAL::GetWindowsHeight();
	d3dpp.BackBufferWidth = GLOBAL::GetWindowsWidth();

	LPDIRECT3DDEVICE9 device;

	GLOBAL::GetDirect()->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		GLOBAL::GetHWND(),
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&device);

	GLOBAL::SetDirectDevice(device);

	if (!GLOBAL::GetDirectDevice())
	{
		MessageBox(NULL, L"Can't create Direct Device", L"Error", MB_OK | MB_ERR_INVALID_CHARS);
		return;
	}

	LPDIRECT3DSURFACE9 backbuffer;

	GLOBAL::GetDirectDevice()->GetBackBuffer(
		0,
		0,
		D3DBACKBUFFER_TYPE_MONO,
		&backbuffer);

	GLOBAL::SetBackBuffer(backbuffer);

	LPD3DXSPRITE spriteHandler;

	if (D3DXCreateSprite(GLOBAL::GetDirectDevice(), &spriteHandler) != D3D_OK)
	{
		MessageBox(NULL, L"Can't create spritehandler!", L"Error", MB_OK | MB_ERR_INVALID_CHARS);
		return;
	}

	GLOBAL::SetSpriteHandler(spriteHandler);
}

void GAME::InitKeyboard()
{
	HRESULT
		hr = DirectInput8Create
		(
			GLOBAL::GethInstance(),
			DIRECTINPUT_VERSION,
			IID_IDirectInput8, (VOID**)&_di, NULL
		);

	// TO-DO: put in exception handling
	if (hr != DI_OK) return;

	//trace(L"DirectInput has been created");

	hr = _di->CreateDevice(GUID_SysKeyboard, &_Keyboard, NULL);

	// TO-DO: put in exception handling
	if (hr != DI_OK) return;

	//trace(L"DirectInput keyboard has been created");

	// Set the data format to "keyboard format" - a predefined data format 
	//
	// A data format specifies which controls on a device we
	// are interested in, and how they should be reported.
	//
	// This tells DirectInput that we will be passing an array
	// of 256 bytes to IDirectInputDevice::GetDeviceState.

	hr = _Keyboard->SetDataFormat(&c_dfDIKeyboard);

//	trace(L"SetDataFormat for keyboard successfully");

	hr = _Keyboard->SetCooperativeLevel(GLOBAL::GetHWND(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

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

	hr = _Keyboard->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	if (hr != DI_OK) return;

	hr = _Keyboard->Acquire();
	if (hr != DI_OK) return;

	//trace(L"Keyboard has been acquired successfully");
}

void GAME::LoadResource()
{
	
}

void GAME::_RenderFrame()
{
	
	if (GLOBAL::GetDirectDevice()->BeginScene())
	{
		
		RenderFrame( _DeltaTime);

		GLOBAL::GetDirectDevice()->EndScene();
	}
	GLOBAL::GetDirectDevice()->Present(NULL, NULL, NULL, NULL);
}

void GAME::RenderFrame(int DeltaTime)
{

	if (GLOBAL::GetDirectDevice()->BeginScene())
	{

		GLOBAL::GetDirectDevice()->EndScene();
	}
	GLOBAL::GetDirectDevice()->Present(NULL, NULL, NULL, NULL);
}

void GAME::Update(int DeltaTime)
{
	
}



void GAME::ProcessInput(int Delta){}

void GAME::AddScene(IScene * sence)
{
	this->mListSence.push_back(sence);
	//sence->LoadResource();
}



int GAME::IsKeyDown(int KeyCode)
{
	return (_KeyStates[KeyCode] & 0x80) > 0;
}

void GAME::OnKeyDown(int KeyCode)
{

}

void GAME::OnKeyUp(int KeyCode){}
