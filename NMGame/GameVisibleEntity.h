#pragma once
#include "Global.h"
#include <vector>
#include "MyRECT.h"
#include "Sprite.h"

class GameVisibleEntity {
protected:
	Sprite*				mSprite;
	LPD3DXSPRITE		mSpriteHandle;
	D3DXVECTOR3			mPosition;
	float				mTime;
	int ANIMATE_RATE;

public:
	GameVisibleEntity();
	GameVisibleEntity( D3DXVECTOR3 pos);
	GameVisibleEntity( int X, int Y);

	virtual void	Render(float DeltaTime) = 0;
	virtual void	Update(float DeltaTime) = 0;


};