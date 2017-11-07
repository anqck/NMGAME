#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__
#include "Global.h"
#include <vector>
#include "MyRECT.h"
#include "Sprite.h"
#include "ViewPort.h"

class GameVisibleEntity {
protected:
	Sprite*					mSprite;

	int						mWidth, mHeight;

	D3DXVECTOR3				mPosition;
	D3DXVECTOR2				mVelocity;

	MyRECT					mBoundingBox;

	//TransformObject		mTransformObject;

	float					mTime;
	int ANIMATE_RATE;

public:
	GameVisibleEntity();
	GameVisibleEntity( D3DXVECTOR3 pos);
	GameVisibleEntity( int X, int Y);

	virtual void			Render(float DeltaTime) = 0;
	virtual void			Update(float DeltaTime) = 0;

	virtual D3DXVECTOR3		getViewPortPosition();

	D3DXVECTOR3				GetPosition();
	void					SetPosition(D3DXVECTOR3 Position);
	void					SetPosition(int X, int Y);

	void					SetWidthAndHeight(int width, int height);

	TransformObject			GetTransformPosition();

	virtual MyRECT			GetBoundingBox();
	

};

#endif __OBJECT_H__