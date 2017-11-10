#pragma once

#include "Global.h"
#include "MyRECT.h"

enum EObjectID
{
	GROUND,
	ROPE,
	STAIR,
	CAMEL,
	ENEMY
};

class CTreeObject
{
public:
	CTreeObject();
	CTreeObject(int key, int id, D3DXVECTOR3 pos, MyRECT bb);
	~CTreeObject();



private:
	int					mKey;
	int					mID;
	D3DXVECTOR3			mPosition;
	MyRECT				mBoundingBox;

};