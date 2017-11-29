#pragma once
#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"

enum FireState
{
	FireGroundState_Nothing,
	FireGroundState_Fire,
	FireGroundState_Done
};

class Fire : public GameVisibleEntity
{
public:
	Fire();
	Fire(D3DXVECTOR3 pos);
	~Fire();

	void						Update(float DeltaTime, D3DXVECTOR3 mNewAladdinpos, bool onFire);
	void						Render(float DeltaTime);

	MyRECT						GetAttackBoundingBox();

	ObjectState *				GetCurrentState() { return this->mState.at(mCurrentState); }

	bool						isDone();
private:
	vector<ObjectState*>		mState;
	FireState					mCurrentState;
};