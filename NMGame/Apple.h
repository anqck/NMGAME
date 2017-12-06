#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"

enum AppleState
{
	AppleState_Normal,
	AppleState_Disappear
};

class Apple : public GameVisibleEntity
{
public:
	Apple();
	Apple(D3DXVECTOR3 pos);
	~Apple();

	void						ResetDefault();

	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

protected:
	vector<ObjectState*>		mState;
	AppleState					mCurrentState;
};