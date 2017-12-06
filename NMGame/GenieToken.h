#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"
#include "SceneManager.h"

enum GenieTokenState
{
	GenieTokenState_Normal,
	GenieTokenState_NhayMat,
	GenieTokenState_Disappear
};

class GenieToken : public GameVisibleEntity
{
public:
	GenieToken();
	GenieToken(D3DXVECTOR3 pos);
	~GenieToken();

	void						ResetDefault();

	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

protected:
	vector<ObjectState*>		mState;
	GenieTokenState				mCurrentState;
};