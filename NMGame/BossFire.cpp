#include "BossFire.h"

BossFire::BossFire()
{
	this->mID = EObjectID::BOSS_FIRE;
	this->mCanAttack = true;
	//this->mC

	mCurrentState = BossFireState::BossFireState_Fire;

	this->mWidth = 40;
	this->mHeight = 100;

	mVelocity = D3DXVECTOR2(0.35, -0.15);
}

BossFire::BossFire(D3DXVECTOR3 pos, Direction Dir) : BossFire()
{
	this->mPosition = pos;
	this->mDir = Dir;

	vector<MyRECT> temp;
	//Nothing
	temp.push_back(MyRECT(49, 91, 166, 99));
	temp.push_back(MyRECT(0, 100, 179, 48,D3DXVECTOR3(2,0,0)));
	temp.push_back(MyRECT(0, 0, 99, 42, D3DXVECTOR3(5, 0, 0)));
	temp.push_back(MyRECT(43, 0, 90, 84, D3DXVECTOR3(6, 0, 0)));
	temp.push_back(MyRECT(85, 0, 77, 116, D3DXVECTOR3(2, 0, 0)));
	temp.push_back(MyRECT(0, 180, 253, 31));
	temp.push_back(MyRECT(84, 167, 231, 127, D3DXVECTOR3(-6, 1, 0)));
	temp.push_back(MyRECT(32, 180, 244, 83, D3DXVECTOR3(-6, 0, 0)));

	this->mState.push_back(new ObjectStateWithLoop(temp, 10, L"Object\\Boss\\BossFire.png", D3DXVECTOR2(mVelocity.x, mVelocity.y), CenterArchor::CenterBottom));
	temp.clear();



	this->mState.at(0)->SetPosition(pos);
	
}

BossFire::~BossFire()
{
}

void BossFire::Update(float DeltaTime)
{

	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	this->mState.at(mCurrentState)->SetFlipVertical((this->mDir== Direction::Right) ? (false) : (true));
}

void BossFire::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);


	this->mState.at(mCurrentState)->Render();
}

MyRECT BossFire::GetAttackBoundingBox()
{
	return this->GetBoundingBox();
	/*switch (mCurrentState)
	{
	case BossFireState::BossFireState_Fire:

		switch (mState.at(mCurrentState)->GetCurrentIdx())
		{
		case 4:
			return MyRECT(this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().top + 20, this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().left, this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().right, this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().bottom + 40);
		default:
			return MyRECT(this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().top + 20, this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().left, this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().right, this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().bottom + 40);

		}



	default:
		return MyRECT(0, 0, 0, 0);

	}*/
}

void BossFire::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)

{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::GROUND:
		this->mState.at(mCurrentState)->SetVelocity(this->mState.at(mCurrentState)->GetVelocity().x , this->mState.at(mCurrentState)->GetVelocity().y * collision.EntryTime);
		break;
	case EObjectID::WALL:

		//this->mState.at(mCurrentState)->SetVelocity(this->mState.at(mCurrentState)->GetVelocity().x * collision.EntryTime, this->mState.at(mCurrentState)->GetVelocity().y * collision.EntryTime);
		this->mDone = true;
		break;
	}
}

bool BossFire::isDone()
{
	return mDone;
}
