#include "CTreeObject.h"

#include "Camel.h"

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
}

CTreeObject::~CTreeObject()
{
}

GameVisibleEntity* CTreeObject::NewGameObject(int id, D3DXVECTOR3 pos, MyRECT bb)
{
	switch ((EObjectID)id)
	{
	case EObjectID::CAMEL:
		return new Camel(pos);
	}
}
