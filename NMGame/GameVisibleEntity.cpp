#include "GameVisibleEntity.h"

#include "Camera.h"
GameVisibleEntity::GameVisibleEntity()
{
	this->mPosition = D3DXVECTOR3(0, 0, 0);
	this->mVelocity = D3DXVECTOR2(0, 0);

	this->mBoundingBox = MyRECT(0, 0, 0, 0);
	this->mInteractBoundingBox = MyRECT(0, 0, 0, 0);

	this->mCanBeHitByFlyingObject = false;
	this->mInteractWithInteractBB = false;
	this->mCanBeAttack = false;
	this->mCanAttack = false;

	mDone = false;
}


GameVisibleEntity::GameVisibleEntity( D3DXVECTOR3 pos)
{
	this->mPosition = pos;
	this->mVelocity = D3DXVECTOR2(0, 0);

	this->mBoundingBox = MyRECT(0, 0, 0, 0);
	this->mInteractBoundingBox = MyRECT(0,0,0,0);

	this->mCanBeHitByFlyingObject = false;
	this->mInteractWithInteractBB = false;
	this->mCanBeAttack = false;
	this->mCanAttack = false;

	this->mStairLayer = 0;
	mDone = false;
}

GameVisibleEntity::GameVisibleEntity( int X, int Y)
{
	this->mPosition.x = X;
	this->mPosition.y = Y;

	this->mVelocity = D3DXVECTOR2(0, 0);

	this->mBoundingBox = MyRECT(0, 0, 0, 0);
	this->mInteractBoundingBox = MyRECT(0, 0, 0, 0);

	this->mCanBeHitByFlyingObject = false;
	this->mInteractWithInteractBB = false;
	this->mCanBeAttack = false;
	this->mCanAttack = false;

	this->mStairLayer = 0;
	
	mDone = false;
}

GameVisibleEntity::~GameVisibleEntity()
{

}

void GameVisibleEntity::ResetDefault()
{

}

void GameVisibleEntity::Render(float DeltaTime)
{
	if(KeyboardHelper::GetInstance()->IsKeyDown(DIK_1))
		GraphicsHelper::GetInstance()->DrawBoundingBox(this->GetBoundingBox(), D3DCOLOR_XRGB(255, 0, 0));

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_2))
		/*if (this->mInteractBoundingBox.bottom != this->mInteractBoundingBox.top != this->mInteractBoundingBox.left != this->mInteractBoundingBox.right != 0)
		{*/
			GraphicsHelper::GetInstance()->DrawBoundingBox(this->mInteractBoundingBox, D3DCOLOR_XRGB(0, 0, 255));
		//}
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

D3DXVECTOR2 GameVisibleEntity::GetVelocity()
{
	return D3DXVECTOR2(0,0);
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
	if (this->mBoundingBox.bottom == 0 && this->mBoundingBox.top == 0 && this->mBoundingBox.left == 0 && this->mBoundingBox.right == 0)
	{
		return MyRECT(mPosition.y + mHeight, mPosition.x - mWidth / 2, mPosition.x + mWidth / 2, mPosition.y);
	}
	else
		return mBoundingBox;
}

void GameVisibleEntity::SetBoundingBox(MyRECT rect)
{
	this->mBoundingBox = rect;
}

void GameVisibleEntity::UpdateBoundingBox()
{
	this->mBoundingBox = MyRECT(mPosition.y + mHeight, mPosition.x - mWidth / 2, mPosition.x + mWidth / 2, mPosition.y);
}

MyRECT GameVisibleEntity::GetInteractBoundingBox()
{
	return this->mInteractBoundingBox;
}

void GameVisibleEntity::SetInteractBoundingBox(MyRECT rect)
{
	this->mInteractBoundingBox = rect;
}

MyRECT GameVisibleEntity::GetAttackBoundingBox()
{
	return MyRECT(0,0,0,0);
}

bool GameVisibleEntity::GetCanBeHitByFlyingObject()
{
	return this->mCanBeHitByFlyingObject;
}

bool GameVisibleEntity::GetInteractWithInteractBB()
{
	return this->mInteractWithInteractBB;
}

bool GameVisibleEntity::GetCanBeAttack()
{
	return this->mCanBeAttack;
}

bool GameVisibleEntity::GetCanAttack()
{
	return this->mCanAttack;
}

void GameVisibleEntity::SetStairLayer(int flag)
{
	this->mStairLayer = flag;
}

int GameVisibleEntity::GetStairLayer()
{
	return this->mStairLayer;
}

ObjectState * GameVisibleEntity::GetCurrentState()
{
	return nullptr;
}

void GameVisibleEntity::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
}

void GameVisibleEntity::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
	
	


}


