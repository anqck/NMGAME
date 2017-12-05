#pragma once
#include "Enemy.h"
#include "FlyingKnife.h"
#include "AladdinCharacter.h"
enum Enemy4State
{
	Enemy4State_DoNothing,
	Enemy4State_Wait,
	Enemy4State_Run,
	Enemy4State_Attack,

	Enemy4State_TuotQuan,
	Enemy4State_Explosion
};
class Enemy4 : public Enemy
{
public:
	Enemy4();
	Enemy4(MyRECT bb, D3DXVECTOR3 pos);
	~Enemy4();

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

private:
	D3DXVECTOR3					mDefaultPosition;
	Enemy4State					mCurrentState;


	D3DXVECTOR3					mLastAladdinPosInInteractBox;



};