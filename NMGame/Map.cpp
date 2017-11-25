#include "Map.h"

Map::Map()
{
	this->mPosition = D3DXVECTOR3(0, WORLD_Y, 0);
	this->LoadResource();
}

void Map::LoadResource()
{
	
}

void Map::Update(float DeltaTime)
{
}

void Map::Render(float DeltaTime, MapLevel mMapLevel)
{
	D3DXVECTOR3 cameraPositionInView = ViewPort::GetInstance()->getViewPortPosition(Camera::GetInstance()->GetPosition());

	D3DXVECTOR2 translation = D3DXVECTOR2(-cameraPositionInView.x, -cameraPositionInView.y);
	D3DXVECTOR3 inPosition = ViewPort::GetInstance()->getViewPortPosition(this->mPosition);


	switch (mMapLevel)
	{
	case MapLevel::MapLevel1:
		GraphicsHelper::GetInstance()->DrawTexture(mMapTextureLevel1, MyRECT(0, 0, 4771, 688), D3DXVECTOR3(0, 0, 0), inPosition, D3DXVECTOR2(2.2,2.5), translation);
		//GraphicsHelper::GetInstance()->DrawTexture(mMapTextureLevel1, MyRECT(0, 0, 4771, 688), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0));
		break;
	case  MapLevel::MapLevel2:
		GraphicsHelper::GetInstance()->DrawTexture(mMapTextureLevel2, MyRECT(0, 0, 4771, 688), D3DXVECTOR3(0, 0, 0), inPosition, D3DXVECTOR2(2.2, 2.5), translation);
		//GraphicsHelper::GetInstance()->DrawTexture(mMapTextureLevel1, MyRECT(0, 0, 4771, 688), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0));
		break;
	}
}
