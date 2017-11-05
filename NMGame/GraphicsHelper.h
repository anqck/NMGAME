#pragma once
#include "Global.h"
#include "MyRECT.h"

class GraphicsHelper
{
public:
	static GraphicsHelper*		GetInstance();
	void						Initialize();

	LPDIRECT3D9					GetDirect();
	LPDIRECT3DDEVICE9			GetDirectDevice();
	LPD3DXSPRITE				GetSpriteHandler();
	LPDIRECT3DSURFACE9			GetBackBuffer();

	void						DrawTexture(LPDIRECT3DTEXTURE9 Texture, MyRECT sourceRect, D3DXVECTOR3 center, D3DXVECTOR3 position, D3DXVECTOR2 scale = D3DXVECTOR2(1, 1), D3DXVECTOR2 translation = D3DXVECTOR2(0, 0), float rotation = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(0, 0));

private:
	GraphicsHelper();

	static GraphicsHelper*		mInstance;

	LPDIRECT3D9					mDirect;
	LPDIRECT3DDEVICE9			mDirectDevice;
	LPDIRECT3DSURFACE9			mBackBuffer;
	LPD3DXSPRITE				mSpriteHandler;

	
};