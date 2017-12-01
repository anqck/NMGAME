#include "ThrowPot.h"

ThrowPot::ThrowPot(D3DXVECTOR3 pos)
{
	mCollisioned = false;

	this->mID = EObjectID::THROWINGPOT;

	this->mPosition = pos;

	this->mDone = false;

	this->mCurrentState = ThrowPotState::ThrowPot_Normal;

	this->mCanBeHitByFlyingObject = true;
	this->mCanBeAttack = true;
	this->mCanAttack = true;

	this->mBoundingBox = MyRECT(0, 0, 0, 0);
	this->mInteractBoundingBox = MyRECT(0, 0, 0, 0);


	mWidth = 55;
	mHeight = 55;

	vector<MyRECT> temp;

	//Normal
	temp.push_back(MyRECT(16, 0, 28, 37));
	temp.push_back(MyRECT(39, 28, 52, 63));
	temp.push_back(MyRECT(16, 29, 55, 38));
	temp.push_back(MyRECT(38, 0, 27, 54));
	temp.push_back(MyRECT(0, 56, 80, 24));
	temp.push_back(MyRECT(25, 56, 77, 50));
	temp.push_back(MyRECT(0, 0, 37, 15));


	this->mState.push_back(new ObjectStateWithLoop(temp, 20, L"Object\\ThrowPot\\Pot.png", D3DXVECTOR2(0.08, - 0.45), CenterArchor::CenterBottom));

	temp.clear();


	temp.push_back(MyRECT(0, 0, 88, 55));
	temp.push_back(MyRECT(0, 89, 171, 51));
	temp.push_back(MyRECT(56, 0, 86, 108));
	temp.push_back(MyRECT(52, 89, 167, 101));
	temp.push_back(MyRECT(52, 168, 242, 100));
	temp.push_back(MyRECT(0, 172, 214, 37));
	temp.push_back(MyRECT(101, 168, 208, 137));
	temp.push_back(MyRECT(102, 87, 126, 136));
	temp.push_back(MyRECT(102, 127, 164, 136));
	temp.push_back(MyRECT(109, 0, 30, 137));
	temp.push_back(MyRECT(109, 31, 51, 124));
	temp.push_back(MyRECT(125, 31, 36, 128));


	this->mState.push_back(new ObjectState(temp, 18, L"Object\\ThrowPot\\Explosion.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	temp.push_back(MyRECT(105, 0, 68, 127));
	temp.push_back(MyRECT(69, 97, 173, 95));
	temp.push_back(MyRECT(34, 103, 189, 68));
	temp.push_back(MyRECT(0, 103, 199, 33));
	temp.push_back(MyRECT(68, 0, 96, 104));
	temp.push_back(MyRECT(0, 0, 102, 36));
	temp.push_back(MyRECT(37, 0, 101, 67));
	this->mState.push_back(new ObjectState(temp, 18, L"Object\\ThrowPot\\GroundExplosion.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	this->mState.at(mCurrentState)->SetPosition(pos);
}

ThrowPot::~ThrowPot()
{
}

void ThrowPot::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	switch (mCurrentState)
	{
	case ThrowPotState::ThrowPot_Normal:
		if (mCollisioned)
		
		{
		
			mCurrentState = ThrowPotState::ThrowPot_GroundExplosion;
			this->mState.at(mCurrentState)->SetPosition(this->mPosition);
		}
	

		break;

	case ThrowPotState::ThrowPot_GroundExplosion:
	case ThrowPotState::ThrowPot_Explosion:
	{
		this->mPosition = this->mState.at(mCurrentState)->GetPosition();

		if (this->mState.at(mCurrentState)->isDone())
		{
			mDone = true;
		}

		break;
	}

	}
}

void ThrowPot::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

ObjectState * ThrowPot::GetCurrentState()
{
	return this->mState.at(mCurrentState);
}

ThrowPotState ThrowPot::GetCurrentStateID()
{
	return this->mCurrentState;
}

void ThrowPot::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::STAIR:
	case EObjectID::GROUND:
	case EObjectID::CAMEL:
	case EObjectID::THROWPOTENEMY:
		//this->mVelocity = D3DXVECTOR2(0, 0);
		this->mState.at(mCurrentState)->SetVelocity(this->mState.at(mCurrentState)->GetVelocity().x * collision.EntryTime, this->mState.at(mCurrentState)->GetVelocity().y * collision.EntryTime);
		//this->mCurrentState = ThrowingAppleState::Explosion;

		mCollisioned = true;
		//this->mState.at(mCurrentState)->SetPosition(this->mState.at(0)->GetPosition().x + this->mState.at(0)->GetVelocity().x*collision.EntryTime, this->mState.at(0)->GetPosition().y + this->mState.at(0)->GetVelocity().y * collision.EntryTime);
		break;
	case EObjectID::THROWINGAPPLE:

		if (this->mCurrentState == ThrowPotState::ThrowPot_Normal)
		{
			this->mState.at(ThrowPotState::ThrowPot_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = ThrowPotState::ThrowPot_Explosion;
		}
		break;
	
	}

}

void ThrowPot::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
	if (AABBresult == false)
		return;

	
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::ALADDIN:
	/*	AladdinCharacter * aladdin = (AladdinCharacter*)obj;
		if (aladdin->getCurrentState() == AState::Attack1)
		{
			this->mState.at(ThrowPotState::ThrowPot_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = ThrowPotState::ThrowPot_Explosion;
			break;
		}*/
		if (this->mCurrentState == ThrowPotState::ThrowPot_Normal)
		{
			this->mState.at(ThrowPotState::ThrowPot_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = ThrowPotState::ThrowPot_Explosion;
		}
		break;
	}
}

bool ThrowPot::isDone()
{
	return mDone;
}
