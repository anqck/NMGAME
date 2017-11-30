#pragma once
#include "Enemy.h"
#include "FlyingKnife.h"
enum Enemy3State
{
	Eneymy3State_Normal,
	Enemy3State_Explosion
};
class Enemy3 : public Enemy 
{
public:
	Enemy3();
	Enemy3(MyRECT bb, D3DXVECTOR3 pos) ;
	~Enemy3();

	void						Update(float DeltaTime);
	void						Render(float DeltaTime);

	void						processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith);
	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

private:
	Enemy3State				mCurrentState;

	D3DXVECTOR3					mLastAladdinPosInInteractBox;


};