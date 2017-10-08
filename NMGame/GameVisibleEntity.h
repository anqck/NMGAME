#pragma once
#include "Global.h"

class GameVisibleEntity {
protected:
	LPD3DXSPRITE		mSpriteHandle;
	D3DXVECTOR3			mPosition;

	float				mTime;

public:
	GameVisibleEntity();
	GameVisibleEntity(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 pos);

	virtual void	Render(float DeltaTime) = 0;
	virtual void	Update(float DeltaTime) = 0;
};