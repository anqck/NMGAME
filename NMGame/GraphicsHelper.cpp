#include "GraphicsHelper.h"
#include "Camera.h"

GraphicsHelper*		GraphicsHelper::mInstance = NULL;

GraphicsHelper * GraphicsHelper::GetInstance()
{
	if (!mInstance)
		GraphicsHelper::mInstance = new GraphicsHelper();

	return GraphicsHelper::mInstance;
}

void GraphicsHelper::Initialize()
{
	this->mDirect = Direct3DCreate9(D3D_SDK_VERSION);
	
	D3DPRESENT_PARAMETERS	d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = GLOBAL::GetFullScreen() ? FALSE : TRUE;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferHeight = GLOBAL::GetWindowsHeight();
	d3dpp.BackBufferWidth = GLOBAL::GetWindowsWidth();
	d3dpp.hDeviceWindow = GLOBAL::GetHWND();

	this->mDirect->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		GLOBAL::GetHWND(),
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&mDirectDevice);


	if (!mDirectDevice)
	{
		MessageBox(NULL, L"Can't create Direct Device", L"Error", MB_OK | MB_ERR_INVALID_CHARS);
		return;
	}

	this->mDirectDevice->Clear(
		0,
		NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0, 0, 0),
		1.0f,
		0);

	mDirectDevice->GetBackBuffer(
		0,
		0,
		D3DBACKBUFFER_TYPE_MONO,
		&mBackBuffer);


	if (D3DXCreateSprite(mDirectDevice, &mSpriteHandler) != D3D_OK)
	{
		MessageBox(NULL, L"Can't create spritehandler!", L"Error", MB_OK | MB_ERR_INVALID_CHARS);
		return;
	}

}

LPDIRECT3D9 GraphicsHelper::GetDirect()
{
	return this->mDirect;
}

LPDIRECT3DDEVICE9 GraphicsHelper::GetDirectDevice()
{
	return this->mDirectDevice;
}

LPD3DXSPRITE GraphicsHelper::GetSpriteHandler()
{
	return this->mSpriteHandler;
}

LPDIRECT3DSURFACE9 GraphicsHelper::GetBackBuffer()
{
	return this->mBackBuffer;
}

void GraphicsHelper::DrawTexture(LPDIRECT3DTEXTURE9 Texture, MyRECT sourceRect, D3DXVECTOR3 center, D3DXVECTOR3 position, D3DXVECTOR2 scale, D3DXVECTOR2 translation, float rotation, D3DXVECTOR2 rotationCenter)
{
	D3DXVECTOR2	scalingCenter = position;

	D3DXMATRIX oldMatrix;
	D3DXMATRIX		mMatrix;

	D3DXMatrixTransformation2D(
		&mMatrix,
		&scalingCenter,
		0,
		&scale,
		NULL,
		rotation,
		&translation);


	this->mSpriteHandler->GetTransform(&oldMatrix);
	this->mSpriteHandler->SetTransform(&mMatrix);

	//D3DXVECTOR3 center = D3DXVECTOR3((this->mSourceRect.right - this->mSourceRect.left) / 2, (this->mSourceRect.bottom - this->mSourceRect.top) / 2, 0);//Tâm của sprite cần vẽ
	

	mSpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	
	mSpriteHandler->Draw(Texture, &sourceRect, &center, &position, D3DCOLOR_XRGB(255, 255, 255));

	mSpriteHandler->End();

	this->mSpriteHandler->SetTransform(&oldMatrix);
}

void GraphicsHelper::DrawSurface(LPDIRECT3DSURFACE9 surface, const RECT * sourceRect, const RECT * desRect)
{
	this->mDirectDevice->StretchRect(
		surface,
		sourceRect,
		this->mBackBuffer,
		desRect,
		D3DTEXF_NONE);
}

void GraphicsHelper::DrawSurface(const RECT * sourceRect, const RECT * desRect)
{
}

void GraphicsHelper::DrawLine(D3DXVECTOR2 lines[], int count)
{
	LPD3DXLINE LineDraw	;

	D3DXCreateLine(GraphicsHelper::GetDirectDevice(), &LineDraw);
	LineDraw->SetWidth(3);
	LineDraw->Begin();
	LineDraw->Draw(lines, count, D3DCOLOR_XRGB(255, 0, 0));
	LineDraw->End();
}

void GraphicsHelper::DrawBoundingBox(MyRECT rect)
{
	D3DXVECTOR3 cameraPositionInView = ViewPort::GetInstance()->getViewPortPosition(Camera::GetInstance()->GetPosition());

	D3DXVECTOR3 _translation = D3DXVECTOR3(-cameraPositionInView.x, -cameraPositionInView.y, 0);


	D3DXVECTOR3 lt = ViewPort::GetInstance()->getViewPortPosition(D3DXVECTOR3(rect.left,rect.top,0));
	D3DXVECTOR3 rb = ViewPort::GetInstance()->getViewPortPosition(D3DXVECTOR3(rect.right , rect.bottom, 0));

	D3DXVECTOR2 trans = D3DXVECTOR2(_translation.x, _translation.y);

	D3DXVECTOR2 lines[] = { D3DXVECTOR2(lt.x + trans.x, lt.y + trans.y),
		D3DXVECTOR2(rb.x + trans.x, lt.y + trans.y),
		D3DXVECTOR2(rb.x + trans.x, rb.y + trans.y),
		D3DXVECTOR2(lt.x + trans.x, rb.y + trans.y),
		D3DXVECTOR2(lt.x + trans.x, lt.y + trans.y) };

		DrawLine(lines, 5);
}

GraphicsHelper::GraphicsHelper()
{
	
}
