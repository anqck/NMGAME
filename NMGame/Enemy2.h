#pragma once
#include "Enemy.h"
#include "FireGround.h"

enum Enemy2State
{
	Enemy2State_DoNothing,
	Enemy2State_Attack1,
	Enemy2State_Attack2,
	Enemy2State_Run,
	Enemy2State_Run_FireGround,
	Enemy2State_Taunt,
	Enemy2State_Damage,
	Enemy2State_Explosion
};
class Enemy2 : public Enemy
{
public:
	Enemy2();
	Enemy2(MyRECT bb, D3DXVECTOR3 pos);
	~Enemy2();

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
	Enemy2State					mCurrentState;

	D3DXVECTOR3					mLastAladdinPosInInteractBox;

	FireGround*					mLastFireGround;
	bool						mOnFire;




};