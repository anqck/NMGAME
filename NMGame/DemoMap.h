#pragma once
#include "Map.h"
#include "Ultils.h"

class DemoMap
{
public:
	DemoMap();

	void Update(float DeltaTime);
	void Render(float DeltaTime);
protected:
	

	void LoadResource();

};