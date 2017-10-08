#pragma once
#include "Ultils.h"
#include "Global.h"

class DemoMap
{
public:
	DemoMap();

	void Update(float DeltaTime);
	void Render(float DeltaTime);
protected:
	LPDIRECT3DSURFACE9		mBackground;

	void LoadResource();

};