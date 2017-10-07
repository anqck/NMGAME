#pragma once

#include "AladdinCharacter.h"

class AladdinAttack1 : public AladdinCharacter
{
public:
	AladdinAttack1() : AladdinCharacter() { this->LoadResource(); };
	AladdinAttack1(LPD3DXSPRITE SpriteHandle) : AladdinCharacter(SpriteHandle) { this->LoadResource(); };
	AladdinAttack1(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinCharacter(SpriteHandle, Position) { this->LoadResource(); };
	AladdinAttack1(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinCharacter(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinAttack1();

	void			 Draw();
protected:
	void			Initialize();
	void			LoadResource();
	void			Animate(float DeltaTime);

};