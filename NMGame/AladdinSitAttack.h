#pragma once

#include "AladdinCharacter.h"

class AladdinSitAttack : public AladdinCharacter
{
public:
	AladdinSitAttack() : AladdinCharacter() { this->LoadResource(); };
	AladdinSitAttack(LPD3DXSPRITE SpriteHandle) : AladdinCharacter(SpriteHandle) { this->LoadResource(); };
	AladdinSitAttack(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinCharacter(SpriteHandle, Position) { this->LoadResource(); };
	AladdinSitAttack(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinCharacter(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinSitAttack();

	void			 Draw();
protected:
	void			Initialize();
	void			LoadResource();
	void			Animate(float DeltaTime);

};