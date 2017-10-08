#pragma once

#include "AladdinState.h"

class AladdinSitAttack : public AladdinState
{
public:
	AladdinSitAttack() : AladdinState() { this->LoadResource(); };
	AladdinSitAttack(LPD3DXSPRITE SpriteHandle) : AladdinState(SpriteHandle) { this->LoadResource(); };
	AladdinSitAttack(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinState(SpriteHandle, Position) { this->LoadResource(); };
	AladdinSitAttack(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinState(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinSitAttack();

protected:
	void			Initialize();
	void			LoadResource();
	void			Animate(float DeltaTime);

};