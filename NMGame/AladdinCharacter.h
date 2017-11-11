#pragma once
#ifndef _ALADDIN_H__
#define _ALADDIN_H__

#include "Global.h"
#include "GameLog.h"
#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"
#include "Collision.h"
#include "MyRECT.h"
#include <vector>
#include <map>

#include "ThrowApple.h"

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
	SitThrow,
	RunAttack,
	StandJump
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

	void			LoadResource();
	AState			getCurrentState();
	void			setCurrentState(AState state);

	ObjectState*	getCurrentObjectState();

	Direction		getDirection();
	void			setDirection(Direction dir);

	void			setAllowStateChange(bool allow);
	
	bool			isGrounded();
	void			SetGrounded(bool allow);

	void			processCollision(float DeltaTime, GameVisibleEntity *obj, CollisionResult collision);

	MyRECT			GetBoundingBox();

	void			PrintLogState();

protected:
	vector<ObjectState*>	mAladdinState;

	AState					mCurrentState;

	Direction				mDir;

	bool					allowStateChange;
	float					mTime;					//Đếm thời gian 
	float					mStopWalkThresHold;
	bool					mIsStopAnimation;

	int						mJumpHeight;
	bool					mIsGrounded;
	bool					mIsReachJumpHeight;
	bool					mIsFalling;
	float					_yCollision;
	bool					_flagGroundCollision;

	bool					allowAttack;
	bool					allowJump;
	bool					allowAction;
	bool					isClimbing;

	void					_BeforeStateChange(AState &changeTo);
	void					_AfterStateChange();

	bool					flagKeyPressed ;

	vector<ThrowingApple*>	mListThrowingApple;	//Các táo ném ra
};

#endif _ALADDIN_H__