#include "CTreeObject.h"

#include "Camel.h"
#include "Ground.h"
#include "Rope.h"
#include "ThrowPotEnemy.h"
#include "Stair.h"
#include "Wall.h"
#include "Block.h"
#include "Enemy1.h"
#include "Enemy3.h"
#include "Apple.h"

CTreeObject::CTreeObject()
{
}

CTreeObject::CTreeObject(int key, int id, D3DXVECTOR3 pos, MyRECT bb)
{
	this->mKey = key;
	this->mID = id;
	this->mPosition = pos;
	this->mBoundingBox = MyRECT(bb);

	this->mGameObject = NewGameObject(id, pos, bb);
	//this->mGameObject->SetID((EObjectID) id);
	this->mGameObject->SetInteractBoundingBox(bb);
}

CTreeObject::~CTreeObject()
{
}

GameVisibleEntity* CTreeObject::NewGameObject(int id, D3DXVECTOR3 pos, MyRECT bb)
{
	switch ((EObjectID)id)
	{
	case  EObjectID::GROUND:
		return new Ground(bb);
	case  EObjectID::ROPE:
		return new Rope(bb);
	case  EObjectID::STAIR:
		return new Stair(bb);
	case  EObjectID::WALL:
		return new Wall(bb);
	case  EObjectID::BLOCK:
		return new Block(bb);
	case EObjectID::APPLE:
		return new Apple(pos);
	case EObjectID::CAMEL:
		return new Camel(pos);
	case EObjectID::THROWPOTENEMY:
		return new ThrowPotEnemy(pos);
	case EObjectID::ENEMY1:
		return new Enemy1(bb, pos);
	case EObjectID::ENEMY3:
		return new Enemy3(bb, pos);
	}
}

GameVisibleEntity * CTreeObject::GetGameObject()
{
	return this->mGameObject;
}

int CTreeObject::GetKey()
{
	return mKey;
}
