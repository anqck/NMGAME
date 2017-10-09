#include "GameVisibleEntity.h"

GameVisibleEntity::GameVisibleEntity()
{
	this->mPosition = D3DXVECTOR3(0, 0, 0);
}


GameVisibleEntity::GameVisibleEntity( D3DXVECTOR3 pos)
{
	this->mPosition = pos;
}

GameVisibleEntity::GameVisibleEntity( int X, int Y)
{
	this->mPosition.x = X;
	this->mPosition.y = Y;
}
