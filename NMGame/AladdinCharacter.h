#pragma once
#ifndef _ALADDIN_H__
#define _ALADDIN_H__
#include "Global.h"
#include "GameLog.h"
#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"
#include "MyRECT.h"
#include <vector>
#include <map>

enum AState
{
	DoNothing,
	Walk,
	StopWalk,
	LookUp,
	Stand,
	Sit,
	Rest,
	SitAttack,
	Attack1,
	RopeClimb,
	RunAndJump,
	ThrowApple,
	SitThrow
};

enum Direction
{
	Left,
	Right,
	Up,
	Down
};

class AladdinCharacter : public GameVisibleEntity
{
public:
	AladdinCharacter();
	AladdinCharacter( D3DXVECTOR3	pos);


	void			Update(float DeltaTime);
	void			Render(float DeltaTime);			//
	void			OnKeyDown(int keyCode);
	void			OnKeyUp(int keyCode);
	void			ProcessInput();

	AState			getCurrentState();
	void			setCurrentState(AState state);

	void			setDirection(Direction dir);

	void			setAllowStateChange(bool allow);



protected:
	//vector<AladdinState*>	mAladdinState;

	vector<ObjectState*>	mAladdinState;

	AState					mCurrentState;
	Direction				mDir;
	//LPD3DXSPRITE			mSpriteHandle;
	//D3DXVECTOR3			mPosition;

	bool					allowStateChange;
	float					mTime;					//Đếm thời gian 
	float					mStopWalkThresHold;
	bool					mIsStopAnimation;

	bool					allowAttack;
	bool					allowJump;
	bool					allowAction;
	bool					isClimbing;

	void					_BeforeStateChange(AState &changeTo);
	void					_AfterStateChange();

	bool		 flagKeyPressed ;


	
};

#endif _ALADDIN_H__