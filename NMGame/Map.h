#pragma once
#include "Ultils.h"
#include "Global.h"

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
	virtual void	Render(float DeltaTime);
private:
	MapLevel mMapLevel;
	LPDIRECT3DTEXTURE9		mMapTextureLevel1, MapTextureLevel2;

};