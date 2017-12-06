#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"
#include "SceneManager.h"

enum AbuTokenState
{
	AbuTokenState_1,
	AbuTokenState_2,
	AbuTokenState_Disappear
};

class AbuToken : public GameVisibleEntity
{
public:
	AbuToken();
	AbuToken(D3DXVECTOR3 pos);
	~AbuToken();

	void						ResetDefault();

	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

protected:
	vector<ObjectState*>		mState;
	AbuTokenState			mCurrentState;
};