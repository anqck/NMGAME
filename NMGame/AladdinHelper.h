#pragma once
#include "AladdinCharacter.h"
#include "AladdinWalk.h"
#include "AladdinLookUp.h"
#include "AladdinRest.h"
#include "AladdinStand.h"
#include "AladdinAttack1.h"

enum AladdinState
{
	DoNothing,
	Walk,
	LookUp,
	Stand,
	Rest,
	Attack1
	
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
	float				mTime;

	AladdinWalk			*_mAladdinWalk;
	AladdinLookUp		*_mAladdinLookUp;
	AladdinStand		*_mAladdinStand;
	AladdinRest			*_mAladdinRest;
	AladdinAttack1		*_mAladdinAttack1;
public:
	AladdinHelper(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 pos);
	void setAladdinState(AladdinState state);
	void setDirection(Direction dir);
	void Render(int DeltaTime);
};