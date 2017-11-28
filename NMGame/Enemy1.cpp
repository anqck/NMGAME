#include "Enemy1.h"

Enemy1::Enemy1() : Enemy::Enemy()
{
	this->mCanBeAttack = true;
	this->mCanBeHitByFlyingObject = true;
	this->mInteractWithInteractBB = true;
	this->mCanBeHitByFlyingObject = true;
	this->mCanAttack = true;

	mLastAladdinPosInInteractBox = D3DXVECTOR3(0, 0, 0);

	this->mID = EObjectID::ENEMY1;

	this->mDone = false;

	this->mCurrentState = Eneymy1State::Eneymy1State_DoNothing;

	mWidth = 40;
	mHeight = 140;

	this->mHP = 2;
}

Enemy1::Enemy1(MyRECT bb, D3DXVECTOR3 pos) : Enemy1()
{
	this->mBoundingBox = MyRECT(0, 0, 0, 0);
	this->mInteractBoundingBox = bb;

	this->mCurrentState = Eneymy1State::Eneymy1State_DoNothing;

	this->mPosition = pos;


	vector<MyRECT> temp;

	//DoNothing
	temp.push_back(MyRECT(0, 0, 44, 58));
	this->mState.push_back(new ObjectState(temp, 20, L"Object\\Enemy\\Enemy1\\DoNothing.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();

	//Attack
	temp.push_back(MyRECT(119, 0, 44, 177));
	temp.push_back(MyRECT(0, 171, 221, 71, D3DXVECTOR3(-7,0,0)));
	temp.push_back(MyRECT(72, 137, 174, 147, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(61, 87, 136, 122, D3DXVECTOR3(-2, 0, 0)));
	temp.push_back(MyRECT(0, 0, 92, 58, D3DXVECTOR3(29, 1, 0)));
	temp.push_back(MyRECT(59, 0, 86, 118, D3DXVECTOR3(26, 1, 0)));
	temp.push_back(MyRECT(0, 93, 170, 60, D3DXVECTOR3(20, 1, 0)));
	temp.push_back(MyRECT(119, 45, 86, 179, D3DXVECTOR3(1, 1, 0)));
	this->mState.push_back(new ObjectStateWithLoop(temp, 13, L"Object\\Enemy\\Enemy1\\Attack.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();


	//Run
	temp.push_back(MyRECT(0, 98, 143, 67));
	temp.push_back(MyRECT(0, 144, 189, 66));
	temp.push_back(MyRECT(0, 51, 97, 65));
	temp.push_back(MyRECT(68, 0, 45, 133));
	temp.push_back(MyRECT(68, 90, 127, 134));
	temp.push_back(MyRECT(68, 46, 89, 135));
	temp.push_back(MyRECT(0, 0, 50, 67));
	temp.push_back(MyRECT(68, 128, 164, 133));
	this->mState.push_back(new ObjectStateWithLoop(temp, 13, L"Object\\Enemy\\Enemy1\\Run.png", D3DXVECTOR2(0.3f, 0), CenterArchor::CenterBottom));

	temp.clear();

	//Damaged
	temp.push_back(MyRECT(63, 45, 85, 111));
	temp.push_back(MyRECT(0, 180, 219, 73, D3DXVECTOR3(-2,0,0)));
	temp.push_back(MyRECT(0, 138, 179, 68, D3DXVECTOR3(0, 8, 0)));
	temp.push_back(MyRECT(0, 48, 94, 62, D3DXVECTOR3(4, 8, 0)));	
	temp.push_back(MyRECT(0, 95, 137, 71, D3DXVECTOR3(2, 0, 0)));
	temp.push_back(MyRECT(0, 0, 47, 49));
	temp.push_back(MyRECT(72, 86, 126, 120, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(50, 0, 44, 108, D3DXVECTOR3(1, 0, 0)));
	this->mState.push_back(new ObjectStateWithLoop(temp, 13, L"Object\\Enemy\\Enemy1\\Damaged.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();

	//Explosion
	temp.push_back(MyRECT(0, 0, 88, 55, D3DXVECTOR3(0,20,0)));
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

	this->mState.at(mCurrentState)->SetPosition(pos);
}

Enemy1::~Enemy1()
{
}

void Enemy1::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	if (mLastAladdinPosInInteractBox.x <= this->mPosition.x)
		this->mDir = Direction::Left;
	else
		this->mDir = Direction::Right;

	this->mState.at(mCurrentState)->SetFlipVertical(((mDir == Direction::Right) ? (false) : (true)));

	switch (mCurrentState)
	{
	case Eneymy1State::Eneymy1State_Run:
		/*if (this->mPosition.x != mLastAladdinPosInInteractBox.x)
		{
			this->m
		}*/
		
		break;
	}
}

void Enemy1::Render(float DeltaTime)
{
	//if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_3))
		//GraphicsHelper::GetInstance()->DrawBoundingBox(this->GetAttackBoundingBox(), D3DCOLOR_XRGB(255, 255, 0));

	GameVisibleEntity::Render(DeltaTime);
	//GraphicsHelper::GetInstance()->DrawBoundingBox(this->GetAttackRange(), D3DCOLOR_XRGB(255,0,255));

	this->mState.at(mCurrentState)->Render();
}

void Enemy1::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::THROWINGAPPLE:
		if (this->mHP == 2)
		{
			this->mHP--;

			this->mState.at(Eneymy1State::Eneymy1State_Damage)->resetFrame();
			this->mState.at(Eneymy1State::Eneymy1State_Damage)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Eneymy1State::Eneymy1State_Damage;
		}
		else if (this->mHP == 1)
		{
			this->mState.at(Eneymy1State::Eneymy1State_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Eneymy1State::Eneymy1State_Explosion;

		}
		
	}
}

void Enemy1::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::ALADDIN:
		if (AABBresult == true)
			mLastAladdinPosInInteractBox = obj->GetCurrentState()->GetPosition();
		if (collisionWith == CollisionWith::InteractBoundingBox)
		{
			switch (mCurrentState)
			{
			case Eneymy1State::Eneymy1State_DoNothing:
				if (AABBresult == true)
				{
					this->mState.at(Eneymy1State::Eneymy1State_Run)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Eneymy1State::Eneymy1State_Run;
				}

				if (this->GetAttackRange().Intersects(obj->GetBoundingBox()))
				{
					this->mState.at(Eneymy1State::Eneymy1State_Attack)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Eneymy1State::Eneymy1State_Attack;
					this->mState.at(Eneymy1State::Eneymy1State_Attack)->resetFrame();
				}


				break;
			case Eneymy1State::Eneymy1State_Run:


				if (this->GetAttackRange().Intersects(obj->GetBoundingBox()))
				{
					this->mState.at(Eneymy1State::Eneymy1State_Attack)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Eneymy1State::Eneymy1State_Attack;
					this->mState.at(Eneymy1State::Eneymy1State_Attack)->resetFrame();
				}
				else if (this->GetBoundingBox().left <= this->mInteractBoundingBox.left + 10 || this->GetBoundingBox().right >= this->mInteractBoundingBox.right - 10)
				{
					this->mState.at(Eneymy1State::Eneymy1State_DoNothing)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Eneymy1State::Eneymy1State_DoNothing;
				}


				break;
			case Eneymy1State::Eneymy1State_Attack:
				if (!this->GetAttackRange().Intersects(obj->GetBoundingBox()) && this->mState.at(mCurrentState)->isDone())
				{
					this->mState.at(Eneymy1State::Eneymy1State_Run)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Eneymy1State::Eneymy1State_Run;
					//this->mState.at(mCurrentState)->SetVelocity(0, 0);
				}
			case Eneymy1State::Eneymy1State_Damage:
				if (this->mState.at(mCurrentState)->isDone())
				{
					this->mState.at(Eneymy1State::Eneymy1State_DoNothing)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Eneymy1State::Eneymy1State_DoNothing;
				}
				break;
			case Eneymy1State::Eneymy1State_Explosion:
				if (this->mState.at(mCurrentState)->isDone())
				{

					mDone = true;
				}
				break;
			}
		}
		else if ((collisionWith == CollisionWith::SwordBoundingBox))
		{
			if (!AABBresult)
				return;

			switch (mCurrentState)
			{
			case Eneymy1State::Eneymy1State_Damage:
				break;
			default:
				if (this->mHP == 2)
				{
					this->mHP--;

					this->mState.at(Eneymy1State::Eneymy1State_Damage)->resetFrame();
					this->mState.at(Eneymy1State::Eneymy1State_Damage)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Eneymy1State::Eneymy1State_Damage;
				}
				else if (this->mHP == 1)
				{
					this->mState.at(Eneymy1State::Eneymy1State_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Eneymy1State::Eneymy1State_Explosion;

				}
			}
			
		}
	}
}

MyRECT Enemy1::GetAttackRange()
{
	//if(this->mDir)
	if(this->mDir == Right)
		return MyRECT(this->GetBoundingBox().top, this->GetBoundingBox().right - 60, this->GetBoundingBox().right + 85, this->GetBoundingBox().bottom);
	else
		return MyRECT(this->GetBoundingBox().top, this->GetBoundingBox().left - 85, this->GetBoundingBox().left +60 , this->GetBoundingBox().bottom);
}

MyRECT Enemy1::GetAttackBoundingBox()
{
	switch (mCurrentState)
	{
	case Eneymy1State::Eneymy1State_Attack:

		switch (mState.at(mCurrentState)->GetCurrentIdx())
		{
		case 4:
			return MyRECT(this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().top + 20, this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().left + ((mDir == Direction::Right) ? (65) : (6)), this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().right + ((mDir == Direction::Right) ? (-6) : (-65)), this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().bottom + 20);
		default:
			return MyRECT(0, 0, 0, 0);
		}



	default:
		return MyRECT(0, 0, 0, 0);

	}
}
