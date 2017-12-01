#include "FlyingCamelSaliva.h"

FlyingCamalSaliva::FlyingCamalSaliva(D3DXVECTOR3 pos) : FlyingCamalSaliva()
{
	mAcceleration = D3DXVECTOR2(0, 0);
	mCollisioned = false;

	this->mDone = false;
	this->mCanAttack = true;

	this->mID = EObjectID::THROWINGCAMELSALIVA;

	this->mDefaultPosition = this->mPosition = pos;
	this->mTime = 0;
	this->mDone = 0;

	this->mInteractBoundingBox = MyRECT(0, 0, 0, 0);
	this->mBoundingBox = MyRECT(0, 0, 0, 0);



	mWidth = 30;
	mHeight = 30;

	vector<MyRECT> temp;

	temp.push_back(MyRECT(20, 0, 24, 31));
	temp.push_back(MyRECT(0, 0, 31, 19,D3DXVECTOR3(-4,-8,0)));
	temp.push_back(MyRECT(0, 43, 51, 8, D3DXVECTOR3(+4, 3, 0)));
	temp.push_back(MyRECT(8, 32, 40, 18, D3DXVECTOR3(+2, 1, 0)));
	temp.push_back(MyRECT(0, 32, 42, 7, D3DXVECTOR3(+2, 1, 0)));

	this->mState = new ObjectStateWithLoop(temp, 11, L"Object\\FlyingCamelSaliva.png", D3DXVECTOR2(0, 0),1, CenterArchor::CenterBottom);
	this->mState->SetPosition(pos);
	temp.clear();

 	this->mState->SetFlipVertical(false);

}

FlyingCamalSaliva::FlyingCamalSaliva(D3DXVECTOR3 pos, D3DXVECTOR2 defaultVelocity, D3DXVECTOR2 acceleration) : FlyingCamalSaliva(pos)
{
	this->mVelocity = defaultVelocity;
	this->mAcceleration = acceleration;
}

FlyingCamalSaliva::~FlyingCamalSaliva()
{
}

void FlyingCamalSaliva::Update(float DeltaTime)
{
	this->mState->Update(DeltaTime);
	this->mPosition = this->mState->GetPosition();

	this->mState->SetVelocity(this->mVelocity.x, this->mVelocity.y);

	if (this->mState->GetPosition().x > mDefaultPosition.x + 1000)
		mDone = true;

}

void FlyingCamalSaliva::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState->Render();
}

bool FlyingCamalSaliva::isDone()
{
	return this->mDone;
}

void FlyingCamalSaliva::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::GROUND:
	case EObjectID::WALL:
	case EObjectID::STAIR:
	case EObjectID::ENEMY3:
	case EObjectID::ENEMY4:
		mDone = true;
		break;


	}
}

void FlyingCamalSaliva::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
}

ObjectState * FlyingCamalSaliva::GetCurrentState()
{
	return this->mState;
}
