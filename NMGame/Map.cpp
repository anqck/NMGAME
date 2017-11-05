#include "Map.h"

Map::Map()
{
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
	

	switch (mMapLevel)
	{
	case MapLevel::MapLevel1:
		GraphicsHelper::GetInstance()->DrawTexture(mMapTextureLevel1, MyRECT(0, 0, 4771, 688), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0));
		break;
	}
}
