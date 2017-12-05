#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"

enum HalfAppleState
{
	HalfState_Explosion,
	HalfState_Normal
};

class HalfApple : public GameVisibleEntity
{
public:
	HalfApple();
	HalfApple(D3DXVECTOR3 pos, Direction dir, float vy);
	~HalfApple();

	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	virtual ObjectState*		GetCurrentState();

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

	bool						isDone();

protected:
	vector<ObjectState*>			mState;


	HalfAppleState					mCurrentState;

	Direction						mDir;
};