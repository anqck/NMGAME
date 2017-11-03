#include "Map.h"

Map::Map()
{
	//this->LoadResource();
}

void Map::LoadResource()
{
}

void Map::Update(float DeltaTime)
{
}

void Map::Render(float DeltaTime)
{
	

	switch (mMapLevel)
	{
	case MapLevel::MapLevel1:
		//if (mMapTextureLevel1 != NULL)
		//
		//	GLOBAL::GetDirectDevice()->StretchRect(
		//		this->mBackground,			// from 
		//		NULL,				// which portion?
		//		GLOBAL::GetBackBuffer(),		// to 
		//		NULL,				// which portion?
		//		D3DTEXF_NONE);
		//	graphics->DrawTexture(map, _rectMap1, inPosition, this->_transform._scale, translation);
		break;
	}
}
