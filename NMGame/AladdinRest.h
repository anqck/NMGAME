#pragma once

#include "AladdinCharacter.h"


class AladdinRest : public AladdinCharacter
{
public:
	AladdinRest() : AladdinCharacter() { this->LoadResource(); };
	AladdinRest(LPD3DXSPRITE SpriteHandle) : AladdinCharacter(SpriteHandle) { this->LoadResource(); };
	AladdinRest(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinCharacter(SpriteHandle, Position) { this->LoadResource(); };
	AladdinRest(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinCharacter(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinRest();

	void			 Draw();
protected:
	void			Initialize();
	void			LoadResource();
	void			Animate();

};