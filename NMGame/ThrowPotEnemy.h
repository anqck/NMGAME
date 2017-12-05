#pragma once

#include "Enemy.h"
#include "ObjectStateWithLoop.h"
#include "SceneManager.h"
#include "ThrowPot.h"

enum ThrowPotEnemyState
{
	ThrowPotEnemy_DoNothing,
	ThrowPotEnemy_ThrowingPot,
	ThrowPotEnemy_Explosion
};

class ThrowPotEnemy : public GameVisibleEntity
{
public:
	ThrowPotEnemy();
	ThrowPotEnemy(D3DXVECTOR3 pos);
	~ThrowPotEnemy();

	void						ResetDefault();

	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);
	void						processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith);

	ObjectState *				GetCurrentState() { return this->mState.at(mCurrentState); }

	bool						isDone();

	ThrowPotEnemyState			GetCurrentStateID();
private:


	vector<ObjectState*>		mState;
	ThrowPotEnemyState			mCurrentState;
};