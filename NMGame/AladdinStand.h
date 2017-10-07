#pragma once

#include "AladdinCharacter.h"


class AladdinStand : public AladdinCharacter
{
public:
	AladdinStand() : AladdinCharacter() { this->LoadResource(); };
	AladdinStand(LPD3DXSPRITE SpriteHandle) : AladdinCharacter(SpriteHandle) { this->LoadResource(); };
	AladdinStand(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinCharacter(SpriteHandle, Position) { this->LoadResource(); };
	AladdinStand(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinCharacter(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinStand();

	void			 Draw();
protected:
	void			Initialize();
	void			LoadResource();
	void			Animate(float DeltaTime);

};