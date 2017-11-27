#include "CollapseGround.h"

CollapseGround::CollapseGround()
{
	this->mHeight = 30;
	this->mWidth = 60;

	this->mID = EObjectID::COLLAPSEGROUND;

	mCollisionFlag = false;

	mTime = 0;
}

CollapseGround::CollapseGround(D3DXVECTOR3 pos) : CollapseGround()
{
	this->mPosition = pos;

	this->mCurrentState = CollapseGroundState::CollapseGroundState_Nothing;

	std::vector<MyRECT> temp;

	temp.push_back(MyRECT(0, 0, 32, 16));
	this->mState.push_back(new ObjectState(temp, 13, L"Object\\StaticObject\\CollapseGround.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	temp.push_back(MyRECT(82, 0, 32, 101));
	temp.push_back(MyRECT(53, 0, 33, 81,D3DXVECTOR3(0,-12,0)));
	temp.push_back(MyRECT(0, 70, 104, 37, D3DXVECTOR3(0, -30, 0)));
	temp.push_back(MyRECT(0, 35, 69, 43, D3DXVECTOR3(0, -35, 0)));
	temp.push_back(MyRECT(0, 0, 34, 52, D3DXVECTOR3(0, -45, 0)));
	temp.push_back(MyRECT(44, 35, 67, 104, D3DXVECTOR3(0, -54, 0)));
	temp.push_back(MyRECT(38, 70, 101, 93, D3DXVECTOR3(0, -58, 0)));
	temp.push_back(MyRECT(0, 105, 134, 53, D3DXVECTOR3(0, -64, 0)));
	temp.push_back(MyRECT(0, 135, 162, 28, D3DXVECTOR3(0, -69, 0)));
	temp.push_back(MyRECT(0, 135, 162, 28, D3DXVECTOR3(0, -72, 0)));
	temp.push_back(MyRECT(0, 0, 0, 0, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, 0, 0, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, 0, 0, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, 0, 0, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, 0, 0, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, 0, 0, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, 0, 0, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, 0, 0, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, 0, 0, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, 0, 0, D3DXVECTOR3(0, 0, 0)));

	this->mState.push_back(new ObjectState(temp, 13, L"Object\\StaticObject\\CollapsingGround.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));


	this->mState.at(0)->SetPosition(pos);
	this->mState.at(1)->SetPosition(pos);
	temp.clear();
}

CollapseGround::~CollapseGround()
{
}

void CollapseGround::Render(float DeltaTime)

{

	GameVisibleEntity::Render(DeltaTime);
	this->mState.at(mCurrentState)->Render();
}

void CollapseGround::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(mTime);

	switch (mCurrentState)
	{
	case CollapseGroundState::CollapseGroundState_Nothing:
		if (mCollisionFlag)
		{
			if (mTime >= 10 * DeltaTime)
			{
				this->mBoundingBox = MyRECT(1, 1, 1, 1);
				this->mCurrentState = CollapseGroundState::CollapseGroundState_JumpOn;
			}
			else
				mTime += DeltaTime;
		}
		break;
	case CollapseGroundState::CollapseGroundState_JumpOn:
		if (this->mState.at(mCurrentState)->isDone())
		{
			this->mState.at(mCurrentState)->resetFrame();
			this->mCurrentState = CollapseGroundState::CollapseGroundState_Nothing;
			this->mBoundingBox = MyRECT(0, 0, 0, 0);
			mTime = 0;
			this->mCollisionFlag = false;
		}
		break;
			
	}
	
}

void CollapseGround::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	if (obj->GetID() == EObjectID::ALADDIN &&collision.dir == Direction::Up)
	{
		
		mCollisionFlag = true;
	}
		
		return;

	//if (collision.dir == Direction::Up)
		//this->mCurrentState = CamelState::JumpOn;
}
