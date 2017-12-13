#include "Enemy5.h"
#include "Lamp.h"
#include "SoundHelper.h"
Enemy5::Enemy5()
{
	this->mCanBeAttack = true;
	this->mCanBeHitByFlyingObject = true;
	this->mInteractWithInteractBB = true;
	this->mCanBeHitByFlyingObject = true;
	this->mCanAttack = true;

	mLastAladdinPosInInteractBox = D3DXVECTOR3(0, 0, 0);

	this->mID = EObjectID::ENEMY5;

	this->mDone = false;

	this->mCurrentState = Enemy5State::Enemy5State_DoNothing;

	mWidth = 10;
	mHeight = 100;

	this->mHP = 2;
}

Enemy5::Enemy5(MyRECT bb, D3DXVECTOR3 pos) : Enemy5()
{
	this->mBoundingBox = MyRECT(0, 0, 0, 0);
	this->mInteractBoundingBox = bb;

	this->mPosition = this->mDefaultPosition =  pos;


	vector<MyRECT> temp;

	//DoNothing
	temp.push_back(MyRECT(0, 0, 36, 39));

	this->mState.push_back(new ObjectState(temp, 14, L"Object\\Enemy\\\\Enemy5\\DoNothing.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();

	//Wait
	temp.push_back(MyRECT(0, 0, 39, 32, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(0, 118, 150, 64, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(47, 76, 110, 96, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(0, 80, 117, 46,D3DXVECTOR3(-2,0,0)));
	temp.push_back(MyRECT(0, 80, 117, 46, D3DXVECTOR3(-2, 0, 0)));
	temp.push_back(MyRECT(0, 80, 117, 46, D3DXVECTOR3(-2, 0, 0)));
	temp.push_back(MyRECT(33, 0, 37, 79, D3DXVECTOR3(-2, 0, 0)));
	temp.push_back(MyRECT(33, 38, 75, 79, D3DXVECTOR3(-2, 0, 0)));
	temp.push_back(MyRECT(0, 40, 79, 32, D3DXVECTOR3(-2, 0, 0)));
	this->mState.push_back(new ObjectState(temp, 11, L"Object\\Enemy\\\\Enemy5\\Wait.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();

	//Run
	temp.push_back(MyRECT(0, 56, 109, 46));
	temp.push_back(MyRECT(47, 0, 45, 93));
	temp.push_back(MyRECT(0, 154, 197, 51));
	temp.push_back(MyRECT(0, 198, 236, 51));
	temp.push_back(MyRECT(52, 169, 207, 103));
	temp.push_back(MyRECT(94, 0, 38, 143));
	temp.push_back(MyRECT(0, 0, 55, 46));
	temp.push_back(MyRECT(47, 46, 90, 95));
	temp.push_back(MyRECT(0, 110, 153, 52));
	temp.push_back(MyRECT(53, 130, 168, 106));
	temp.push_back(MyRECT(53, 91, 129, 106));
	temp.push_back(MyRECT(52, 208, 246, 102));

	this->mState.push_back(new ObjectStateWithLoop(temp, 13, L"Object\\Enemy\\\\Enemy5\\Run.png", D3DXVECTOR2(0.13f, 0), CenterArchor::CenterBottom));

	temp.clear();

	//Attack
	temp.push_back(MyRECT(42, 50, 89, 74,D3DXVECTOR3(-2,0,0)));
	temp.push_back(MyRECT(0, 150, 186, 39));
	temp.push_back(MyRECT(75, 50, 88, 114, D3DXVECTOR3(1, 0, 0)));
	temp.push_back(MyRECT(75, 89, 127, 114, D3DXVECTOR3(1, 0, 0)));
	temp.push_back(MyRECT(82, 0, 48, 124, D3DXVECTOR3(6, 0, 0)));
	temp.push_back(MyRECT(0, 62, 112, 41, D3DXVECTOR3(7, 0, 0)));
	temp.push_back(MyRECT(0, 0, 61, 40, D3DXVECTOR3(12, 0, 0)));
	temp.push_back(MyRECT(41, 0, 49, 81, D3DXVECTOR3(6, 0, 0)));
	temp.push_back(MyRECT(0, 113, 149, 40));
	temp.push_back(MyRECT(0, 187, 223, 39));
	this->mState.push_back(new ObjectState(temp, 14, L"Object\\Enemy\\\\Enemy5\\Attack.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();

	//Explosion
	temp.push_back(MyRECT(0, 0, 88, 55, D3DXVECTOR3(0, 20, 0)));
	temp.push_back(MyRECT(0, 89, 171, 51, D3DXVECTOR3(0, 20, 0)));
	temp.push_back(MyRECT(56, 0, 86, 108, D3DXVECTOR3(0, 20, 0)));
	temp.push_back(MyRECT(52, 89, 167, 101, D3DXVECTOR3(0, 20, 0)));
	temp.push_back(MyRECT(52, 168, 242, 100, D3DXVECTOR3(0, 20, 0)));
	temp.push_back(MyRECT(0, 172, 214, 37, D3DXVECTOR3(0, 20, 0)));
	temp.push_back(MyRECT(101, 168, 208, 137, D3DXVECTOR3(0, 20, 0)));
	temp.push_back(MyRECT(102, 87, 126, 136, D3DXVECTOR3(0, 20, 0)));
	temp.push_back(MyRECT(102, 127, 164, 136, D3DXVECTOR3(0, 20, 0)));
	temp.push_back(MyRECT(109, 0, 30, 137, D3DXVECTOR3(0, 20, 0)));
	temp.push_back(MyRECT(109, 31, 51, 124, D3DXVECTOR3(0, 20, 0)));
	temp.push_back(MyRECT(125, 31, 36, 128, D3DXVECTOR3(0, 20, 0)));
	this->mState.push_back(new ObjectState(temp, 13, L"Object\\Enemy\\Enemy1\\Explosion.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();

	this->mState.at(mCurrentState)->SetPosition(mPosition);
}

Enemy5::~Enemy5()
{
}

void Enemy5::ResetDefault()
{
	mLastAladdinPosInInteractBox = D3DXVECTOR3(0, 0, 0);

	this->mDone = false;

	this->mCurrentState = Enemy5State::Enemy5State_DoNothing;

	mWidth = 10;
	mHeight = 100;

	this->mHP = 2;

	this->mPosition = mDefaultPosition;

	this->mState.at(mCurrentState)->SetPosition(mDefaultPosition);

	this->mState.at(Enemy5State::Enemy5State_Explosion)->resetFrame();
}

void Enemy5::Update(float DeltaTime)
{
	PlaySoundOnState();

	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	if (mLastAladdinPosInInteractBox.x != 0)
	{
		if (mLastAladdinPosInInteractBox.x <= this->mPosition.x)
			this->mDir = Direction::Left;
		else
			this->mDir = Direction::Right;
	}
	this->mState.at(mCurrentState)->SetFlipVertical(((mDir == Direction::Right) ? (false) : (true)));

	switch (mCurrentState)
	{
	case Enemy5State::Enemy5State_DoNothing:
		if ((this->mLastAladdinPosInInteractBox.x <= this->mInteractBoundingBox.left && this->mDir == Direction::Left) || (this->mLastAladdinPosInInteractBox.x >= this->mInteractBoundingBox.right && this->mDir == Direction::Right))
		{
			int randNumber = rand() % 100; //1%
			if (randNumber == 1)
			{
				this->mState.at(Enemy5State::Enemy5State_Wait)->resetFrame();
				this->mState.at(Enemy5State::Enemy5State_Wait)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
				mCurrentState = Enemy5State::Enemy5State_Wait;
			}
		}
		else
		{
			int randNumber = rand() % 100; //1%
			if (randNumber == 0)
			{
				this->mState.at(Enemy5State::Enemy5State_Wait)->resetFrame();
				this->mState.at(Enemy5State::Enemy5State_Wait)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
				mCurrentState = Enemy5State::Enemy5State_Wait;
			}
		}
		break;
	case Enemy5State::Enemy5State_Wait:
		if (this->mState.at(mCurrentState)->isDone())
		{
			this->mState.at(Enemy5State::Enemy5State_DoNothing)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy5State::Enemy5State_DoNothing;
		}
		break;
	case Enemy5State::Enemy5State_Run:
		if (this->GetBoundingBox().left <= this->mInteractBoundingBox.left + 10 || this->GetBoundingBox().right >= this->mInteractBoundingBox.right - 10)
		{
			//this->mState.at(Enemy4State::Enemy4State_Attack)->resetFrame();
			this->mState.at(Enemy5State::Enemy5State_DoNothing)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy5State::Enemy5State_DoNothing;
		}



		break;
	case Enemy5State::Enemy5State_Attack:
		if (this->mState.at(mCurrentState)->isDone())
		{
			this->mState.at(Enemy5State::Enemy5State_DoNothing)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy5State::Enemy5State_DoNothing;
		}
		break;
	case Enemy5State::Enemy5State_Explosion:
		if (this->mState.at(mCurrentState)->isDone())
		{

			mDone = true;
		}
		break;
	}
}

void Enemy5::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	//GraphicsHelper::GetInstance()->DrawBoundingBox(this->GetAttackBoundingBox(), D3DCOLOR_XRGB(255, 0, 255));
	this->mState.at(mCurrentState)->Render();
}

void Enemy5::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
	switch (obj->GetID())
	{
	case EObjectID::LAMP:
		if (((Lamp*)obj)->GetCollisioned() && this->GetBoundingBox().Intersects(obj->GetInteractBoundingBox()))
		{
			this->mState.at(Enemy5State::Enemy5State_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy5State::Enemy5State_Explosion;
			this->mWidth = 0;
			this->mHeight = 0;
		}
		break;
	case EObjectID::ALADDIN:

		if (AABBresult == true)
			mLastAladdinPosInInteractBox = obj->GetCurrentState()->GetPosition();

		if (collisionWith == CollisionWith::InteractBoundingBox)
		{
			switch (mCurrentState)
			{
			case Enemy5State::Enemy5State_Run:
				if (this->GetAttackRange().Intersects(obj->GetBoundingBox()))
				{
					this->mState.at(Enemy5State::Enemy5State_Attack)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Enemy5State::Enemy5State_Attack;
					this->mState.at(Enemy5State::Enemy5State_Attack)->resetFrame();
				}
				else if (abs(obj->GetCurrentState()->GetPosition().x - this->mPosition.x) > 320 || obj->GetCurrentState()->GetPosition().y < this->GetInteractBoundingBox().left || obj->GetCurrentState()->GetPosition().x > this->GetInteractBoundingBox().right)
				{
					this->mState.at(Enemy5State::Enemy5State_DoNothing)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Enemy5State::Enemy5State_DoNothing;
				}
				break;
			case Enemy5State::Enemy5State_DoNothing:
				if (this->GetAttackRange().Intersects(obj->GetBoundingBox()))
				{
					this->mState.at(Enemy5State::Enemy5State_Attack)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Enemy5State::Enemy5State_Attack;
					this->mState.at(Enemy5State::Enemy5State_Attack)->resetFrame();
				}
				else if (abs(obj->GetCurrentState()->GetPosition().x - this->mPosition.x) <= 320 &&  this->GetBoundingBox().left >= mInteractBoundingBox.left - 10 &&  this->GetBoundingBox().right <= mInteractBoundingBox.right + 10 && this->mLastAladdinPosInInteractBox.x >= this->GetInteractBoundingBox().left && this->mLastAladdinPosInInteractBox.x <= this->GetInteractBoundingBox().right)
				{
					this->mState.at(Enemy5State::Enemy5State_Run)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Enemy5State::Enemy5State_Run;
				}
				
				break;

				break;
			}

		}
		else if ((collisionWith == CollisionWith::SwordBoundingBox))
		{
			if (!AABBresult || this->mCurrentState == Enemy5State::Enemy5State_DoNothing)
				return;

			switch (mCurrentState)
			{
			default:

				this->mState.at(Enemy5State::Enemy5State_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
				mCurrentState = Enemy5State::Enemy5State_Explosion;
				this->mWidth = 0;
				this->mHeight = 0;
			}
		}
		break;
	}
}

void Enemy5::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::THROWINGKNIFE:
	case EObjectID::THROWINGAPPLE:
		if (this->mCurrentState == Enemy5State::Enemy5State_DoNothing)
			return;

		if (this->mHP >= 2)
		{
			
			this->mHP--;

		}
		else if (this->mHP == 1)
		{
			this->mState.at(Enemy5State::Enemy5State_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy5State::Enemy5State_Explosion;

			this->mWidth = 0;
			this->mHeight = 0;

		}
		break;
	}
}

MyRECT Enemy5::GetAttackRange()
{
	if (this->mDir == Right)
		return MyRECT(this->GetBoundingBox().top, this->GetBoundingBox().right - 60, this->GetBoundingBox().right + 75, this->GetBoundingBox().bottom);
	else
		return MyRECT(this->GetBoundingBox().top, this->GetBoundingBox().left - 75, this->GetBoundingBox().left + 60, this->GetBoundingBox().bottom);

}

MyRECT Enemy5::GetAttackBoundingBox()
{
	switch (mCurrentState)
	{
	case Enemy5State::Enemy5State_Attack:

		switch (mState.at(mCurrentState)->GetCurrentIdx())
		{
		case 2:
			return MyRECT(this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().top + 20, this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().left + ((mDir == Direction::Right) ? (45) : (-60)), this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().right + ((mDir == Direction::Right) ? (60) : (-45)), this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().bottom + 20);
		default:
			return MyRECT(0, 0, 0, 0);
		}

		break;
	}
}

D3DXVECTOR2 Enemy5::GetVelocity()
{
	return D3DXVECTOR2();
}

bool Enemy5::isDone()
{
	return mDone;
}

void Enemy5::PlaySoundOnState()
{
	if (!mState.at(mCurrentState)->isNextFrame)
		return;

	switch (mCurrentState)
	{
	case Enemy5State::Enemy5State_Explosion:
		switch (mState.at(mCurrentState)->GetCurrentIdx())
		{
		case 1:
			SoundHelper::GetInstance()->Play("Explosion", false, 1);
			break;
		}
		break;
	}
}
