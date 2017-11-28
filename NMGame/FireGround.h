#pragma once

#include "Enemy.h"

enum FireGroundState
{
	FireGroundState_Normal,
	FireGroundState_Fire
};
class FireGround : public Enemy
{
public:
	FireGround();
	FireGround(MyRECT bb);
	~FireGround();

	void						Update(float DeltaTime);
	void						Render(float DeltaTime);

	void						processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith);
	//void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

	//MyRECT						GetAttackBoundingBox();

	ObjectState *				GetCurrentState() { return this->mState.at(mCurrentState); }

private:
	FireGroundState				mCurrentState;

	bool						mOnFire;

};
