#include "GameVisibleEntity.h"

#include "Camera.h"
GameVisibleEntity::GameVisibleEntity()
{
	this->mPosition = D3DXVECTOR3(0, 0, 0);

	this->mInteractBoundingBox = MyRECT(0, 0, 0, 0);

	this->mCanAttack = false;
	this->mCanBeAttack = false;
}


GameVisibleEntity::GameVisibleEntity( D3DXVECTOR3 pos)
{
	this->mPosition = pos;

	this->mInteractBoundingBox = MyRECT(0,0,0,0);

	this->mCanAttack = false;
	this->mCanBeAttack = false;
}

GameVisibleEntity::GameVisibleEntity( int X, int Y)
{
	this->mPosition.x = X;
	this->mPosition.y = Y;

	this->mInteractBoundingBox = MyRECT(0, 0, 0, 0);

	this->mCanAttack = false;
	this->mCanBeAttack = false;
}

void GameVisibleEntity::Render(float DeltaTime)
{
	GraphicsHelper::GetInstance()->DrawBoundingBox(this->GetBoundingBox());

	if (this->mInteractBoundingBox.bottom != this->mInteractBoundingBox.top != this->mInteractBoundingBox.left != this->mInteractBoundingBox.right != 0)
	{
		GraphicsHelper::GetInstance()->DrawBoundingBox(this->mInteractBoundingBox);
	}
}

void GameVisibleEntity::Update(float DeltaTime)
{
}

D3DXVECTOR3 GameVisibleEntity::getViewPortPosition()
{
	return ViewPort::GetInstance()->getViewPortPosition(this->mPosition);
}

EObjectID GameVisibleEntity::GetID()
{
	return mID;
}

void GameVisibleEntity::SetID(EObjectID id)
{
	this->mID = id;
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
	if (this->mInteractBoundingBox.bottom != this->mInteractBoundingBox.top != this->mInteractBoundingBox.left != this->mInteractBoundingBox.right != 0)
	{
		mBoundingBox.left = mPosition.x - mWidth / 2;
		mBoundingBox.right = mPosition.x + mWidth / 2;

		/*mBoundingBox.top = mPosition.y - mHeight / 2;
		mBoundingBox.bottom = mPosition.y + mHeight / 2;*/

		mBoundingBox.top = mPosition.y + mHeight;
		mBoundingBox.bottom = mPosition.y;
	}
	
	return mBoundingBox;
}

void GameVisibleEntity::SetBoundingBox(MyRECT rect)
{
	this->mBoundingBox = rect;
}

MyRECT GameVisibleEntity::GetInteractBoundingBox()
{
	return this->mInteractBoundingBox;
}

void GameVisibleEntity::SetInteractBoundingBox(MyRECT rect)
{
	this->mInteractBoundingBox = rect;
}

ObjectState * GameVisibleEntity::GetCurrentState()
{
	return nullptr;
}

void GameVisibleEntity::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
}


