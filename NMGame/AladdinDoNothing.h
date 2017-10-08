#pragma once
#include "AladdinState.h"

class AladdinDoNothing : public AladdinState
{
public:
	AladdinDoNothing() : AladdinState() { this->LoadResource(); };
	AladdinDoNothing(LPD3DXSPRITE SpriteHandle) : AladdinState(SpriteHandle) { this->LoadResource(); };
	AladdinDoNothing(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinState(SpriteHandle, Position) { this->LoadResource(); };
	AladdinDoNothing(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinState(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinDoNothing();

protected:
	void			Initialize();
	void			LoadResource();
	void			Update(float DeltaTime);

};