#include "CTreeObject.h"

#include "Camel.h"
#include "Ground.h"
#include "Rope.h"

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
	this->mGameObject->SetBoundingBox(bb);
}

CTreeObject::~CTreeObject()
{
}

GameVisibleEntity* CTreeObject::NewGameObject(int id, D3DXVECTOR3 pos, MyRECT bb)
{
	switch ((EObjectID)id)
	{
	case  EObjectID::GROUND:
		return new Ground();
	case  EObjectID::ROPE:
		return new Rope();
	case EObjectID::CAMEL:
	case EObjectID::THROWPOT:
		return new Camel(pos);
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
