
#pragma once
#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"

enum CamelState
{
	DoNothing1,
	JumpOn
};

class Camel : public GameVisibleEntity
{
public:
	Camel();
	Camel(D3DXVECTOR3 pos);
	~Camel();
	
	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

	void						PlaySoundOnState();

protected:
	vector<ObjectState*>		mState;	
	CamelState					mCurrentState;
	
	
};