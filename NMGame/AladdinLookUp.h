#pragma once

#include "AladdinState.h"


class AladdinLookUp : public AladdinState
{
public:
	AladdinLookUp() : AladdinState() { this->LoadResource(); };
	AladdinLookUp(LPD3DXSPRITE SpriteHandle) : AladdinState(SpriteHandle) { this->LoadResource(); };
	AladdinLookUp(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinState(SpriteHandle, Position) { this->LoadResource(); };
	AladdinLookUp(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinState(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinLookUp();


protected:
	void			Initialize();
	void			LoadResource();
	void			Animate(float DeltaTime);

};