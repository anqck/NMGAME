#pragma once
#include "AladdinCharacter.h"
#include "AladdinWalk.h"
#include "AladdinLookUp.h"
#include "AladdinRest.h"
#include "AladdinStand.h"
#include "AladdinAttack1.h"
#include "AladdinSit.h"
#include "AladdinSitAttack.h"

enum AladdinState
{
	DoNothing,
	Walk,
	LookUp,
	Stand,
	Sit,
	Rest,
	SitAttack,
	Attack1,
	ActionEnd
	
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
	AladdinSit			*_mAladdinSit;
	AladdinSitAttack	*_mAladdinSitAttack;

	bool				allowStateChange;
public:
	AladdinHelper(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 pos);
	AladdinState getAladdinState();
	void setAladdinState(AladdinState state);
	void setDirection(Direction dir);
	void	setAllowStateChange(bool allow);
	void Render(int DeltaTime);
};