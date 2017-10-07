#pragma once
#include "Global.h"

class GameVisibleEntity {
protected:
	LPD3DXSPRITE		mSpriteHandler;
	D3DXVECTOR3			mPosition;

	float				mTime;

public:
	GameVisibleEntity(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 pos);

	virtual void	Render(int DeltaTime) = 0;
	virtual void	Update(int DeltaTime) = 0;
};