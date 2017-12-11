#include "BossMap.h"

BossMap::BossMap()
{

	this->mPosition = D3DXVECTOR3(0, WORLD_Y, 0);
	this->LoadResource();
}

void BossMap::LoadResource()
{
	D3DXIMAGE_INFO			mImageInfo;

	D3DXGetImageInfoFromFile(L"Map\\mapboss.png", &mImageInfo);

	D3DXCreateTextureFromFileEx(GraphicsHelper::GetInstance()->GetDirectDevice(), L"Map\\mapboss.png", mImageInfo.Width,
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
}

void BossMap::Render(float DeltaTime, MapLevel mMapLevel)
{
	D3DXVECTOR3 cameraPositionInView = ViewPort::GetInstance()->getViewPortPosition(Camera::GetInstance()->GetPosition());

	D3DXVECTOR2 translation = D3DXVECTOR2(-cameraPositionInView.x, -cameraPositionInView.y);
	D3DXVECTOR3 inPosition = ViewPort::GetInstance()->getViewPortPosition(this->mPosition);


	switch (mMapLevel)
	{
	case MapLevel::MapBackground:
		LPDIRECT3DSURFACE9			_Surface;
		GraphicsHelper::GetInstance()->GetDirectDevice()->CreateOffscreenPlainSurface(
			100,
			100,
			D3DFMT_X8R8G8B8,
			D3DPOOL_DEFAULT,
			&_Surface,
			NULL);

		GraphicsHelper::GetInstance()->GetDirectDevice()->ColorFill(_Surface, NULL, D3DCOLOR_XRGB(0, 0, 0));

		GraphicsHelper::GetInstance()->GetDirectDevice()->StretchRect(_Surface, NULL, GraphicsHelper::GetInstance()->GetBackBuffer(), NULL, D3DTEXF_NONE);
		break;
	case MapLevel::MapLevel1:
		GraphicsHelper::GetInstance()->DrawTexture(mMapTextureLevel1, MyRECT(0, 0, 1100, 392), D3DXVECTOR3(0, 0, 0), inPosition, D3DXVECTOR2(2.2, 2.5), translation);
		//GraphicsHelper::GetInstance()->DrawTexture(mMapTextureLevel1, MyRECT(0, 0, 4771, 688), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0));
		break;
	//case  MapLevel::MapLevel2:
	//	GraphicsHelper::GetInstance()->DrawTexture(mMapTextureLevel2, MyRECT(0, 0, 4770, 688), D3DXVECTOR3(0, 0, 0), inPosition, D3DXVECTOR2(2.2, 2.5), translation);
	//	//GraphicsHelper::GetInstance()->DrawTexture(mMapTextureLevel1, MyRECT(0, 0, 4771, 688), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0));
	//	break;
	}
}

void BossMap::Update(float DeltaTime)
{
}
