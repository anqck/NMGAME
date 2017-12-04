#pragma once

#include "Global.h"
#include "MyRECT.h"

#define	BG_WIDTH 1024 * 2.2

class MovableBackground
{
public:
	MovableBackground();
	MovableBackground(LPWSTR filePath, int height, D3DXVECTOR2 velocity, float CameraRate);
	~MovableBackground();

	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	MyRECT						GetBoundingBox0();
private:
	D3DXVECTOR3					mPosition0, mPosition1;
	D3DXVECTOR2					mVelocity;

	LPDIRECT3DTEXTURE9			mTexture0;
	D3DXIMAGE_INFO				mImageInfo0;

	int							mCurrentOnSceneIdx;

	float						mCameraRate;



};