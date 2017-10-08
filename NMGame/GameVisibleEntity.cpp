#include "GameVisibleEntity.h"

GameVisibleEntity::GameVisibleEntity()
{
}

GameVisibleEntity::GameVisibleEntity(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 pos)
{
	this->mSpriteHandle = SpriteHandle;
	this->mPosition = pos;
}
