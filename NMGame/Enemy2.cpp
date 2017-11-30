#include "Enemy2.h"

Enemy2::Enemy2() : Enemy::Enemy()
{
	this->mCanBeAttack = true;
	this->mCanBeHitByFlyingObject = true;
	this->mInteractWithInteractBB = true;
	this->mCanBeHitByFlyingObject = true;
	this->mCanAttack = true;

	mLastAladdinPosInInteractBox = D3DXVECTOR3(0, 0, 0);

	this->mID = EObjectID::ENEMY2;

	this->mDone = false;
	this->mOnFire = false;

	mLastFireGround = nullptr;

	this->mCurrentState = Enemy2State::Enemy2State_DoNothing;

	mWidth = 10;
	mHeight = 140;

	this->mHP = 2;
}

Enemy2::Enemy2(MyRECT bb, D3DXVECTOR3 pos) : Enemy2()
{
	this->mBoundingBox = MyRECT(0, 0, 0, 0);
	this->mInteractBoundingBox = bb;

	this->mPosition = pos;


	vector<MyRECT> temp;

	//DoNothing
	temp.push_back(MyRECT(0, 0, 55, 52));
	this->mState.push_back(new ObjectState(temp, 20, L"Object\\Enemy\\Enemy2\\DoNothing.png", D3DXVECTOR2(0, -0.4f), CenterArchor::CenterBottom));

	temp.clear();

	//Attack
	temp.push_back(MyRECT(74, 103, 146, 134));
	temp.push_back(MyRECT(124, 0, 43, 197, D3DXVECTOR3(-3,0,0)));	
	temp.push_back(MyRECT(57, 0, 52, 123, D3DXVECTOR3(-4, 0, 0)));
	temp.push_back(MyRECT(0, 0, 114, 56, D3DXVECTOR3(31, 0, 0)));
	temp.push_back(MyRECT(0, 115, 206, 73, D3DXVECTOR3(23, 0, 0)));
	temp.push_back(MyRECT(57, 53, 102, 128, D3DXVECTOR3(1, 0, 0)));
	temp.push_back(MyRECT(129, 44, 87, 202, D3DXVECTOR3(-3, 0, 0)));
	this->mState.push_back(new ObjectState(temp, 15, L"Object\\Enemy\\Enemy2\\Attack1.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();


	//Attack2
	temp.push_back(MyRECT(93, 0, 67, 137,D3DXVECTOR3( + 21, 0, 0)));
	temp.push_back(MyRECT(0, 185, 255, 42,D3DXVECTOR3(1 + 21,0,0)));
	temp.push_back(MyRECT(47, 89, 164, 90, D3DXVECTOR3(2 + 21, 0, 0)));
	temp.push_back(MyRECT(47, 0, 88, 92, D3DXVECTOR3(9 + 21, 0, 0)));
	temp.push_back(MyRECT(0, 0, 95, 46, D3DXVECTOR3(11 + 21, 0, 0)));
	temp.push_back(MyRECT(0, 96, 184, 45, D3DXVECTOR3(9 + 21, 0, 0)));
	temp.push_back(MyRECT(46, 165, 240, 89, D3DXVECTOR3(2 + 21, 0, 0)));

	this->mState.push_back(new ObjectState(temp, 15, L"Object\\Enemy\\Enemy2\\Attack2.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();

	//Run
	temp.push_back(MyRECT(0, 57, 109, 54));
	temp.push_back(MyRECT(0, 0, 56, 55));
	temp.push_back(MyRECT(56, 0, 51, 110));
	temp.push_back(MyRECT(56, 52, 101, 108));
	temp.push_back(MyRECT(55, 102, 144, 108));
	temp.push_back(MyRECT(0, 158, 202, 56));
	temp.push_back(MyRECT(0, 110, 157, 54));

	this->mState.push_back(new ObjectStateWithLoop(temp, 13, L"Object\\Enemy\\Enemy2\\Run.png", D3DXVECTOR2(0.27f,-0.4f), CenterArchor::CenterBottom));

	temp.clear();

	

	//FireGround
	temp.push_back(MyRECT(119, 126, 164, 177));
	temp.push_back(MyRECT(173, 42, 83, 226));
	temp.push_back(MyRECT(52, 44, 87, 112));
	temp.push_back(MyRECT(113, 42, 83, 172));
	temp.push_back(MyRECT(119, 84, 125, 173));
	temp.push_back(MyRECT(0, 92, 135, 59));
	temp.push_back(MyRECT(60, 175, 217, 118));
	temp.push_back(MyRECT(0, 180, 223, 58));
	temp.push_back(MyRECT(0, 46, 91, 51));
	temp.push_back(MyRECT(0, 136, 179, 59));
	temp.push_back(MyRECT(60, 132, 174, 118));
	temp.push_back(MyRECT(60, 88, 131, 118));
	temp.push_back(MyRECT(0, 0, 45, 51));
	temp.push_back(MyRECT(173, 0, 41, 227));
	temp.push_back(MyRECT(52, 0, 43, 112));
	temp.push_back(MyRECT(113, 0, 41, 172));
	this->mState.push_back(new ObjectStateWithLoop(temp, 13, L"Object\\Enemy\\Enemy2\\FireGround.png", D3DXVECTOR2(0.26f, 0), CenterArchor::CenterBottom));

	temp.clear();

	//Taunt
	temp.push_back(MyRECT(0, 168, 212, 53));
	temp.push_back(MyRECT(108, 0, 37, 162,D3DXVECTOR3(-4,0,0)));
	temp.push_back(MyRECT(54, 0, 54, 107, D3DXVECTOR3(5, 0, 0)));
	temp.push_back(MyRECT(0, 0, 58, 53, D3DXVECTOR3(7, 0, 0)));
	temp.push_back(MyRECT(0, 118, 167, 53, D3DXVECTOR3(2, 0, 0)));
	temp.push_back(MyRECT(54, 160, 204, 107));
	temp.push_back(MyRECT(54, 55, 109, 107, D3DXVECTOR3(5, 0, 0)));
	temp.push_back(MyRECT(0, 59, 117, 53, D3DXVECTOR3(7, 0, 0)));
	temp.push_back(MyRECT(54, 110, 159, 107, D3DXVECTOR3(2, 0, 0)));
	temp.push_back(MyRECT(108, 38, 75, 162, D3DXVECTOR3(-4, 0, 0)));
	temp.push_back(MyRECT(54, 205, 249, 107));
	this->mState.push_back(new ObjectState(temp, 14, L"Object\\Enemy\\Enemy2\\Taunt.png", D3DXVECTOR2(0.0f, -0.4f), CenterArchor::CenterBottom));

	temp.clear();

	//Damage
	temp.push_back(MyRECT(72, 133, 187, 120));
	temp.push_back(MyRECT(0, 147, 210, 71));
	temp.push_back(MyRECT(67, 67, 132, 124));
	temp.push_back(MyRECT(0, 75, 146, 66));
	temp.push_back(MyRECT(0, 0, 74, 64));
	temp.push_back(MyRECT(65, 0, 66, 121));
	temp.push_back(MyRECT(72, 188, 242, 120));
	this->mState.push_back(new ObjectState(temp, 15, L"Object\\Enemy\\Enemy2\\Damage.png", D3DXVECTOR2(0.0f, 0.0f), CenterArchor::CenterBottom));

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

Enemy2::~Enemy2()
{
}

void Enemy2::Update(float DeltaTime)
{
	

	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	this->mState.at(mCurrentState)->ResetDefaultVelocity();

	
	if (!mOnFire &&this->mCurrentState != Enemy2State::Enemy2State_Run_FireGround)
	{
		if (mLastAladdinPosInInteractBox.x <= this->mPosition.x)
			this->mDir = Direction::Left;
		else
			this->mDir = Direction::Right;
	}
	

	this->mState.at(mCurrentState)->SetFlipVertical(((mDir == Direction::Right) ? (false) : (true)));

	if (mLastFireGround != nullptr)
	{
		switch (mCurrentState)
		{
		case Enemy2State::Enemy2State_DoNothing:

			this->mState.at(Enemy2State::Enemy2State_Taunt)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy2State::Enemy2State_Taunt;
			break;
		case Enemy2State::Enemy2State_Run:
			if (mLastFireGround->GetBoundingBox().Intersects(this->GetBoundingBox()))
			{
				this->mState.at(Enemy2State::Enemy2State_Run_FireGround)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
				mCurrentState = Enemy2State::Enemy2State_Run_FireGround;
			}
			else if (this->GetBoundingBox().left <= this->mInteractBoundingBox.left + 10 || this->GetBoundingBox().right >= this->mInteractBoundingBox.right - 10)
			{
				this->mState.at(Enemy2State::Enemy2State_DoNothing)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
				mCurrentState = Enemy2State::Enemy2State_DoNothing;
			}
			break;
			
		case Enemy2State::Enemy2State_Run_FireGround:
			if (!mLastFireGround->GetBoundingBox().Intersects(this->GetBoundingBox()))
			{
				if (this->mDir == Direction::Left && (mLastAladdinPosInInteractBox.x > this->mState.at(mCurrentState)->GetPosition().x + 30/*|| mLastAladdinPosInInteractBox.x - this->mState.at(mCurrentState)->GetPosition().x >= 60*/)|| this->mDir == Direction::Right && mLastAladdinPosInInteractBox.x < this->mState.at(mCurrentState)->GetPosition().x - 30)
				{
					int randNumber = rand() % 2; //33%
					if (randNumber == 0)
					{
						this->mState.at(Enemy2State::Enemy2State_Taunt)->resetFrame();
						this->mState.at(Enemy2State::Enemy2State_Taunt)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
						mCurrentState = Enemy2State::Enemy2State_Taunt;

					}
					else
					{
						this->mState.at(Enemy2State::Enemy2State_Run)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
						mCurrentState = Enemy2State::Enemy2State_Run;
					}

					
				}
				else
				{
					this->mState.at(Enemy2State::Enemy2State_Run)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Enemy2State::Enemy2State_Run;
				}
				
			}
			break;
		
		case Enemy2State::Enemy2State_Damage:
			if (this->mState.at(mCurrentState)->isDone())
			{
				if (mLastFireGround->GetBoundingBox().Intersects(this->GetBoundingBox()))
				{
					this->mState.at(Enemy2State::Enemy2State_Run_FireGround)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Enemy2State::Enemy2State_Run_FireGround;
				}
				else if (this->GetBoundingBox().left <= this->mInteractBoundingBox.left + 10 || this->GetBoundingBox().right >= this->mInteractBoundingBox.right - 10)
				{
					this->mState.at(Enemy2State::Enemy2State_DoNothing)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Enemy2State::Enemy2State_DoNothing;
				}
				else
				{
					this->mState.at(Enemy2State::Enemy2State_Run)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Enemy2State::Enemy2State_Run;
				}
				break;
			}
			break;
		}
	}
	
}

void Enemy2::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);
	//GraphicsHelper::GetInstance()->DrawBoundingBox(GetAttackBoundingBox(), D3DCOLOR_XRGB(255, 0, 255));

	this->mState.at(mCurrentState)->Render();
}

void Enemy2::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
	switch(obj->GetID())
	{

	case EObjectID::ALADDIN:
		if (AABBresult == true)
			mLastAladdinPosInInteractBox = obj->GetCurrentState()->GetPosition();
		if (collisionWith == CollisionWith::InteractBoundingBox)
		{
			switch (mCurrentState)
			{
			case Enemy2State::Enemy2State_DoNothing:
				

				if (AABBresult == true)
				{
					if (mLastAladdinPosInInteractBox.x <= this->mPosition.x)
						this->mDir = Direction::Left;
					else
						this->mDir = Direction::Right;

				

					this->mState.at(Enemy2State::Enemy2State_Run)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					this->mState.at(Enemy2State::Enemy2State_Run)->SetVelocity(0.4, this->mState.at(mCurrentState)->GetVelocity().y);
					mCurrentState = Enemy2State::Enemy2State_Run;
					this->mState.at(mCurrentState)->SetFlipVertical(((mDir == Direction::Right) ? (false) : (true)));

				}


				if (this->GetAttackRange().Intersects(obj->GetBoundingBox()))
				{
					this->mState.at(Enemy2State::Enemy2State_Attack1)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Enemy2State::Enemy2State_Attack1;
					this->mState.at(Enemy2State::Enemy2State_Attack1)->resetFrame();
				}
				break;
			case Enemy2State::Enemy2State_Taunt:
				if (this->mState.at(mCurrentState)->isDone())
				{
					if (!(this->GetBoundingBox().left <= this->mInteractBoundingBox.left + 10 || this->GetBoundingBox().right >= this->mInteractBoundingBox.right - 10))
					{
						this->mState.at(Enemy2State::Enemy2State_Run)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
						mCurrentState = Enemy2State::Enemy2State_Run;
					}
					else if (this->GetAttackRange().Intersects(obj->GetBoundingBox()))
					{
						this->mState.at(Enemy2State::Enemy2State_Attack1)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
						mCurrentState = Enemy2State::Enemy2State_Attack1;
						this->mState.at(Enemy2State::Enemy2State_Attack1)->resetFrame();
					}
					else
					{
						this->mState.at(Enemy2State::Enemy2State_Taunt)->resetFrame();
					}
				}
				break;
			case Enemy2State::Enemy2State_Run:


				if (this->GetAttackRange().Intersects(obj->GetBoundingBox()))
				{
				this->mState.at(Enemy2State::Enemy2State_Attack2)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
				mCurrentState = Enemy2State::Enemy2State_Attack2;
				this->mState.at(Enemy2State::Enemy2State_Attack2)->resetFrame();
				}
				//else 
				break;
			case Enemy2State::Enemy2State_Attack1:
				if (this->mState.at(mCurrentState)->isDone())
				{
					if (this->GetAttackRange().Intersects(obj->GetBoundingBox()))
					{
						int randNumber = rand() % 3; //33%
						if (randNumber == 0)
						{
							this->mState.at(Enemy2State::Enemy2State_Attack1)->resetFrame();
						}
						else
						{
							this->mState.at(Enemy2State::Enemy2State_Attack2)->SetPosition(this->mState.at(mCurrentState)->GetPosition());

							mCurrentState = Enemy2State::Enemy2State_Attack2;
							this->mState.at(Enemy2State::Enemy2State_Attack2)->resetFrame();

						}
					}
					else
					{
						this->mState.at(Enemy2State::Enemy2State_Run)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
						this->mState.at(Enemy2State::Enemy2State_Run)->SetVelocity(0.4, this->mState.at(mCurrentState)->GetVelocity().y);
						mCurrentState = Enemy2State::Enemy2State_Run;
					}
					
				}
			case Enemy2State::Enemy2State_Attack2:
				if (this->mState.at(mCurrentState)->isDone())
				{
					if (this->GetAttackRange().Intersects(obj->GetBoundingBox()))
					{
						int randNumber = rand() % 3; //67%
						if (randNumber == 0 || randNumber == 1)
						{
							this->mState.at(Enemy2State::Enemy2State_Attack2)->resetFrame();
						}
						else
						{
							this->mState.at(Enemy2State::Enemy2State_Attack1)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
							mCurrentState = Enemy2State::Enemy2State_Attack1;
							this->mState.at(Enemy2State::Enemy2State_Attack1)->resetFrame();

						}
					}
					else
					{
						this->mState.at(Enemy2State::Enemy2State_Run)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
						this->mState.at(Enemy2State::Enemy2State_Run)->SetVelocity(0.4, this->mState.at(mCurrentState)->GetVelocity().y);
						mCurrentState = Enemy2State::Enemy2State_Run;
					}

				}
				break;
			case Enemy2State::Enemy2State_Explosion:
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
			case Enemy2State::Enemy2State_Damage:
				break;
			default:
				if (this->mHP == 2)
				{
					this->mHP--;

					this->mState.at(Enemy2State::Enemy2State_Damage)->resetFrame();
					this->mState.at(Enemy2State::Enemy2State_Damage)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Enemy2State::Enemy2State_Damage;
				}
				else if (this->mHP == 1)
				{
					this->mState.at(Enemy2State::Enemy2State_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
					mCurrentState = Enemy2State::Enemy2State_Explosion;

					this->mWidth = 0;
					this->mHeight = 0;

				}
			}

		}
	}
}

void Enemy2::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::GROUND:

		if (collision.dir == Direction::Up|| collision.dir == Direction::Down)
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
	case EObjectID::FIREGROUND:
			mLastFireGround = (FireGround*)obj;
		break;
	case EObjectID::THROWINGAPPLE:
		if (this->mHP == 2)
		{
			this->mHP--;

			this->mState.at(Enemy2State::Enemy2State_Damage)->resetFrame();
			this->mState.at(Enemy2State::Enemy2State_Damage)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy2State::Enemy2State_Damage;
		}
		else if (this->mHP == 1)
		{
			this->mState.at(Enemy2State::Enemy2State_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy2State::Enemy2State_Explosion;
			this->mWidth = 0;
			this->mHeight = 0;
		}
		break;
	}
}

MyRECT Enemy2::GetAttackRange()
{
	if (this->mDir == Right)
		return MyRECT(this->GetBoundingBox().top, this->GetBoundingBox().right - 60, this->GetBoundingBox().right + 85, this->GetBoundingBox().bottom);
	else
		return MyRECT(this->GetBoundingBox().top, this->GetBoundingBox().left - 85, this->GetBoundingBox().left + 60, this->GetBoundingBox().bottom);
}

MyRECT Enemy2::GetAttackBoundingBox()
{
	switch (mCurrentState)
	{
	case Enemy2State::Enemy2State_Attack1:

		switch (mState.at(mCurrentState)->GetCurrentIdx())
		{
		case 4:
			return MyRECT(this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().top + 20, this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().left + ((mDir == Direction::Right) ? (65) : (6)), this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().right + ((mDir == Direction::Right) ? (-6) : (-65)), this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().bottom + 20);
		default:
			return MyRECT(0, 0, 0, 0);
		}

		break;
	case Enemy2State::Enemy2State_Attack2:

		switch (mState.at(mCurrentState)->GetCurrentIdx())
		{
		case 4:
			return MyRECT(this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().top + 20, this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().left + ((mDir == Direction::Right) ? (65) : (6)), this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().right + ((mDir == Direction::Right) ? (-6) : (-65)), this->mState.at(mCurrentState)->GetCurrentFrameBoundingBox().bottom + 20);
		default:
			return MyRECT(0, 0, 0, 0);
		}

		break;

	default:
		return MyRECT(0, 0, 0, 0);

	}
}

D3DXVECTOR2 Enemy2::GetVelocity()
{
	return this->mState.at(mCurrentState)->GetVelocity();
}
