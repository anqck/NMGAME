#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"

enum HealthState
{
	HeathState_Normal,
	HeathState_Disappear
};

class Health : public GameVisibleEntity
{
public:
	Health();
	Health(D3DXVECTOR3 pos);
	~Health();

	void						ResetDefault();

	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

protected:
	vector<ObjectState*>		mState;
	HealthState					mCurrentState;
};