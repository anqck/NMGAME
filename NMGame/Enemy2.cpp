#include "Enemy2.h"

Enemy2::Enemy2() : Enemy::Enemy()
{
	this->mCanBeAttack = true;
	this->mCanBeHitByFlyingObject = true;
	this->mInteractWithInteractBB = true;
	this->mCanBeHitByFlyingObject = true;
	this->mCanAttack = true;

	mLastAladdinPosInInteractBox = D3DXVECTOR3(0, 0, 0);

	this->mID = EObjectID::ENEMY2;

	this->mDone = false;

	this->mCurrentState = Eneymy2State::Eneymy2State_DoNothing;

	mWidth = 40;
	mHeight = 140;

	this->mHP = 2;
}

Enemy2::Enemy2(MyRECT bb, D3DXVECTOR3 pos)
{
}

Enemy2::~Enemy2()
{
}

void Enemy2::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();
}

void Enemy2::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);
	//GraphicsHelper::GetInstance()->DrawBoundingBox(this->GetAttackRange(), D3DCOLOR_XRGB(255,0,255));

	this->mState.at(mCurrentState)->Render();
}

void Enemy2::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
}

void Enemy2::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
}

MyRECT Enemy2::GetAttackRange()
{
	return MyRECT();
}

MyRECT Enemy2::GetAttackBoundingBox()
{
	return MyRECT();
}
