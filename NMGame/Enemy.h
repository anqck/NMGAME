#pragma once
#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"
#include "AladdinCharacter.h"

class Enemy : public GameVisibleEntity
{
public:
	Enemy();
	Enemy(MyRECT bb, D3DXVECTOR3 pos);
	~Enemy();

	virtual void				processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision) {};
	virtual void				processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith) {};

	virtual MyRECT				GetAttackBoundingBox() { return MyRECT(0, 0, 0, 0); };
	virtual ObjectState *		GetCurrentState() { return this->mState.at(mCurrentState); }

	virtual D3DXVECTOR2			GetVelocity();

	virtual bool				isDone() { return mDone; };
protected:
	int			mHP;


	vector<ObjectState*>		mState;
	Direction					mDir;

	int							mCurrentState;

	bool						mDone;



	
};