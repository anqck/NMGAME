
#pragma once
#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"

enum CollapseGroundState
{
	CollapseGroundState_Nothing,
	CollapseGroundState_JumpOn
};

class CollapseGround : public GameVisibleEntity
{
public:
	CollapseGround();
	CollapseGround(D3DXVECTOR3 pos);
	~CollapseGround();

	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

protected:
	bool						mCollisionFlag;

	vector<ObjectState*>		mState;
	CollapseGroundState			mCurrentState;


};