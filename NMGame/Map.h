#pragma once
#include "Ultils.h"
#include "Global.h"
#include "GraphicsHelper.h"
#include "ViewPort.h"
#include "Camera.h"

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
	D3DXVECTOR3				mPosition;

	LPDIRECT3DTEXTURE9		mMapTextureLevel1, mMapTextureLevel2;
	MyRECT					mRectMap;

};