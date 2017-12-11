#pragma once
#include "Enemy.h"

enum JafarState
{
	JafarState_DoNothing,
	JafarState_Hut,
	JafarState_Snake
};
class Jafar : public Enemy
{
public:
	Jafar();
	Jafar( D3DXVECTOR3 pos,AladdinCharacter* aladdin);
	~Jafar();

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

	JafarState					mCurrentState;

	AladdinCharacter*			mAladdin;



};