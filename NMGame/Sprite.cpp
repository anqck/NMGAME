#include "Sprite.h"
#include "Camera.h"

Sprite::Sprite( LPWSTR FilePath, D3DCOLOR transcolor, vector<MyRECT> listSourceRect, CenterArchor center)
{

	this->mPosition = D3DXVECTOR3(0, 0, 0);

	this->mCenterArchor = center;

	this->mListRect = listSourceRect;

	mSourceRect = listSourceRect.at(0);

	this->isFlipVertical = false;

	D3DXGetImageInfoFromFile(FilePath, &mImageInfo);

	D3DXCreateTextureFromFileEx(GraphicsHelper::GetInstance()->GetDirectDevice(), FilePath, mImageInfo.Width,
		mImageInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transcolor,
		&mImageInfo,
		NULL,
		&mTexture);


}

Sprite::~Sprite()
{
	if (mTexture)
		mTexture->Release();
}


void Sprite::SetFrame(int frameIdx)
{
	mSourceRect = mListRect.at(frameIdx);
}

D3DXVECTOR3 Sprite::GetPosition()
{
	return this->mPosition;
}

void Sprite::SetPosition(D3DXVECTOR3 Position)
{
	this->mPosition = Position;
}

void Sprite::SetPosition(int X, int Y)
{
	 D3DXVECTOR3 position((float)X, (float)Y, 0);
	 this->mPosition = position;
}

D3DXVECTOR2 Sprite::GetScale()
{
	return this->mScale;
}

void Sprite::SetScale(D3DXVECTOR2 scale)
{
	this->mScale = scale;
}

void Sprite::SetScale(float x, float y)
{
	this->mScale = D3DXVECTOR2(x, y);
}

MyRECT Sprite::GetSourceRect()
{
	return mSourceRect;
}

bool Sprite::IsFlipVertical()
{
	return this->isFlipVertical;
}

void Sprite::FlipVertical(bool flip_vertical)
{
	this->isFlipVertical = flip_vertical;
}

TransformObject Sprite::GetTransformPosition()
{
	TransformObject		mTransformObject;

	//Get aladdin pos in ViewPort
	mTransformObject.mPosition = ViewPort::GetInstance()->getViewPortPosition(this->mPosition);

	//Get camera pos in ViewPort
	D3DXVECTOR3 cameraPositionInView = ViewPort::GetInstance()->getViewPortPosition(Camera::GetInstance()->GetPosition());

	//Translation vector
	mTransformObject.mTranslation = D3DXVECTOR3(-cameraPositionInView.x, -cameraPositionInView.y, 0);

	mTransformObject.mPosition += mTransformObject.mTranslation;

	return mTransformObject;
}

MyRECT Sprite::GetCurrentFrameBoundingBox()
{
	MyRECT mBoundingBox;

	int Height = (this->GetSourceRect().bottom - this->GetSourceRect().top) * 2.5;
	int Width = (this->GetSourceRect().right - this->GetSourceRect().left) * 2;

	switch (this->mCenterArchor)
	{
	case CenterArchor::CenterBottom:
		mBoundingBox.left = (mPosition.x + ((isFlipVertical) ? -1 : 1) * this->GetSourceRect().getCenterTranslation().x * 2 ) - Width / 2;
		mBoundingBox.right = (mPosition.x + ((isFlipVertical) ? -1 : 1) * this->GetSourceRect().getCenterTranslation().x * 2 ) + Width / 2 ;
		mBoundingBox.bottom = mPosition.y + this->GetSourceRect().getCenterTranslation().y * 2.5;
		mBoundingBox.top = mPosition.y + this->GetSourceRect().getCenterTranslation().y * 2.5 + Height;
		break;
	case CenterArchor::TopLeft:
		mBoundingBox.left = mPosition.x;
		mBoundingBox.right = mPosition.x + Width ;
		mBoundingBox.top = mPosition.y;
		mBoundingBox.bottom = mPosition.y - Height;
		break;
	case CenterArchor::Center:
		mBoundingBox.left = mPosition.x - Width / 2;
		mBoundingBox.right = mPosition.x + Width/2;
		mBoundingBox.top = mPosition.y + Height / 2;
		mBoundingBox.bottom = mPosition.y - Height / 2;
		break;
	}


	

	return mBoundingBox;
}

void Sprite::Render()
{
	//Temp code
	D3DXVECTOR2 tempScale = D3DXVECTOR2(((isFlipVertical)?-1:1) * 2, 2.5);

	D3DXVECTOR3 center = this->mSourceRect.GetCenterArchorPosision(this->mCenterArchor);

	GraphicsHelper::GetInstance()->DrawTexture(mTexture, this->mSourceRect, center,this->GetTransformPosition().mPosition, tempScale);
	
	//Draw Boundingbox for debug
	//if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_3))
		//GraphicsHelper::GetInstance()->DrawBoundingBox(this->GetCurrentFrameBoundingBox(), D3DCOLOR_XRGB(255, 255, 0));
}
