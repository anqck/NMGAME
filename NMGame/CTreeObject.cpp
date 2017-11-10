#include "CTreeObject.h"

CTreeObject::CTreeObject()
{
}

CTreeObject::CTreeObject(int key, int id, D3DXVECTOR3 pos, MyRECT bb)
{
	this->mKey = key;
	this->mID = id;
	this->mPosition = pos;
	this->mBoundingBox = MyRECT(bb);
}

CTreeObject::~CTreeObject()
{
}
