#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"
#include "KeyboardHelper.h"
#include "Global.h"


enum FlyingKnifeState
{
	FlyingKnifeState_Normal,
	FlyingKnifeState_Explosion
};
class FlyingKnife : public GameVisibleEntity
{
public:
	FlyingKnife() : GameVisibleEntity() {};
	FlyingKnife(D3DXVECTOR3	pos, Direction dir);
	FlyingKnife(D3DXVECTOR3	pos, Direction dir, D3DXVECTOR2 defaultVelocity, D3DXVECTOR2 acceleration) ;

	~FlyingKnife();

	void						Update(float DeltaTime);
	void						Render(float DeltaTime);

	virtual ObjectState*		GetCurrentState();

	FlyingKnifeState			GetCurrenStateID();

	bool						isDone();

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);
	void						processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith);


protected:
	vector<ObjectState*>		mState;
	Direction					mDir;
	D3DXVECTOR2					mAcceleration;

	FlyingKnifeState			mCurrentState;

	bool						mDone;
	bool						mCollisioned;

};