#include "Jafar.h"
#include "JafarBullet.h"
#include "BossFire.h"

Jafar::Jafar()
{
	this->mCanBeAttack = true;
	this->mCanBeHitByFlyingObject = true;
	this->mInteractWithInteractBB = true;
	this->mCanBeHitByFlyingObject = true;
	this->mCanAttack = true;

	this->mDir = Direction::Right;
	this->mID = EObjectID::BOSS_JAFAR;

	this->mDone = false;

	this->mCurrentState = JafarState::JafarState_DoNothing;
		
	mWidth = 10;
	mHeight = 140;

	this->mHP = 31;

	
	this->mTime = 0;

	mAttackBoundingBox = MyRECT(0, 0, 0, 0);
}

Jafar::Jafar(D3DXVECTOR3 pos, AladdinCharacter* aladdin) : Jafar()
{
	this->mPosition = pos;

	vector<MyRECT> temp;

	//DoNothing
	temp.push_back(MyRECT(0, 312, 369, 70));
	this->mState.push_back(new ObjectState(temp, 20, L"Object\\Boss\\Jafar.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();


	//Hut
	temp.push_back(MyRECT(0, 312, 369, 70));
	temp.push_back(MyRECT(72, 279, 334, 141,D3DXVECTOR3(-1,0,0)));
	temp.push_back(MyRECT(143, 203, 254, 211, D3DXVECTOR3(-3, 0, 0)));
	temp.push_back(MyRECT(140, 0, 68, 209, D3DXVECTOR3(7, 0, 0)));
	temp.push_back(MyRECT(0, 83, 165, 69, D3DXVECTOR3(13, 0, 0)));
	temp.push_back(MyRECT(70, 83, 151, 139, D3DXVECTOR3(7, 0, 0)));
	temp.push_back(MyRECT(0, 166, 248, 69, D3DXVECTOR3(13, 0, 0)));
	temp.push_back(MyRECT(140, 69, 137, 209, D3DXVECTOR3(7, 0, 0)));
	temp.push_back(MyRECT(70, 0, 82, 139, D3DXVECTOR3(13, 0, 0)));
	temp.push_back(MyRECT(70, 152, 220, 139, D3DXVECTOR3(7, 0, 0)));
	temp.push_back(MyRECT(70, 152, 220, 139, D3DXVECTOR3(7, 0, 0)));
	temp.push_back(MyRECT(70, 152, 220, 139, D3DXVECTOR3(7, 0, 0)));
	this->mState.push_back(new ObjectStateWithLoop(temp, 13, L"Object\\Boss\\Jafar.png", D3DXVECTOR2(0, 0),10, CenterArchor::CenterBottom));
	temp.clear();

	//HutToDoNoThing
	temp.push_back(MyRECT(0, 0, 82, 69, D3DXVECTOR3(13, 0, 0)));
	temp.push_back(MyRECT(140, 138, 202, 209, D3DXVECTOR3(5, 0, 0)));
	temp.push_back(MyRECT(0, 249, 311, 71, D3DXVECTOR3(4, 0, 0)));
	temp.push_back(MyRECT(72, 221, 278, 142));
	this->mState.push_back(new ObjectState(temp, 13, L"Object\\Boss\\Jafar.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//BossSnake
	temp.push_back(MyRECT(62, 72, 142, 120,D3DXVECTOR3(16,0,0)));
	temp.push_back(MyRECT(0, 280, 344, 64,D3DXVECTOR3(0,0,0)));
	temp.push_back(MyRECT(83, 143, 210, 155, D3DXVECTOR3(-12, 0, 0)));
	temp.push_back(MyRECT(0, 0, 71, 72, D3DXVECTOR3(-15, 0, 0)));
	temp.push_back(MyRECT(156, 0, 69, 240, D3DXVECTOR3(-15, 0, 0)));
	temp.push_back(MyRECT(121, 71, 140, 204, D3DXVECTOR3(-15, 0, 0)));
	temp.push_back(MyRECT(0, 144, 214, 82, D3DXVECTOR3(-15, 0, 0)));
	temp.push_back(MyRECT(73, 0, 70, 155, D3DXVECTOR3(-15, 0, 0)));
	temp.push_back(MyRECT(156, 141, 205, 240, D3DXVECTOR3(-12, 0, 0)));
	temp.push_back(MyRECT(0, 215, 279, 82, D3DXVECTOR3(5, 0, 0)));
	temp.push_back(MyRECT(0, 72, 143, 61, D3DXVECTOR3(19, 0, 0)));
	this->mState.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\Boss\\BossSnake.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	this->mState.at(0)->SetPosition(pos);
	this->mState.at(1)->SetPosition(pos);
	this->mState.at(2)->SetPosition(pos);
	this->mState.at(3)->SetPosition(pos);

	this->mAladdin = aladdin;


	//FireEffect
	temp.push_back(MyRECT(0, 64, 88, 47));
	temp.push_back(MyRECT(47, 0, 22, 100));
	temp.push_back(MyRECT(0, 89, 113, 47));
	temp.push_back(MyRECT(0, 36, 63, 50));
	temp.push_back(MyRECT(0, 0, 35, 46));
	this->mFireEffect.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\Boss\\FireEffect.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	this->mFireEffect.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\Boss\\FireEffect.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	this->mFireEffect.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\Boss\\FireEffect.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	this->mFireEffect.at(0)->SetPosition(pos);
	this->mFireEffect.at(1)->SetPosition(D3DXVECTOR3(pos.x - 35,pos.y,pos.z));
	this->mFireEffect.at(2)->SetPosition(D3DXVECTOR3(pos.x + 35, pos.y, pos.z));

	//ExplosionEffect
	temp.push_back(MyRECT(164, 54, 80, 188));
	temp.push_back(MyRECT(49, 252, 312, 98));
	temp.push_back(MyRECT(77, 0, 82, 163));
	temp.push_back(MyRECT(74, 84, 166, 154, D3DXVECTOR3(0, 3, 0)));
	temp.push_back(MyRECT(0, 0, 83, 76, D3DXVECTOR3(0, 4, 0)));
	temp.push_back(MyRECT(0, 84, 167, 73, D3DXVECTOR3(0, 4, 0)));
	temp.push_back(MyRECT(136, 167, 247, 206, D3DXVECTOR3(0, 6, 0)));
	temp.push_back(MyRECT(63, 168, 250, 135, D3DXVECTOR3(0, 4, 0)));
	temp.push_back(MyRECT(0, 168, 251, 62, D3DXVECTOR3(0, 9, 0)));
	temp.push_back(MyRECT(155, 83, 164, 208, D3DXVECTOR3(0, 14, 0)));
	temp.push_back(MyRECT(0, 252, 329, 48, D3DXVECTOR3(0, 20, 0)));
	temp.push_back(MyRECT(164, 0, 53, 205, D3DXVECTOR3(0, 24, 0)));
	temp.push_back(MyRECT(99, 251, 293, 138, D3DXVECTOR3(4, 26, 0)));
	temp.push_back(MyRECT(139, 248, 268, 172, D3DXVECTOR3(0, 29, 0)));

	this->mExposionEffect = new ObjectState(temp, 21, L"Object\\LampDisappear.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom);
	this->mExposionEffect->SetPosition(pos);

	this->mInteractBoundingBox = MyRECT(this->mPosition.y + 500, this->mPosition.x - 580, this->mPosition.x + 580, this->mPosition.y - 50);
	this->mCenterRegionRECT = MyRECT(this->mPosition.y + 100, this->mPosition.x - 90, this->mPosition.x + 95, this->mPosition.y - 50);
}

Jafar::~Jafar()
{
}

void Jafar::ResetDefault()
{
}

void Jafar::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	for (int i = 0; i < mFireEffect.size(); i++)
	{
		mFireEffect.at(i)->Update(DeltaTime);
	}
	
	this->mState.at(mCurrentState)->SetFlipVertical(((mAladdin->GetCurrentState()->GetPosition().x >= this->mPosition.x) ? (false) : (true)));

	if (this->mCenterRegionRECT.Intersects(mAladdin->GetBoundingBox()))
	{
		if (mTime >= 35 * DeltaTime)
		{
				mAttackBoundingBox = this->mCenterRegionRECT;
			mTime = 0;
		}
		else
		{
			mAttackBoundingBox = MyRECT(0, 0, 0, 0);
			mTime += DeltaTime;
		}
	}
	else
	{
		mAttackBoundingBox = this->mCenterRegionRECT;
		mTime = DeltaTime * 30;
	}
		
	if (this->mHP == 20)
	{
		this->mCurrentState = JafarState::JafarState_Snake;
	}

	switch (mCurrentState)
	{
	case JafarState::JafarState_DoNothing:
		if (mAladdin->GetBoundingBox().right <= this->mCenterRegionRECT.right && mAladdin->GetBoundingBox().left >= this->mCenterRegionRECT.left)
		{

		}
		else
		{
			if (rand() % 50 == 0)
			{
				this->mCurrentState = JafarState::JafarState_Hut;
				this->mState.at(this->mCurrentState)->resetFrame();
			}
		
		}
		break;
	case JafarState::JafarState_Hut:
		if (this->mInteractBoundingBox.Intersects(this->mAladdin->GetBoundingBox()))
		{
			switch (this->mState.at(mCurrentState)->GetCurrentIdx())
			{
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
				if (mState.at(mCurrentState)->isNextFrame == true)
					if (mAladdin->GetBoundingBox().right <= this->mCenterRegionRECT.right && mAladdin->GetBoundingBox().left >= this->mCenterRegionRECT.left)
					{
						this->mCurrentState = JafarState::JafarState_HuToDoNothing;
						this->mState.at(JafarState::JafarState_HuToDoNothing)->resetFrame();
					}
					else
					{
						if ((mAladdin->GetCurrentState()->GetPosition().x >= this->mPosition.x))
						{
							SceneManager::GetInstance()->GetCurrentScene()->AddFlyingObject(new JafarBullet(D3DXVECTOR3(this->mPosition.x + 70, this->mPosition.y + 130, 0), this->mAladdin));
						}
						else
						{
							SceneManager::GetInstance()->GetCurrentScene()->AddFlyingObject(new JafarBullet(D3DXVECTOR3(this->mPosition.x - 70, this->mPosition.y + 130, 0), this->mAladdin));
						}
					}



				break;


			case 11:
				if (mState.at(mCurrentState)->isNextFrame == true)
					if (mAladdin->GetBoundingBox().right <= this->mCenterRegionRECT.right && mAladdin->GetBoundingBox().left >= this->mCenterRegionRECT.left)
					{
						this->mCurrentState = JafarState::JafarState_HuToDoNothing;
						this->mState.at(JafarState::JafarState_HuToDoNothing)->resetFrame();
					}
					else
					{
						if ((mAladdin->GetCurrentState()->GetPosition().x >= this->mPosition.x))
						{
							SceneManager::GetInstance()->GetCurrentScene()->AddFlyingObject(new JafarBullet(D3DXVECTOR3(this->mPosition.x + 70, this->mPosition.y + 130, 0), this->mAladdin));
						}
						else
						{
							SceneManager::GetInstance()->GetCurrentScene()->AddFlyingObject(new JafarBullet(D3DXVECTOR3(this->mPosition.x - 70, this->mPosition.y + 130, 0), this->mAladdin));
						}
					}
				if (rand() % 120 == 0)
				{
					this->mCurrentState = JafarState::JafarState_HuToDoNothing;
					this->mState.at(JafarState::JafarState_HuToDoNothing)->resetFrame();
				}

				
			}
		}
		else
		{
			this->mCurrentState = JafarState::JafarState_DoNothing;
		}

		break;
	case JafarState::JafarState_HuToDoNothing:
		if (this->mState.at(mCurrentState)->isDone())
		{
			this->mCurrentState = JafarState::JafarState_DoNothing;
		}
		break;
	case JafarState::JafarState_Snake:
		mExposionEffect->Update(DeltaTime);
		switch (this->mState.at(mCurrentState)->GetCurrentIdx()  )
		{
		case 4:
			if (this->mState.at(mCurrentState)->isNextFrame)
			{
				SceneManager::GetInstance()->GetCurrentScene()->AddFlyingObject(new BossFire(this->mPosition, Direction::Left));
				SceneManager::GetInstance()->GetCurrentScene()->AddFlyingObject(new BossFire(this->mPosition, Direction::Right));
			}
			
			break;
		default:
			break;
		}
		break;
	}
}

void Jafar::Render(float DeltaTime)
{
	//GraphicsHelper::GetInstance()->DrawBoundingBox(this->mCenterRegionRECT, D3DCOLOR_XRGB(255, 255, 255));
	GameVisibleEntity::Render(DeltaTime);

	if (this->GetCurrentStateID() == JafarState::JafarState_Snake)
	{
		mExposionEffect->Render();
		for (int i = 0; i < mFireEffect.size(); i++)
		{
			mFireEffect.at(i)->Render();
		}
	}


	this->mState.at(mCurrentState)->Render();

	
}

void Jafar::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
}

void Jafar::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch (obj->GetID())
	{
	case EObjectID::THROWINGAPPLE:
		this->mHP--;
		break;
	}
}

MyRECT Jafar::GetAttackRange()
{
	return this->mInteractBoundingBox;
}

MyRECT Jafar::GetAttackBoundingBox()
{
	return this->mAttackBoundingBox;
}

D3DXVECTOR2 Jafar::GetVelocity()
{
	return D3DXVECTOR2();
}

JafarState Jafar::GetCurrentStateID()
{
	return this->mCurrentState;
}

MyRECT Jafar::GetCenterRegionRECT()
{
	return this->mCenterRegionRECT;
}

bool Jafar::isDone()
{
	return false;
}
