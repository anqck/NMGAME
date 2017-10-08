#pragma once

#include "AladdinState.h"


class AladdinStopWalk : public AladdinState
{
public:
	AladdinStopWalk() : AladdinState() { this->LoadResource(); };
	AladdinStopWalk(LPD3DXSPRITE SpriteHandle) : AladdinState(SpriteHandle) { this->LoadResource(); };
	AladdinStopWalk(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinState(SpriteHandle, Position) { this->LoadResource(); };
	AladdinStopWalk(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinState(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinStopWalk();

protected:
	void			Initialize();
	void			LoadResource();
	void			Animate(float DeltaTime);

};