#include "FireGround.h"

FireGround::FireGround()
{
	this->mInteractWithInteractBB = true;
	this->mCanAttack = true;
	
	mOnFire = false;

	this->mID = EObjectID::FIREGROUND;

	this->mCurrentState = FireGroundState::FireGroundState_Normal;
}

FireGround::FireGround(MyRECT bb):FireGround()
{
	this->mBoundingBox = this->mInteractBoundingBox = bb;
	this->mPosition = D3DXVECTOR3(mBoundingBox.left + (mBoundingBox.right - mBoundingBox.left), mBoundingBox.bottom, 0);

	vector<MyRECT> temp;
	//DoNothing
	temp.push_back(MyRECT(0, 0, 0, 0));
	this->mState.push_back(new ObjectState(temp, 20, L"Object\\Enemy\\Enemy1\\DoNothing.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();

	//Attack
	temp.push_back(MyRECT(119, 0, 44, 177));
	temp.push_back(MyRECT(0, 171, 221, 71, D3DXVECTOR3(-7, 0, 0)));
	temp.push_back(MyRECT(72, 137, 174, 147, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(61, 87, 136, 122, D3DXVECTOR3(-2, 0, 0)));
	temp.push_back(MyRECT(0, 0, 92, 58, D3DXVECTOR3(29, 1, 0)));
	temp.push_back(MyRECT(59, 0, 86, 118, D3DXVECTOR3(26, 1, 0)));
	temp.push_back(MyRECT(0, 93, 170, 60, D3DXVECTOR3(20, 1, 0)));
	temp.push_back(MyRECT(119, 45, 86, 179, D3DXVECTOR3(1, 1, 0)));
	this->mState.push_back(new ObjectStateWithLoop(temp, 13, L"Object\\Enemy\\Enemy1\\Attack.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();


	this->mState.at(0)->SetPosition(this->mPosition);
	this->mState.at(1)->SetPosition(this->mPosition);
}

FireGround::~FireGround()
{
}

void FireGround::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);

	switch (mCurrentState)
	{
	case FireGroundState::FireGroundState_Fire:
		{
			if (this->mState.at(mCurrentState)->isDone() && !mOnFire)
				mCurrentState = FireGroundState::FireGroundState_Normal;
		}

		break;
	}
}

void FireGround::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

void FireGround::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::ALADDIN:
		if (collisionWith == CollisionWith::InteractBoundingBox)
		{
			if (AABBresult)
				mOnFire = true;
			else
				mOnFire = false;

			switch (mCurrentState)
			{
			case FireGroundState::FireGroundState_Normal:
				if (AABBresult == true)
				{
					//this->mState.at(FireGroundState::FireGroundState_Fire)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = FireGroundState::FireGroundState_Fire;
				}
			}
			break;
			
		}
	}
}

