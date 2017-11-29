#pragma once
#include "Enemy.h"

enum Eneymy2State
{
	Eneymy2State_DoNothing,
	Eneymy2State_Attack1,
	Eneymy2State_Attack2,
	Eneymy2State_Run,
	Eneymy2State_Damage,
	Eneymy2State_Explosion
};
class Enemy2 : public Enemy
{
public:
	Enemy2();
	Enemy2(MyRECT bb, D3DXVECTOR3 pos);
	~Enemy2();

	void						Update(float DeltaTime);
	void						Render(float DeltaTime);

	void						processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith);
	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

	MyRECT						GetAttackRange();
	MyRECT						GetAttackBoundingBox();

	ObjectState *				GetCurrentState() { return this->mState.at(mCurrentState); }

private:
	Eneymy2State				mCurrentState;

	D3DXVECTOR3					mLastAladdinPosInInteractBox;



};