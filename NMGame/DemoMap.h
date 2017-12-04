#pragma once
#include "Map.h"
#include "Ultils.h"

#include "MovableBackground.h"

class DemoMap : public Map
{
public:
	DemoMap();

	void LoadResource();

	void	Render(float DeltaTime, MapLevel mMapLevel);
	void	Update(float DeltaTime);

protected:
	vector<MovableBackground*>	mBackground;

	MovableBackground*		bg1, * bg9;
	

};