#pragma once

#include "AladdinState.h"


class AladdinStand : public AladdinState
{
public:
	AladdinStand() : AladdinState() { this->LoadResource(); };
	AladdinStand(LPD3DXSPRITE SpriteHandle) : AladdinState(SpriteHandle) { this->LoadResource(); };
	AladdinStand(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinState(SpriteHandle, Position) { this->LoadResource(); };
	AladdinStand(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinState(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinStand();

protected:
	void			Initialize();
	void			LoadResource();
	void			Animate(float DeltaTime);

};