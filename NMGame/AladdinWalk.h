#pragma once
#include "AladdinState.h"


class AladdinWalk : public AladdinState
{
public:
	AladdinWalk() : AladdinState() { this->LoadResource(); };
	AladdinWalk(LPD3DXSPRITE SpriteHandle)  : AladdinState(SpriteHandle) { this->LoadResource(); };
	AladdinWalk(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position) : AladdinState(SpriteHandle, Position) { this->LoadResource(); };
	AladdinWalk(LPD3DXSPRITE SpriteHandle, int X, int Y) : AladdinState(SpriteHandle, X, Y) { this->LoadResource(); };
	~AladdinWalk();

protected:
	void			Initialize();
	void			LoadResource();
	void			Update(float DeltaTime);
	void			nextFrame();

	bool			flagLoop;

};