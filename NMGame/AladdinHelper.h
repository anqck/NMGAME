#pragma once
#include "AladdinCharacter.h"
#include "AladdinWalk.h"

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

	AladdinWalk			*_mAladdinWalk;
public:
	AladdinHelper(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 pos);
	void setAladdinState(AladdinState state);
	void setDirection(Direction dir);
	void Render(int DeltaTime);
};