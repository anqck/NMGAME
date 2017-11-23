#pragma once
#ifndef _ALADDIN_H__
#define _ALADDIN_H__

#include "Global.h"
#include "GameLog.h"
#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"
#include "SceneManager.h"
#include "Collision.h"
#include "MyRECT.h"
#include <vector>
#include <map>

#include "ThrowApple.h"
#include "StoppingDust.h"

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
	StandJump,
	JumpAttack,
	Push,
	LookUpAttack,
	JumpThrow,
	RunThrow,
	Wait1,
	Wait2,
	RopeJump,
	SwingWait,
	SwingAttack,
	SwingThrow,
	SwingMove,
	Couple,
	Falling
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

	void			CheckCollision(float DeltaTime, vector<GameVisibleEntity*> mListObjectInViewPort);
	void			processCollision(float DeltaTime, GameVisibleEntity *obj, CollisionResult collision);

	void			CheckCollisionWithGround(float DeltaTime, vector<GameVisibleEntity*> mListGround);
	void			CheckCollisionWithRope(float DeltaTime, vector<GameVisibleEntity*> mListRope);

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


	bool					mIsGrounded;
	bool					mWallCollision;

	bool					mRopeCollision;
	bool					mRopeIntersects;
	bool					mReachTopRope;


	float					_yCollision;


	bool					allowAttack;
	bool					allowJump;
	bool					allowAction;
	bool					isClimbing;

	void					_BeforeStateChange(AState &changeTo);
	void					_AfterStateChange();

	bool					flagKeyPressed ;

	StoppingDust*			mStoppingDust;
	//vector<ThrowingApple*>		mListThrowingApple;	//Các táo ném ra

	
						
	vector<GameVisibleEntity*> mListGround;
	vector<GameVisibleEntity*> mListRope;
};

#endif _ALADDIN_H__