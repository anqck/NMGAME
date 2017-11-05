#pragma once
#include "Ultils.h"
#include "Global.h"
#include "GraphicsHelper.h"

enum MapLevel
{
	MapLevel1,
	MapLevel2
};

class Map
{
public:
	

	Map();
	virtual void	LoadResource();
	virtual void	Update(float DeltaTime);
	virtual void	Render(float DeltaTime, MapLevel mMapLevel);

protected:


	LPDIRECT3DTEXTURE9		mMapTextureLevel1, MapTextureLevel2;
	MyRECT					mRectMap;

};