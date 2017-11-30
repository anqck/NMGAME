#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(MyRECT bb, D3DXVECTOR3 pos) : Enemy()
{
	this->mInteractWithInteractBB = true;

	this->mInteractBoundingBox = bb;
	this->mBoundingBox = bb;

	this->mPosition = pos;

}

Enemy::~Enemy()
{
}

D3DXVECTOR2 Enemy::GetVelocity()
{
	return D3DXVECTOR2(0,0);
}
