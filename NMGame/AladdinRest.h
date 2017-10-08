#pragma once

#include "AladdinState.h"


class AladdinRest : public AladdinState
{
public:
	AladdinRest() : AladdinState() { this->LoadResource(); };
	AladdinRest(LPD3DXSPRITE SpriteHandle) : AladdinState(SpriteHandle) { this->LoadResource(); };
	AladdinRest(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinState(SpriteHandle, Position) { this->LoadResource(); };
	AladdinRest(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinState(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinRest();

protected:
	void			Initialize();
	void			LoadResource();
	void			Animate();

};