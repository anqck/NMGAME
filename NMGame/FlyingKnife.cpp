#include "FlyingKnife.h"

FlyingKnife::FlyingKnife(D3DXVECTOR3 pos, Direction dir)
{
	mAcceleration = D3DXVECTOR2(0, 0);
	mCollisioned = false;

	this->mCanBeAttack = true;
	this->mCanAttack = true;
	this->mCanBeHitByFlyingObject = true;

	this->mID = EObjectID::THROWINGKNIFE;

	this->mPosition = pos;
	this->mTime = 0;
	this->mDone = 0;
	this->mCurrentState = FlyingKnifeState::FlyingKnifeState_Normal;

	this->mInteractBoundingBox = MyRECT(0, 0, 0, 0);
	this->mBoundingBox = MyRECT(0, 0, 0, 0);


	this->mDir = dir;

	mWidth = 30;
	mHeight = 30;

	vector<MyRECT> temp;

	temp.push_back(MyRECT(0, 0, 27, 27));
	temp.push_back(MyRECT(21, 28, 53, 44));
	temp.push_back(MyRECT(0, 70, 83, 22));
	temp.push_back(MyRECT(27, 54, 65, 52));
	temp.push_back(MyRECT(0, 56, 69, 26));
	temp.push_back(MyRECT(28, 0, 26, 45));
	temp.push_back(MyRECT(0, 28, 55, 20));
	temp.push_back(MyRECT(46, 0, 22, 59));
	this->mState.push_back(new ObjectStateWithLoop(temp, 18, L"Object\\Enemy\\Enemy3\\FlyingKnife.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	this->mState.at(0)->SetPosition(pos);
	temp.clear();

	temp.push_back(MyRECT(21, 0, 14, 34));
	temp.push_back(MyRECT(0, 0, 21, 20));
	temp.push_back(MyRECT(0, 43, 58, 21));
	temp.push_back(MyRECT(0, 22, 42, 20));

	this->mState.push_back(new ObjectState(temp, 15, L"Object\\Enemy\\Enemy3\\FlyingKnifeExplosion.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	//this->mState->SetPosition(pos);
	temp.clear();

	//this->mVelocity = D3DXVECTOR2(((mDir == Direction::Right) ? (1.0f) : (-1.0f)) * 1, 0.1);
	
}

FlyingKnife::FlyingKnife(D3DXVECTOR3 pos, Direction dir, D3DXVECTOR2 defaultVelocity, D3DXVECTOR2 acceleration) :FlyingKnife(pos, dir)
{ 
	this->mVelocity = defaultVelocity; 
	mState.at(mCurrentState)->SetVelocity(this->mVelocity);
	mAcceleration = acceleration;
}


FlyingKnife::~FlyingKnife()
{
}

void FlyingKnife::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	this->mState.at(mCurrentState)->SetFlipVertical(((mDir == Direction::Right) ? (false) : (true)));

	switch (mCurrentState)
	{
	case FlyingKnifeState::FlyingKnifeState_Normal:
		if (!mCollisioned)
		{
			this->mState.at(mCurrentState)->SetVelocity(this->mVelocity.x, this->mState.at(mCurrentState)->GetVelocity().y + this->mAcceleration.y);
			//this->mVelocity = this->mState.at(mCurrentState)->GetVelocity();
		}
		else
		{
			this->mState.at(mCurrentState)->SetVelocity(0, 0);
			mCurrentState = FlyingKnifeState::FlyingKnifeState_Explosion;
			this->mState.at(mCurrentState)->SetPosition(this->mPosition);
		}
		break;
	case FlyingKnifeState::FlyingKnifeState_Explosion:
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

void FlyingKnife::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

ObjectState * FlyingKnife::GetCurrentState()
{
	return this->mState.at(mCurrentState);
}

FlyingKnifeState FlyingKnife::GetCurrenStateID()
{
	return this->mCurrentState;
}

bool FlyingKnife::isDone()
{
	return mDone;
}

void FlyingKnife::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::GROUND:
	case EObjectID::WALL:
	case EObjectID::STAIR:
	case EObjectID::ENEMY3:
	case EObjectID::ENEMY4:
		this->mState.at(mCurrentState)->SetVelocity(this->mState.at(mCurrentState)->GetVelocity().x * collision.EntryTime, this->mState.at(mCurrentState)->GetVelocity().y * collision.EntryTime);
		mCollisioned = true;
		break;

	case EObjectID::THROWINGAPPLE:

		if (this->mCurrentState == FlyingKnifeState::FlyingKnifeState_Normal)
		{
			this->mState.at(FlyingKnifeState::FlyingKnifeState_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = FlyingKnifeState::FlyingKnifeState_Explosion;
		}
		break;

	case EObjectID::ALADDIN:
		if (this->mCurrentState == FlyingKnifeState::FlyingKnifeState_Normal)
		{
			this->mDone = true;

		}
		break;

	}
	
}

void FlyingKnife::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
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
		if (this->mCurrentState == FlyingKnifeState::FlyingKnifeState_Normal)
		{
			this->mVelocity.x = -this->mState.at(mCurrentState)->GetVelocity().x;
			this->mState.at(mCurrentState)->SetVelocity(  D3DXVECTOR2(this->mVelocity.x, this->mVelocity.y + 0.1));
		}
		break;
	
	}
}
