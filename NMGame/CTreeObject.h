#pragma once

#include "Global.h"
#include "MyRECT.h"
#include "GameVisibleEntity.h"



class CTreeObject
{
public:
	CTreeObject();
	CTreeObject(int key, int id, D3DXVECTOR3 pos, MyRECT bb, int stairFlag = 0, int changeto = 0);
	~CTreeObject();

	GameVisibleEntity*	NewGameObject(int id, D3DXVECTOR3 pos, MyRECT bb, int changefr = 0, int changeto = 0);
	GameVisibleEntity*	GetGameObject();

	int					GetKey();


private:
	GameVisibleEntity	*mGameObject;

	int					mKey;
	int					mID;
	D3DXVECTOR3			mPosition;
	MyRECT				mBoundingBox;

};