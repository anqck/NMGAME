#pragma once
#include "AladdinCharacter.h"
#include "AladdinWalk.h"
#include "AladdinLookUp.h"

enum AladdinState
{
	DoNothing,
	Walk,
	LookUp
};

enum Direction
{
	Left,
	Right,
	Up,
	Down
};
class AladdinHelper {
protected:
	AladdinState		mState;
	AladdinCharacter	*mAladdin;
	Direction			mDir;
	LPD3DXSPRITE		mSpriteHandler;
	D3DXVECTOR3			mPosition;

	AladdinWalk			*_mAladdinWalk;
	AladdinLookUp		*_mAladdinLookUp;
public:
	AladdinHelper(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 pos);
	void setAladdinState(AladdinState state);
	void setDirection(Direction dir);
	void Render(int DeltaTime);
};