#pragma once

#include "Enemy.h"
#include "Fire.h"

//enum FireGroundState
//{
//	FireGroundState_Normal,
//	FireGroundState_Fire
//};
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

	MyRECT						GetAttackBoundingBox();

	Fire*						GetCurrentIntersectFire();

private:
	vector<ObjectState*>		mState;
	Fire*						mCurrentIntersectFire;

	vector<Fire*>				mFireArr;

	AladdinCharacter*			mAladdin;
	D3DXVECTOR3					mLastAladdinPosInInteractBox;

	bool						mOnFire;

};
