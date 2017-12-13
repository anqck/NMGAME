#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"
#include "Global.h"
#include "AladdinCharacter.h"


enum ThrowPotState
{
	ThrowPot_Normal,
	ThrowPot_Explosion,
	ThrowPot_GroundExplosion
};
class ThrowPot : public GameVisibleEntity
{
public:
	ThrowPot() : GameVisibleEntity() {};
	ThrowPot(D3DXVECTOR3	pos);
	~ThrowPot();

	void						Update(float DeltaTime);
	void						Render(float DeltaTime);

	virtual ObjectState*		GetCurrentState();
	ThrowPotState				GetCurrentStateID();

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);
	void						processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith);

	bool						isDone();

	void						PlaySoundOnState();

protected:
	vector<ObjectState*>		mState;

	ThrowPotState				mCurrentState;

	bool						mDone;
	bool						mCollisioned;

};