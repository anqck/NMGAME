#include "DemoMap.h"

DemoMap::DemoMap()
{
	this->mPosition = D3DXVECTOR3(0, WORLD_Y, 0);
	this->LoadResource();
}



void DemoMap::LoadResource()
{
	D3DXIMAGE_INFO			mImageInfo;

	D3DXGetImageInfoFromFile(L"MapLevel1.png", &mImageInfo);

	D3DXCreateTextureFromFileEx(GraphicsHelper::GetInstance()->GetDirectDevice(), L"MapLevel1.png", mImageInfo.Width,
		mImageInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(63, 72, 204),
		&mImageInfo,
		NULL,
		&this->mMapTextureLevel1);


	D3DXGetImageInfoFromFile(L"MapLevel2.png", &mImageInfo);

	D3DXCreateTextureFromFileEx(GraphicsHelper::GetInstance()->GetDirectDevice(), L"MapLevel2.png", mImageInfo.Width,
		mImageInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(63, 72, 204),
		&mImageInfo,
		NULL,
		&this->mMapTextureLevel2);


	
	/*this->mBackground = CreateSurfaceFromFile(GLOBAL::GetDirectDevice(), L"Map\\Map1.PNG");*/
}
