#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"

enum CheckPointState
{
	CheckPointState_Normal,
	CheckPointState_Check,
	CheckPointState_Revise
};

class CheckPoint : public GameVisibleEntity
{
public:
	CheckPoint();
	CheckPoint(D3DXVECTOR3 pos);
	~CheckPoint();

	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

	CheckPointState				GetCurrentStateID();
protected:
	vector<ObjectState*>		mState;
	CheckPointState				mCurrentState;


	int							mLastCheckPointScore;
};