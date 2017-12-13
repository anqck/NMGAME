#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"

enum LampState
{
	LampState_Normal,
	LampState_Disappear
};

class Lamp : public GameVisibleEntity
{
public:
	Lamp();
	Lamp(D3DXVECTOR3 pos, MyRECT bb);
	~Lamp();
	
	void						ResetDefault();

	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

	bool						GetCollisioned();

	void						PlaySoundOnState();

protected:
	vector<ObjectState*>		mState;
	LampState					mCurrentState;

	bool						mCollisioned;
};