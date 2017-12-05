#include "Enemy4.h"
#include "Lamp.h"
Enemy4::Enemy4()
{

	this->mCanBeAttack = true;
	this->mCanBeHitByFlyingObject = true;
	this->mInteractWithInteractBB = true;
	this->mCanBeHitByFlyingObject = true;
	this->mCanAttack = false;

	mLastAladdinPosInInteractBox = D3DXVECTOR3(0, 0, 0);

	this->mID = EObjectID::ENEMY4;

	this->mDone = false;

	this->mCurrentState = Enemy4State::Enemy4State_Wait;

	mWidth = 10;
	mHeight = 140;

	this->mHP = 2;
}

Enemy4::Enemy4(MyRECT bb, D3DXVECTOR3 pos) : Enemy4()
{
	this->mBoundingBox = MyRECT(0, 0, 0, 0);
	this->mInteractBoundingBox = bb;

	this->mPosition = this->mDefaultPosition = pos;


	vector<MyRECT> temp;

	//DoNothing
	temp.push_back(MyRECT(0, 0, 43, 50,D3DXVECTOR3(1,0,0)));

	this->mState.push_back(new ObjectState(temp, 14, L"Object\\Enemy\\\\Enemy4\\DoNothing.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();

	//Wait
	temp.push_back(MyRECT(0, 0, 54, 46));
	temp.push_back(MyRECT(0, 55, 107, 52,D3DXVECTOR3(3,0,0)));
	temp.push_back(MyRECT(53, 41, 81, 102, D3DXVECTOR3(8, 0, 0)));
	temp.push_back(MyRECT(45, 122, 159, 89, D3DXVECTOR3(6, 0, 0)));
	temp.push_back(MyRECT(0, 108, 147, 44, D3DXVECTOR3(4, 0, 0)));
	temp.push_back(MyRECT(47, 0, 40, 97, D3DXVECTOR3(2, 0, 0)));
	temp.push_back(MyRECT(53, 82, 121, 99, D3DXVECTOR3(1, 0, 0)));
	temp.push_back(MyRECT(0, 148, 186, 44, D3DXVECTOR3(3, 0, 0)));
	this->mState.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\Enemy\\Enemy4\\Wait.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();


	//Run
	temp.push_back(MyRECT(0, 44, 83, 55));
	temp.push_back(MyRECT(0, 0, 43, 60));
	temp.push_back(MyRECT(0, 84, 123, 55));
	temp.push_back(MyRECT(61, 38, 75, 108));
	temp.push_back(MyRECT(0, 160, 194, 51));
	temp.push_back(MyRECT(61, 0, 37, 113));
	temp.push_back(MyRECT(0, 124, 159, 50));
	temp.push_back(MyRECT(56, 76, 113, 103));
	this->mState.push_back(new ObjectStateWithLoop(temp, 12, L"Object\\Enemy\\Enemy4\\Run.png", D3DXVECTOR2(0.15, -0.4), CenterArchor::CenterBottom));

	temp.clear();


	//Attack
	temp.push_back(MyRECT(0, 0, 55, 58, D3DXVECTOR3(-2, 0, 0)));
	temp.push_back(MyRECT(45, 56, 92, 101,D3DXVECTOR3(6,0,0)));
	temp.push_back(MyRECT(0, 56, 102, 44, D3DXVECTOR3(12, 0, 0)));
	temp.push_back(MyRECT(45, 93, 126, 97, D3DXVECTOR3(7, 0, 0)));
	temp.push_back(MyRECT(59, 0, 43, 109));


	this->mState.push_back(new ObjectState(temp, 11, L"Object\\Enemy\\Enemy4\\Attack.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();

	//TuotQuan
	temp.push_back(MyRECT(0, 136, 191, 52,D3DXVECTOR3(-1,0,0)));
	temp.push_back(MyRECT(0, 192, 247, 51, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(52, 192, 247, 102, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(128, 0, 55, 178, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(0, 70, 135, 48, D3DXVECTOR3(5, 0, 0)));
	temp.push_back(MyRECT(0, 0, 69, 65, D3DXVECTOR3(14, 0, 0)));
	temp.push_back(MyRECT(66, 0, 68, 127, D3DXVECTOR3(14, 0, 0)));
	temp.push_back(MyRECT(49, 70, 135, 97, D3DXVECTOR3(5, 0, 0)));
	temp.push_back(MyRECT(98, 69, 124, 148, D3DXVECTOR3(-2, 0, 0)));
	temp.push_back(MyRECT(53, 136, 191, 105, D3DXVECTOR3(-2, 0, 0)));
	this->mState.push_back(new ObjectState(temp, 12, L"Object\\Enemy\\Enemy4\\TuotQuan.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

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

	this->mState.at(mCurrentState)->SetPosition(pos);
}

Enemy4::~Enemy4()
{
}

void Enemy4::ResetDefault()
{
	this->mDone = false;

	this->mCurrentState = Enemy4State::Enemy4State_Wait;

	mWidth = 10;
	mHeight = 140;

	this->mHP = 2;

	this->mPosition = mDefaultPosition;

	this->mState.at(mCurrentState)->SetPosition(mDefaultPosition);

	mLastAladdinPosInInteractBox = D3DXVECTOR3(0, 0, 0);
	this->mState.at(Enemy4State::Enemy4State_Explosion)->resetFrame();
}

void Enemy4::Update(float DeltaTime)
{
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
	case Enemy4State::Enemy4State_DoNothing:
		if ((this->mLastAladdinPosInInteractBox.x <= this->mInteractBoundingBox.left && this->mDir == Direction::Left)|| (this->mLastAladdinPosInInteractBox.x >= this->mInteractBoundingBox.right && this->mDir == Direction::Right))
		{
			this->mState.at(Enemy4State::Enemy4State_Attack)->resetFrame();
			this->mState.at(Enemy4State::Enemy4State_Attack)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy4State::Enemy4State_Attack;
		}
		//else 
		break;
	case Enemy4State::Enemy4State_Run:
		if (this->GetBoundingBox().left <= this->mInteractBoundingBox.left + 10 || this->GetBoundingBox().right >= this->mInteractBoundingBox.right - 10)
		{
			//this->mState.at(Enemy4State::Enemy4State_Attack)->resetFrame();
			this->mState.at(Enemy4State::Enemy4State_DoNothing)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy4State::Enemy4State_DoNothing;
		}

		break;
	case Enemy4State::Enemy4State_Attack:
		if (this->mState.at(mCurrentState)->GetCurrentIdx() == 2 && this->mState.at(mCurrentState)->isNextFrame == true)
		{
			SceneManager::GetInstance()->GetCurrentScene()->AddFlyingObject(new FlyingKnife(D3DXVECTOR3(this->mState.at(mCurrentState)->GetPosition().x + ((this->mDir == Direction::Right) ? 1 : -1) * 32, this->mState.at(mCurrentState)->GetPosition().y + 25, 0), this->mDir, D3DXVECTOR2(((mDir == Direction::Right) ? (1.0f) : (-1.0f)) * 0.6, 0.25), D3DXVECTOR2(0, -0.019)));
		}
		if (this->mState.at(mCurrentState)->isDone())
		{
			this->mState.at(Enemy4State::Enemy4State_DoNothing)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			this->mCurrentState = Enemy4State::Enemy4State_DoNothing;
		}
		break;
	case Enemy4State::Enemy4State_TuotQuan:
		if (this->mState.at(mCurrentState)->isDone())
		{
			this->mState.at(Enemy4State::Enemy4State_DoNothing)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			this->mCurrentState = Enemy4State::Enemy4State_DoNothing;
		}
		break;
	}
}

void Enemy4::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	//GraphicsHelper::GetInstance()->DrawBoundingBox(this->GetAttackRange(), D3DCOLOR_XRGB(255, 0, 255));
	this->mState.at(mCurrentState)->Render();
}

void Enemy4::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
	switch (obj->GetID())
	{
	case EObjectID::LAMP:
		if (((Lamp*)obj)->GetCollisioned() && this->GetBoundingBox().Intersects(obj->GetInteractBoundingBox()))
		{
			this->mState.at(Enemy4State::Enemy4State_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy4State::Enemy4State_Explosion;
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
			case Enemy4State::Enemy4State_DoNothing:
				if (this->mLastAladdinPosInInteractBox.x >= this->mInteractBoundingBox.left && this->mLastAladdinPosInInteractBox.x <= this->mInteractBoundingBox.right && obj->GetCurrentState()->GetPosition().x >= this->mInteractBoundingBox.left && obj->GetCurrentState()->GetPosition().x <= this->mInteractBoundingBox.right && obj->GetCurrentState()->GetPosition().y >= this->mInteractBoundingBox.bottom && obj->GetCurrentState()->GetPosition().y <= this->mInteractBoundingBox.top)
				{
					this->mState.at(Enemy4State::Enemy4State_Run)->SetVelocity(0.15, this->mState.at(mCurrentState)->GetVelocity().y);
					this->mState.at(Enemy4State::Enemy4State_Run)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Enemy4State::Enemy4State_Run;
				}
				break;
			case Enemy4State::Enemy4State_Wait:
				if (this->mLastAladdinPosInInteractBox.x >= this->mInteractBoundingBox.left && this->mLastAladdinPosInInteractBox.x <= this->mInteractBoundingBox.right)
				{
					this->mState.at(Enemy4State::Enemy4State_Run)->SetVelocity(0.15, this->mState.at(mCurrentState)->GetVelocity().y);
					this->mState.at(Enemy4State::Enemy4State_Run)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Enemy4State::Enemy4State_Run;
				}
				break;
			case Enemy4State::Enemy4State_Run:
				if (this->GetAttackRange().Intersects(obj->GetBoundingBox()))
				{
					this->mState.at(Enemy4State::Enemy4State_Attack)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Enemy4State::Enemy4State_Attack;
					this->mState.at(Enemy4State::Enemy4State_Attack)->resetFrame();
				}
				break;
			case Enemy4State::Enemy4State_Explosion:
				if (this->mState.at(mCurrentState)->isDone())
				{

					mDone = true;
				}
				break;
			}
		}
		if ((collisionWith == CollisionWith::SwordBoundingBox))
		{
			if (!AABBresult)
				return;

			switch (mCurrentState)
			{
			default:

				this->mState.at(Enemy4State::Enemy4State_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
				mCurrentState = Enemy4State::Enemy4State_Explosion;
				this->mWidth = 0;
				this->mHeight = 0;
			}
		}
	}
}

void Enemy4::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::GROUND:

		if (collision.dir == Direction::Up || collision.dir == Direction::Down)
		{


			this->mState.at(mCurrentState)->SetVelocity(this->mState.at(mCurrentState)->GetVelocity().x, this->mState.at(mCurrentState)->GetVelocity().y*collision.EntryTime);


		}

		break;
	case EObjectID::STAIR:
		if (collision.dir == Direction::Left || collision.dir == Direction::Right)
		{
			/*mWallCollision = true;

			this->mAladdinState.at(mCurrentState)->SetVelocity(this->mAladdinState.at(mCurrentState)->GetVelocity().x*collision.EntryTime, this->mAladdinState.at(mCurrentState)->GetVelocity().y);

			this->mPosition = this->mAladdinState.at(mCurrentState)->GetPosition();*/
			this->mState.at(mCurrentState)->SetPosition(this->mState.at(mCurrentState)->GetPosition().x, obj->GetBoundingBox().top);
		}
		else if (collision.dir == Direction::Up || collision.dir == Direction::Down)
		{


			this->mState.at(mCurrentState)->SetVelocity(this->mState.at(mCurrentState)->GetVelocity().x, this->mState.at(mCurrentState)->GetVelocity().y*collision.EntryTime);


		}
		break;
	case EObjectID::THROWINGKNIFE:
	case EObjectID::THROWINGAPPLE:
		if (collision.dir == Right)
		{
			//this->mDir = Direction::Right;
			this->mLastAladdinPosInInteractBox.x = this->GetInteractBoundingBox().right;
			this->mState.at(Enemy4State::Enemy4State_TuotQuan)->resetFrame();
			this->mState.at(Enemy4State::Enemy4State_TuotQuan)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy4State::Enemy4State_TuotQuan;
			//this->mState.at(mCurrentState)->SetFlipVertical(((mDir == Direction::Right) ? (false) : (true)));
		}
		else
		{
			this->mLastAladdinPosInInteractBox.x = this->GetInteractBoundingBox().left;
			this->mState.at(Enemy4State::Enemy4State_TuotQuan)->resetFrame();
			this->mState.at(Enemy4State::Enemy4State_TuotQuan)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy4State::Enemy4State_TuotQuan;
		}
			
			

		if (this->mHP >= 2)
		{
			this->mHP--;

			this->mState.at(Enemy4State::Enemy4State_TuotQuan)->resetFrame();
			this->mState.at(Enemy4State::Enemy4State_TuotQuan)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy4State::Enemy4State_TuotQuan;
		}
		else if (this->mHP == 1)
		{
			this->mState.at(Enemy4State::Enemy4State_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy4State::Enemy4State_Explosion;

			this->mWidth = 0;
			this->mHeight = 0;

		}
		break;
	case EObjectID::THROWINGCAMELSALIVA:
		this->mState.at(Enemy4State::Enemy4State_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
		mCurrentState = Enemy4State::Enemy4State_Explosion;

		this->mWidth = 0;
		this->mHeight = 0;
		break;

	}
}

MyRECT Enemy4::GetAttackRange()
{
	if (this->mDir == Right)
		return MyRECT(this->GetBoundingBox().top, this->GetBoundingBox().right + 00 , this->GetBoundingBox().right + 205, this->GetBoundingBox().bottom);
	else
		return MyRECT(this->GetBoundingBox().top, this->GetBoundingBox().left - 205, this->GetBoundingBox().left - 00, this->GetBoundingBox().bottom);
}

MyRECT Enemy4::GetAttackBoundingBox()
{
	return MyRECT();
}

D3DXVECTOR2 Enemy4::GetVelocity()
{
	return this->mState.at(mCurrentState)->GetVelocity();
}

bool Enemy4::isDone()
{
	return this->mDone;
}
