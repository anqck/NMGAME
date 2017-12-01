#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"
#include "KeyboardHelper.h"
#include "Global.h"



class FlyingCamalSaliva : public GameVisibleEntity
{
public:
	FlyingCamalSaliva() : GameVisibleEntity() {};
	FlyingCamalSaliva(D3DXVECTOR3	pos);
	FlyingCamalSaliva(D3DXVECTOR3	pos, D3DXVECTOR2 defaultVelocity, D3DXVECTOR2 acceleration);

	~FlyingCamalSaliva();

	void						Update(float DeltaTime);
	void						Render(float DeltaTime);

	bool						isDone();

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);
	void						processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith);

	ObjectState*				GetCurrentState();

protected:
	ObjectState*				mState;
	Direction					mDir;
	D3DXVECTOR2					mAcceleration;

	D3DXVECTOR3					mDefaultPosition;

	bool						mDone;
	bool						mCollisioned;

};