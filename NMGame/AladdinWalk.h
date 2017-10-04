#pragma once
#include "AladdinCharacter.h"


class AladdinWalk : public AladdinCharacter
{
public:
	AladdinWalk() : AladdinCharacter() { this->LoadResource(); };
	AladdinWalk(LPD3DXSPRITE SpriteHandle)  : AladdinCharacter(SpriteHandle) { this->LoadResource(); };
	AladdinWalk(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinCharacter(SpriteHandle, Position) { this->LoadResource(); };
	AladdinWalk(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinCharacter(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinWalk();

	void			 Draw();
protected:
	void			Initialize();
	void			LoadResource();

};