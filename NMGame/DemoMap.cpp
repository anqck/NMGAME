#include "DemoMap.h"

DemoMap::DemoMap()
{
	mBackground.push_back(new MovableBackground(L"Map\\BG1.png", 430, D3DXVECTOR2(0.00f, 0.0f),1));
	mBackground.push_back(new MovableBackground(L"Map\\BG2.png", 366, D3DXVECTOR2(0.00f, 0.0f),0.8));
	mBackground.push_back(new MovableBackground(L"Map\\BG3.png", 323, D3DXVECTOR2(0.00f, 0.0f), 0.65));
	mBackground.push_back(new MovableBackground(L"Map\\BG4.png", 302, D3DXVECTOR2(0.00f, 0.0f), 0.55));
	mBackground.push_back(new MovableBackground(L"Map\\BG5.png", 259, D3DXVECTOR2(0.00f, 0.0f), 0.45));
	mBackground.push_back(new MovableBackground(L"Map\\BG6.png", 195.64, D3DXVECTOR2(0.00f, 0.0f), 0.4));
	mBackground.push_back(new MovableBackground(L"Map\\BG7.png", 109.88, D3DXVECTOR2(-0.03f, 0.0f), 0.5));
	mBackground.push_back(new MovableBackground(L"Map\\BG8.png",45.56, D3DXVECTOR2(-0.04f, 0.0f), 0.6));
	mBackground.push_back(new MovableBackground(L"Map\\BG9.png",0, D3DXVECTOR2(-0.08f, 0.0f), 0.7));
	//this->bg1 = new MovableBackground(L"Map\\BG1.png", 600 - 157, D3DXVECTOR2(0.00f, 0.0f), CenterArchor::CenterBottom);
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
		D3DX_DEFAULT,
		0,
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

void DemoMap::Render(float DeltaTime, MapLevel mMapLevel)
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

		GraphicsHelper::GetInstance()->GetDirectDevice()->StretchRect(_Surface,	NULL, GraphicsHelper::GetInstance()->GetBackBuffer(),	NULL,D3DTEXF_NONE);
		for (int i = 0; i < mBackground.size(); i++)
		{
			this->mBackground.at(i)->Render(DeltaTime);
		}
		break;
	case MapLevel::MapLevel1:
		GraphicsHelper::GetInstance()->DrawTexture(mMapTextureLevel1, MyRECT(0, 0, 4770, 688), D3DXVECTOR3(0, 0, 0), inPosition, D3DXVECTOR2(2.2, 2.5), translation);
		//GraphicsHelper::GetInstance()->DrawTexture(mMapTextureLevel1, MyRECT(0, 0, 4771, 688), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0));
		break;
	case  MapLevel::MapLevel2:
		GraphicsHelper::GetInstance()->DrawTexture(mMapTextureLevel2, MyRECT(0, 0, 4770, 688), D3DXVECTOR3(0, 0, 0), inPosition, D3DXVECTOR2(2.2, 2.5), translation);
		//GraphicsHelper::GetInstance()->DrawTexture(mMapTextureLevel1, MyRECT(0, 0, 4771, 688), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0));
		break;
	}
}

void DemoMap::Update(float DeltaTime)
{
	for (int i = 0; i < mBackground.size(); i++)
	{
		this->mBackground.at(i)->Update(DeltaTime);
	}
}
