#include "GameVisibleEntity.h"

#include "Camera.h"
GameVisibleEntity::GameVisibleEntity()
{
	this->mPosition = D3DXVECTOR3(0, 0, 0);
}


GameVisibleEntity::GameVisibleEntity( D3DXVECTOR3 pos)
{
	this->mPosition = pos;
}

GameVisibleEntity::GameVisibleEntity( int X, int Y)
{
	this->mPosition.x = X;
	this->mPosition.y = Y;
}

D3DXVECTOR3 GameVisibleEntity::getViewPortPosition()
{
	return ViewPort::GetInstance()->getViewPortPosition(this->mPosition);
}

D3DXVECTOR3 GameVisibleEntity::GetPosition()
{
	return this->mPosition;
}

void GameVisibleEntity::SetPosition(D3DXVECTOR3 Position)
{
	this->mPosition = Position;
}

void GameVisibleEntity::SetPosition(int X, int Y)
{
	this->mPosition.x = X;
	this->mPosition.y = Y;
}

void GameVisibleEntity::SetWidthAndHeight(int width, int height)
{
	this->mWidth = width;
	this->mHeight = height;
}

TransformObject GameVisibleEntity::GetTransformPosition()
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

MyRECT GameVisibleEntity::GetBoundingBox()
{
	mBoundingBox.left = mPosition.x - mWidth / 2;
	mBoundingBox.right = mPosition.x + mWidth / 2;
	
	/*mBoundingBox.top = mPosition.y - mHeight / 2;
	mBoundingBox.bottom = mPosition.y + mHeight / 2;*/

	mBoundingBox.top = mPosition.y  ;
	mBoundingBox.bottom = mPosition.y + mHeight;

	return mBoundingBox;
}
