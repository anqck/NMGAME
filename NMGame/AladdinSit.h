#pragma once

#include "AladdinState.h"


class AladdinSit : public AladdinState
{
public:
	AladdinSit() : AladdinState() { this->LoadResource(); };
	AladdinSit(LPD3DXSPRITE SpriteHandle) : AladdinState(SpriteHandle) { this->LoadResource(); };
	AladdinSit(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinState(SpriteHandle, Position) { this->LoadResource(); };
	AladdinSit(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinState(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinSit();

protected:
	void			Initialize();
	void			LoadResource();
	void			Animate(float DeltaTime);

};