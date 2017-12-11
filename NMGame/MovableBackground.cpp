#include "MovableBackground.h"
#include "GraphicsHelper.h"
#include "Camera.h"
MovableBackground::MovableBackground()
{
	this->mPosition0 = D3DXVECTOR3(0, 0, 0);
	this->mPosition1 = D3DXVECTOR3(-2048* 2.68, 0, 0);
	mCurrentOnSceneIdx = 0;
}

MovableBackground::MovableBackground(LPWSTR filePath, int height, D3DXVECTOR2 velocity, float CameraRate) : MovableBackground()
{
	this->mCameraRate = CameraRate;
	this->mPosition0.y = height;
	this->mPosition1.y = height;

	this->mVelocity = velocity;

	D3DXGetImageInfoFromFile(filePath, &mImageInfo0);

	D3DXCreateTextureFromFileEx(GraphicsHelper::GetInstance()->GetDirectDevice(), filePath, mImageInfo0.Width,
		mImageInfo0.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		NULL,
		&mImageInfo0,
		NULL,
		&mTexture0);
}

MovableBackground::~MovableBackground()
{
}

void MovableBackground::Render(float DeltaTime)
{
	GraphicsHelper::GetInstance()->DrawTexture(mTexture0, MyRECT(0,0, mImageInfo0.Width,mImageInfo0.Height), D3DXVECTOR3(0,0,0), this->mPosition0, D3DXVECTOR2(2.2, 2.68), D3DXVECTOR2(0, 0), 0.0f, D3DXVECTOR2(0, 0),D3DCOLOR_ARGB(255,255,255,255) );
	GraphicsHelper::GetInstance()->DrawTexture(mTexture0, MyRECT(0, 0, mImageInfo0.Width, mImageInfo0.Height), D3DXVECTOR3(0, 0, 0), this->mPosition1, D3DXVECTOR2(2.2, 2.68), D3DXVECTOR2(0, 0), 0.0f, D3DXVECTOR2(0, 0), D3DCOLOR_ARGB(255, 255, 255, 255));
}

void MovableBackground::Update(float DeltaTime)
{
	

	if (this->mCurrentOnSceneIdx == 0)
	{
		if (this->mPosition0.x + BG_WIDTH <= GLOBAL::GetWindowsWidth() + 10)
		{
			this->mPosition1 = D3DXVECTOR3(this->mPosition0.x + BG_WIDTH, this->mPosition0.y,0);
			this->mCurrentOnSceneIdx = 1;
		}
		else if (this->mPosition0.x > 0)
		{
			this->mPosition1 = D3DXVECTOR3(this->mPosition0.x - BG_WIDTH, this->mPosition0.y, 0);
			this->mCurrentOnSceneIdx = 1;
		}
	}
	else
	{
		if (this->mPosition1.x + BG_WIDTH <= GLOBAL::GetWindowsWidth() + 10)
		{
			this->mPosition0 = D3DXVECTOR3(this->mPosition1.x + BG_WIDTH, this->mPosition1.y, 0);
			mCurrentOnSceneIdx = 0;
		}
		else if (this->mPosition1.x > 0)
		{
			this->mPosition0 = D3DXVECTOR3(this->mPosition1.x - BG_WIDTH, this->mPosition1.y, 0);
			this->mCurrentOnSceneIdx = 0;
		}
	}

	this->mPosition0 = D3DXVECTOR3(this->mPosition0.x + mVelocity.x * DeltaTime - Camera::GetInstance()->GetVelocity().x * this->mCameraRate, this->mPosition0.y + mVelocity.y * DeltaTime, 0);
	this->mPosition1 = D3DXVECTOR3(this->mPosition1.x + mVelocity.x * DeltaTime - Camera::GetInstance()->GetVelocity().x * this->mCameraRate, this->mPosition1.y + mVelocity.y * DeltaTime, 0);
}

MyRECT MovableBackground::GetBoundingBox0()
{
	return MyRECT();
}
