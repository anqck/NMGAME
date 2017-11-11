#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__
#include "Global.h"
#include <vector>
#include "MyRECT.h"
#include "Sprite.h"
#include "ViewPort.h"

enum EObjectID
{
	GROUND,
	ROPE,
	STAIR,
	CAMEL,
	ENEMY
};

class GameVisibleEntity {
protected:
	EObjectID				mID;

	Sprite*					mSprite;

	int						mWidth, mHeight;

	D3DXVECTOR3				mPosition;
	D3DXVECTOR2				mVelocity;

	MyRECT					mBoundingBox;

	float					mTime;
	int						ANIMATE_RATE;

public:
	GameVisibleEntity();
	GameVisibleEntity( D3DXVECTOR3 pos);
	GameVisibleEntity( int X, int Y);

	virtual void			Render(float DeltaTime) ;
	virtual void			Update(float DeltaTime);

	virtual D3DXVECTOR3		getViewPortPosition();

	EObjectID				GetID();
	void					SetID(EObjectID id);

	D3DXVECTOR3				GetPosition();
	void					SetPosition(D3DXVECTOR3 Position);
	void					SetPosition(int X, int Y);

	void					SetWidthAndHeight(int width, int height);

	TransformObject			GetTransformPosition();

	virtual MyRECT			GetBoundingBox();
	void					SetBoundingBox(MyRECT rect);
	

};

#endif __OBJECT_H__