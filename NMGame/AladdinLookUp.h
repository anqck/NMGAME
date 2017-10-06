#pragma once

#pragma once
#include "AladdinCharacter.h"


class AladdinLookUp : public AladdinCharacter
{
public:
	AladdinLookUp() : AladdinCharacter() { this->LoadResource(); };
	AladdinLookUp(LPD3DXSPRITE SpriteHandle) : AladdinCharacter(SpriteHandle) { this->LoadResource(); };
	AladdinLookUp(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinCharacter(SpriteHandle, Position) { this->LoadResource(); };
	AladdinLookUp(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinCharacter(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinLookUp();

	void			 Draw();
protected:
	void			Initialize();
	void			LoadResource();
	void			Animate();

};