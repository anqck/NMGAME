#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"
#include "KeyboardHelper.h"
#include "Global.h"


enum ThrowingAppleState
{
	Normal,
	Explosion
};
class ThrowingApple : public GameVisibleEntity
{
public:
	ThrowingApple() : GameVisibleEntity() {};
	ThrowingApple(D3DXVECTOR3	pos, Direction dir) ;
	ThrowingApple(D3DXVECTOR3	pos, Direction dir, D3DXVECTOR2 defaultVelocity) :ThrowingApple(pos, dir) { this->mVelocity = defaultVelocity; };
	~ThrowingApple();

	void						Update(float DeltaTime);
	void						Render(float DeltaTime);

	virtual ObjectState*		GetCurrentState();

	bool						isDone();

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);


protected:
	vector<ObjectState*>		mState;
	Direction					mDir;

	ThrowingAppleState			mCurrentState;

	bool						mDone;
	bool						mCollisioned;
	 
};