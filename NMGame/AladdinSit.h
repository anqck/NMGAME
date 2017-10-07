#pragma once

#include "AladdinCharacter.h"


class AladdinSit : public AladdinCharacter
{
public:
	AladdinSit() : AladdinCharacter() { this->LoadResource(); };
	AladdinSit(LPD3DXSPRITE SpriteHandle) : AladdinCharacter(SpriteHandle) { this->LoadResource(); };
	AladdinSit(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinCharacter(SpriteHandle, Position) { this->LoadResource(); };
	AladdinSit(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinCharacter(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinSit();

	void			 Draw();
protected:
	void			Initialize();
	void			LoadResource();
	void			Animate(float DeltaTime);

};