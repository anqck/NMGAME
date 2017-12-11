#pragma once
#include "Map.h"
#include "Ultils.h"

#include "MovableBackground.h"

class BossMap : public Map
{
public:
	BossMap();

	void LoadResource();

	void	Render(float DeltaTime, MapLevel mMapLevel);
	void	Update(float DeltaTime);

//protected:
//	vector<MovableBackground*>	mBackground;

};