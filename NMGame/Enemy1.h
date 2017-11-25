#pragma once
#include "Enemy.h"

enum Eneymy1State
{
	Eneymy1State_DoNothing,
	Eneymy1State_Attack,
	Eneymy1State_Run,
	Eneymy1State_Damage,
	Eneymy1State_Explosion
};
class Enemy1 : public Enemy
{
public:
	Enemy1();
	Enemy1(MyRECT bb, D3DXVECTOR3 pos);
	~Enemy1();

	void						Update(float DeltaTime);
	void						Render(float DeltaTime);

	void						processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith);
	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

	MyRECT						GetAttackRange();
	MyRECT						GetAttackBoundingBox();

	ObjectState *				GetCurrentState() { return this->mState.at(mCurrentState); }

private:
	Eneymy1State				mCurrentState;

	D3DXVECTOR3					mLastAladdinPosInInteractBox;
	


};