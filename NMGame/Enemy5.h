#pragma once
#include "Enemy.h"
#include "FlyingKnife.h"
#include "AladdinCharacter.h"
enum Enemy5State
{
	Enemy5State_DoNothing,
	Enemy5State_Wait,
	Enemy5State_Run,
	Enemy5State_Attack,
	Enemy5State_Explosion
};
class Enemy5 : public Enemy
{
public:
	Enemy5();
	Enemy5(MyRECT bb, D3DXVECTOR3 pos);
	~Enemy5();

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
	Enemy5State					mCurrentState;

	D3DXVECTOR3					mLastAladdinPosInInteractBox;
};