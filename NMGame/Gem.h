#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"

enum GemState
{
	GemState_Normal,
	GemState_Shine,
	GemState_Disappear
};

class Gem : public GameVisibleEntity
{
public:
	Gem();
	Gem(D3DXVECTOR3 pos);
	~Gem();

	void						ResetDefault();

	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

protected:
	vector<ObjectState*>		mState;
	GemState					mCurrentState;
};