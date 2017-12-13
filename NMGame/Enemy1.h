#pragma once
#include "Enemy.h"

enum Enemy1State
{
	Enemy1State_DoNothing,
	Enemy1State_Attack,
	Enemy1State_Run,
	Enemy1State_Damage,
	Enemy1State_Explosion
};
class Enemy1 : public Enemy
{
public:
	Enemy1();
	Enemy1(MyRECT bb, D3DXVECTOR3 pos);
	~Enemy1();

	void						ResetDefault();

	void						Update(float DeltaTime);
	void						Render(float DeltaTime);

	void						processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith);
	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

	MyRECT						GetAttackRange();
	MyRECT						GetAttackBoundingBox();

	ObjectState *				GetCurrentState() { return this->mState.at(mCurrentState); }

	D3DXVECTOR2					GetVelocity();

	bool						isDone();

	void						PlaySoundOnState();

private:
	D3DXVECTOR3					mDefaultPosition;
	Enemy1State					mCurrentState;

	D3DXVECTOR3					mLastAladdinPosInInteractBox;
	


};