#pragma once

#include "AladdinState.h"

class AladdinAttack1 : public AladdinState
{
public:
	AladdinAttack1() : AladdinState() { this->LoadResource(); };
	AladdinAttack1(LPD3DXSPRITE SpriteHandle) : AladdinState(SpriteHandle) { this->LoadResource(); };
	AladdinAttack1(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinState(SpriteHandle, Position) { this->LoadResource(); };
	AladdinAttack1(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinState(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinAttack1();

protected:
	void			Initialize();
	void			LoadResource();
	void			Update(float DeltaTime);
	void			Animate(float DeltaTime);

};