#pragma once
#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"


enum BossFireState
{
	BossFireState_Fire,
};

class BossFire : public GameVisibleEntity
{
public:
	BossFire();
	BossFire(D3DXVECTOR3 pos, Direction Dir);
	~BossFire();

	void						Update(float DeltaTime);
	void						Render(float DeltaTime);

	MyRECT						GetAttackBoundingBox();

	ObjectState *				GetCurrentState() { return this->mState.at(mCurrentState); }

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

	bool						isDone();
private:
	vector<ObjectState*>		mState;
	BossFireState				mCurrentState;

	D3DXVECTOR2					mVelocity;
	Direction					mDir;
};