#include "ThrowApple.h"
#include "ThrowPot.h"
#include "FlyingKnife.h"
#include "ThrowPotEnemy.h"
#include "HalfApple.h"
#include "SoundHelper.h"

ThrowingApple::ThrowingApple(D3DXVECTOR3 pos, Direction dir)
{
	mCollisioned = false;
	mBossCollisioned = false;

	this->mID = EObjectID::THROWINGAPPLE;

	this->mPosition = pos;
	this->mTime = 0;
	this->mDone = 0;
	this->mCurrentState = ThrowingAppleState::Normal;

	this->mInteractBoundingBox = MyRECT(0, 0, 0, 0);
	this->mBoundingBox = MyRECT(0, 0, 0, 0);
	

	this->mDir = dir;

	mWidth = 20;
	mHeight = 20;

	vector<MyRECT> temp;

	temp.push_back(MyRECT(0, 18, 25, 7));
	temp.push_back(MyRECT(0, 0, 9, 7));
	temp.push_back(MyRECT(0, 10, 17, 8));
	temp.push_back(MyRECT(8, 0, 9, 14));

	this->mState.push_back(new ObjectStateWithLoop(temp, 18, L"Object\\ThrowingApple.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	this->mState.at(0)->SetPosition(pos);
	temp.clear();

	temp.push_back(MyRECT(28, 51, 58, 38));
	temp.push_back(MyRECT(28, 30, 50, 46));
	temp.push_back(MyRECT(26, 0, 29, 48));
	temp.push_back(MyRECT(0, 0, 31, 25));
	temp.push_back(MyRECT(0, 32, 62, 27));
	this->mState.push_back( new ObjectState(temp, 15, L"Object\\AppleExplosion.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	//this->mState->SetPosition(pos);
	temp.clear();

	temp.push_back(MyRECT(101, 209, 228, 121));
	temp.push_back(MyRECT(135, 171, 197, 162, D3DXVECTOR3(0, -2, 0)));
	temp.push_back(MyRECT(135, 198, 224, 162, D3DXVECTOR3(0, -2, 0)));
	temp.push_back(MyRECT(51, 200, 230, 80, D3DXVECTOR3(2, -2, 0)));
	temp.push_back(MyRECT(103, 79, 122, 146, D3DXVECTOR3(-1, -10, 0)));
	temp.push_back(MyRECT(162, 131, 169, 199, D3DXVECTOR3(-2, -6, 0)));
	temp.push_back(MyRECT(103, 0, 78, 146, D3DXVECTOR3(0, -8, 0)));
	temp.push_back(MyRECT(50, 0, 108, 102, D3DXVECTOR3(0, -13, 0)));
	temp.push_back(MyRECT(51, 109, 199, 98, D3DXVECTOR3(0, -7, 0)));
	temp.push_back(MyRECT(0, 111, 219, 50, D3DXVECTOR3(0, -14, 0)));
	temp.push_back(MyRECT(0, 0, 110, 49, D3DXVECTOR3(1, -14, 0)));
	temp.push_back(MyRECT(147, 44, 87, 186, D3DXVECTOR3(0, -4, 0)));
	temp.push_back(MyRECT(99, 123, 166, 136, D3DXVECTOR3(0, -4, 0)));
	temp.push_back(MyRECT(147, 88, 130, 184, D3DXVECTOR3(0, -4, 0)));
	temp.push_back(MyRECT(147, 0, 43, 191, D3DXVECTOR3(0, -10, 0)));
	temp.push_back(MyRECT(99, 167, 208, 134, D3DXVECTOR3(0, -5, 0)));
	temp.push_back(MyRECT(185, 88, 128, 209, D3DXVECTOR3(1, 4, 0)));
	temp.push_back(MyRECT(137, 131, 170, 161, D3DXVECTOR3(1, 5, 0)));
	temp.push_back(MyRECT(187, 44, 69, 207, D3DXVECTOR3(0, 8, 0)));
	temp.push_back(MyRECT(81, 209, 229, 100, D3DXVECTOR3(0, 8, 0)));
	this->mState.push_back(new ObjectState(temp, 18, L"Object\\Explosion.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//this->mVelocity = D3DXVECTOR2(((mDir == Direction::Right) ? (1.0f) : (-1.0f)) * 1, 0.1);
	this->mState.at(mCurrentState)->SetVelocity(this->mVelocity);
}

ThrowingApple::~ThrowingApple()
{ 
	ObjectState* pd;
	for (vector<ObjectState *>::iterator it = mState.begin(); it != mState.end(); ++it) {
		pd = *it;
		delete pd;
	}


}

void ThrowingApple::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	this->mState.at(mCurrentState)->SetFlipVertical(((mDir == Direction::Right) ? (false) : (true)));

	switch (mCurrentState)
	{
	case ThrowingAppleState::Normal:
		if (!mCollisioned)
		{
			this->mState.at(mCurrentState)->SetVelocity(this->mVelocity.x, this->mState.at(mCurrentState)->GetVelocity().y - 0.032);
			//this->mVelocity = this->mState.at(mCurrentState)->GetVelocity();
		}
		else if (mBossCollisioned)
		{
			this->mState.at(mCurrentState)->SetVelocity(0, 0);
			mCurrentState = ThrowingAppleState::Boss_Explosion;
			this->mState.at(mCurrentState)->SetPosition(this->mPosition);
		}
		else
		{
			this->mState.at(mCurrentState)->SetVelocity(0, 0);
			mCurrentState = ThrowingAppleState::Explosion;
			this->mState.at(mCurrentState)->SetPosition(this->mPosition);
		}
			

		break;

	case ThrowingAppleState::Boss_Explosion:
	case ThrowingAppleState::Explosion:
	{
		
		this->mPosition = this->mState.at(mCurrentState)->GetPosition();

		if (this->mState.at(mCurrentState)->isDone())
		{
			mDone = true;
		}

		break;
	}

	}

	//UpdateBoundingBox();
}

void ThrowingApple::Render(float DeltaTime) 
{

	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

ObjectState* ThrowingApple::GetCurrentState()
{
	return this->mState.at(mCurrentState);
}

bool ThrowingApple::isDone()
{
	return mDone;
}

void ThrowingApple::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::GROUND:
//	case EObjectID::CAMEL:
	
	case EObjectID::ENEMY1:
	case EObjectID::ENEMY2:
	case EObjectID::ENEMY3:
	case EObjectID::ENEMY4:
	case EObjectID::ENEMY5:
	
	case EObjectID::WALL:
	case EObjectID::STAIR:
		SoundHelper::GetInstance()->Play("Apple_Splat", false , 1);
		this->mState.at(mCurrentState)->SetVelocity(this->mState.at(mCurrentState)->GetVelocity().x * collision.EntryTime, this->mState.at(mCurrentState)->GetVelocity().y * collision.EntryTime);
		mCollisioned = true;
		break;
	case EObjectID::BOSS_JAFAR:
		SoundHelper::GetInstance()->Play("Apple_Splat", false, 1);
		this->mState.at(mCurrentState)->SetVelocity(this->mState.at(mCurrentState)->GetVelocity().x * collision.EntryTime, this->mState.at(mCurrentState)->GetVelocity().y * collision.EntryTime);
		mCollisioned = true;
		mBossCollisioned = true;
		break;
	case EObjectID::THROWPOTENEMY:

		if (((ThrowPotEnemy*)obj)->GetCurrentStateID() == ThrowPotEnemyState::ThrowPotEnemy_ThrowingPot)

		{
			SoundHelper::GetInstance()->Play("Apple_Splat", false, 1);
			this->mState.at(mCurrentState)->SetVelocity(this->mState.at(mCurrentState)->GetVelocity().x * collision.EntryTime, this->mState.at(mCurrentState)->GetVelocity().y * collision.EntryTime);
			mCollisioned = true;

		}
		break;
	case EObjectID::THROWINGPOT:
	
		//this->mVelocity = D3DXVECTOR2(0, 0);
		if (((ThrowPot*)obj)->GetCurrentStateID() == ThrowPotState::ThrowPot_Normal)

		{
			SoundHelper::GetInstance()->Play("Apple_Splat", false, 1);
			this->mState.at(mCurrentState)->SetVelocity(this->mState.at(mCurrentState)->GetVelocity().x * collision.EntryTime, this->mState.at(mCurrentState)->GetVelocity().y * collision.EntryTime);
			mCollisioned = true;

		}
		break;
	case EObjectID::THROWINGKNIFE:
		if (((FlyingKnife*)obj)->GetCurrenStateID() == FlyingKnifeState::FlyingKnifeState_Normal)

		{
			SoundHelper::GetInstance()->Play("Apple_Splat", false, 1);
			this->mState.at(mCurrentState)->SetVelocity(this->mState.at(mCurrentState)->GetVelocity().x * collision.EntryTime, this->mState.at(mCurrentState)->GetVelocity().y * collision.EntryTime);
			SceneManager::GetInstance()->GetCurrentScene()->AddFlyingObject(new HalfApple(this->mState.at(mCurrentState)->GetPosition(),Direction::Left,0.2));
			SceneManager::GetInstance()->GetCurrentScene()->AddFlyingObject(new HalfApple(this->mState.at(mCurrentState)->GetPosition(), Direction::Right,0.5));
			SoundHelper::GetInstance()->Play("Apple_Slice", false, 1);
			mDone = true;

		}
		break;
	}
}
