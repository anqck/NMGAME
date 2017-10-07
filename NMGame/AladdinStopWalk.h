#pragma once

#include "AladdinCharacter.h"


class AladdinStopWalk : public AladdinCharacter
{
public:
	AladdinStopWalk() : AladdinCharacter() { this->LoadResource(); };
	AladdinStopWalk(LPD3DXSPRITE SpriteHandle) : AladdinCharacter(SpriteHandle) { this->LoadResource(); };
	AladdinStopWalk(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinCharacter(SpriteHandle, Position) { this->LoadResource(); };
	AladdinStopWalk(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinCharacter(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinStopWalk();

	void			 Draw();
protected:
	void			Initialize();
	void			LoadResource();
	void			Animate(float DeltaTime);

};