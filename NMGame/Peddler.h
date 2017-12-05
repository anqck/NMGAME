#pragma once
#include "Enemy.h"
#include "FireGround.h"
#include "ShopText.h"

enum PeddlerState
{
	PeddlerState_DoNothing,
	PeddlerState_WithShopDoNothing,
	PeddlerState_ShopAppear,
	PeddlerState_Wait,
	PeddlerState_WaitWithShop,
	PeddlerState_WaitWithShop2

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
	MyRECT						GetItem2BoundingBox();


private:
	PeddlerState				mCurrentState;

	ShopText*					mShopText;





};