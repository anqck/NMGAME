#include "GameVisibleEntity.h"

GameVisibleEntity::GameVisibleEntity(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 pos)
{
	this->mSpriteHandler = SpriteHandle;
	this->mPosition = pos;
}
