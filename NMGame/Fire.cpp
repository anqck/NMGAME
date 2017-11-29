#include "Fire.h"

Fire::Fire()
{
	this->mID = EObjectID::FIRE;
	this->mCanAttack = true;

	mCurrentState = FireState::FireGroundState_Fire;

	this->mWidth = 20;
	this->mHeight = 30;
}

Fire::Fire(D3DXVECTOR3 pos) : Fire()
{
	this->mPosition = pos;

	vector<MyRECT> temp;
	//Nothing
	temp.push_back(MyRECT(0, 0, 0, 0));
	this->mState.push_back(new ObjectState(temp, 20, L"Object\\StaticObject\\FireGround.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Fire
	temp.push_back(MyRECT(51, 48, 55, 70));
	temp.push_back(MyRECT(50, 79, 98, 77));
	temp.push_back(MyRECT(0, 81, 105, 47));
	temp.push_back(MyRECT(50, 56, 78, 103));
	temp.push_back(MyRECT(55, 0, 24, 102));
	temp.push_back(MyRECT(0, 28, 55, 50));
	temp.push_back(MyRECT(0, 0, 27, 54));
	temp.push_back(MyRECT(0, 56, 80, 49));
	//temp.push_back(MyRECT(51, 28, 47, 84));
	//temp.push_back(MyRECT(0, 106, 113, 19));

	this->mState.push_back(new ObjectStateWithLoop(temp, 9, L"Object\\StaticObject\\FireGround.png", D3DXVECTOR2(0, 0),2, CenterArchor::CenterBottom));
	temp.clear();

	//Done
	temp.push_back(MyRECT(0, 0, 27, 54));
	temp.push_back(MyRECT(0, 56, 80, 49));
	temp.push_back(MyRECT(51, 28, 47, 84));
	temp.push_back(MyRECT(0, 106, 113, 19));

	this->mState.push_back(new ObjectState(temp, 14, L"Object\\StaticObject\\FireGround.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	this->mState.at(1)->SetPosition(pos);
	this->mState.at(2)->SetPosition(pos);
}

Fire::~Fire()
{
}

void Fire::Update(float DeltaTime, D3DXVECTOR3 mNewAladdinpos, bool onFire)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);

	if(!onFire)
		this->mCurrentState = FireState::FireGroundState_Done;

	switch (mCurrentState)
	{
	case FireState::FireGroundState_Fire:
		if (mPosition.x + 70 < mNewAladdinpos.x || mPosition.x - 70 > mNewAladdinpos.x)
		{
			this->mState.at(FireState::FireGroundState_Done)->SetPosition(this->mState.at(FireState::FireGroundState_Fire)->GetPosition());
			this->mCurrentState = FireState::FireGroundState_Done;
		}
			
		else
		{
			this->mState.at(mCurrentState)->SetPosition(mNewAladdinpos);
			//if (mPosition.x + 70 >= mNewAladdinpos.x)
			//{
			//	
			//	//this->mState.at(2)->SetPosition(mNewAladdinpos);
			//}
			
		}
			
		break;

	}
}

void Fire::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);


	this->mState.at(mCurrentState)->Render();
}

MyRECT Fire::GetAttackBoundingBox()
{
	switch (mCurrentState)
	{
	case FireState::FireGroundState_Fire:

		switch (mState.at(mCurrentState)->GetCurrentIdx())
		{
		case 4:
			return MyRECT(this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().top + 20, this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().left , this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().right , this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().bottom + 40);
		default:
			return MyRECT(0, 0, 0, 0);
		}



	default:
		return MyRECT(0, 0, 0, 0);

	}
}

bool Fire::isDone()
{
	return ((this->mCurrentState == FireState::FireGroundState_Done)&&(this->mState.at(mCurrentState)->isDone()));
}
