#pragma once

#include "GameVisibleEntity.h"
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

	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);
	void						processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith);
private:
	vector<ObjectState*>		mState;
	ThrowPotEnemyState			mCurrentState;
};