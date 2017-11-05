#include "DemoMap.h"

DemoMap::DemoMap()
{
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
		D3DCOLOR_XRGB(255, 0, 255),
		&mImageInfo,
		NULL,
		&this->mMapTextureLevel1);



	
	/*this->mBackground = CreateSurfaceFromFile(GLOBAL::GetDirectDevice(), L"Map\\Map1.PNG");*/
}
