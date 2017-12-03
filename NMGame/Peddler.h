#pragma once
#include "Enemy.h"
#include "FireGround.h"

enum PeddlerState
{
	PeddlerState_DoNothing,
	PeddlerState_WithShopDoNothing,
	PeddlerState_ShopAppear,
	PeddlerState_Wait,
	PeddlerState_WaitWithShop,

};
class Peddler : public Enemy
{
public:
	Peddler();
	Peddler(MyRECT bb, D3DXVECTOR3 pos);
	~Peddler();

	void						Update(float DeltaTime);
	void						Render(float DeltaTime);

	void						processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith);
	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);


	ObjectState *				GetCurrentState() { return this->mState.at(mCurrentState); }

	MyRECT						GetItem1BoundingBox();



private:
	PeddlerState				mCurrentState;





};