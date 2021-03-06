#include "ThrowPotEnemy.h"
#include "Lamp.h"
#include "SoundHelper.h"
ThrowPotEnemy::ThrowPotEnemy()
{
	this->mID = EObjectID::THROWPOTENEMY;

	this->mCanBeHitByFlyingObject = true;
	this->mInteractWithInteractBB = true;
	this->mCanBeAttack = true;

	mWidth = 50;
	mHeight = 50;
}

ThrowPotEnemy::ThrowPotEnemy(D3DXVECTOR3 pos) : ThrowPotEnemy()
{
	this->mPosition = pos;

	this->mCurrentState = ThrowPotEnemyState::ThrowPotEnemy_DoNothing;

	std::vector<MyRECT> temp;

	//DoNothing
	temp.push_back(MyRECT(0, 0, 1, 1));
	this->mState.push_back(new ObjectState(temp, 13, L"Object\\ThrowPot\\ThrowHand.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	temp.push_back(MyRECT(37, 30, 41, 59, D3DXVECTOR3(0.5, 0, 0)));
	temp.push_back(MyRECT(14, 77, 94, 39, D3DXVECTOR3(3, -3, 0)));
	temp.push_back(MyRECT(63, 30, 53, 95, D3DXVECTOR3(5.5,-10,0)));
	temp.push_back(MyRECT(37, 0, 29, 68, D3DXVECTOR3(8.5, -8, 0)));
	temp.push_back(MyRECT(0, 42, 76, 30, D3DXVECTOR3(13, -2, 0)));
	temp.push_back(MyRECT(0, 0, 41, 36, D3DXVECTOR3(15.5, 4, 0)));
	temp.push_back(MyRECT(31, 42, 75, 62, D3DXVECTOR3(12, 2, 0)));
	temp.push_back(MyRECT(69, 0, 25, 91, D3DXVECTOR3(7, 4.5, 0)));
	temp.push_back(MyRECT(0, 77, 95, 13, D3DXVECTOR3(4, 5, 0)));
	temp.push_back(MyRECT(92, 0, 8, 98, D3DXVECTOR3(0, 5, 0)));
	

	this->mState.push_back(new ObjectStateWithLoop(temp, 13, L"Object\\ThrowPot\\ThrowHand.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//Explosion
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

	this->mState.at(0)->SetPosition(pos);
	this->mState.at(1)->SetPosition(pos);
	this->mState.at(2)->SetPosition(pos);
	temp.clear();

}

ThrowPotEnemy::~ThrowPotEnemy()
{
}

void ThrowPotEnemy::ResetDefault()
{
	this->mDone = false;

	this->mCurrentState = ThrowPotEnemyState::ThrowPotEnemy_DoNothing;

	mWidth = 50;
	mHeight = 50;

	this->mState.at(ThrowPotEnemyState::ThrowPotEnemy_Explosion)->resetFrame();
}

void ThrowPotEnemy::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();

	
}

void ThrowPotEnemy::Update(float DeltaTime)
{
	PlaySoundOnState();

	this->mState.at(mCurrentState)->Update(mTime);

	switch (mCurrentState)
	{
	case ThrowPotEnemyState::ThrowPotEnemy_ThrowingPot:
		if (this->mState.at(mCurrentState)->GetCurrentIdx() == 5 && this->mState.at(mCurrentState)->isNextFrame == true)
		{
			SceneManager::GetInstance()->GetCurrentScene()->AddFlyingObject(new ThrowPot(D3DXVECTOR3(this->mState.at(mCurrentState)->GetPosition().x + 25, this->mState.at(mCurrentState)->GetPosition().y, 0)));
		}
		break;
	case ThrowPotEnemyState::ThrowPotEnemy_Explosion:
		this->mPosition = this->mState.at(mCurrentState)->GetPosition();

		if (this->mState.at(mCurrentState)->isDone())
		{
			mDone = true;
		}
		break;
	}
}

void ThrowPotEnemy::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::THROWINGAPPLE:
		if (this->mCurrentState == ThrowPotEnemyState::ThrowPotEnemy_ThrowingPot)
		{
			this->mState.at(ThrowPotEnemyState::ThrowPotEnemy_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = ThrowPotEnemyState::ThrowPotEnemy_Explosion;
			
		}
		break;

	}
}

void ThrowPotEnemy::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
	switch (obj->GetID())
	{
	case EObjectID::LAMP:
		if (((Lamp*)obj)->GetCollisioned() && this->GetBoundingBox().Intersects(obj->GetInteractBoundingBox()))
		{
			this->mState.at(ThrowPotEnemyState::ThrowPotEnemy_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = ThrowPotEnemyState::ThrowPotEnemy_Explosion;
			this->mWidth = 0;
			this->mHeight = 0;
		}
		break;
	case EObjectID::ALADDIN:
		if (collisionWith == CollisionWith::InteractBoundingBox)
		{
			if (this->mCurrentState == ThrowPotEnemyState::ThrowPotEnemy_Explosion)
				return;

			if (AABBresult == true)
			{
				this->mCurrentState = ThrowPotEnemyState::ThrowPotEnemy_ThrowingPot;
			}
			else
			{
				if (this->mCurrentState == ThrowPotEnemyState::ThrowPotEnemy_ThrowingPot && this->mState.at(mCurrentState)->isDone())
					this->mCurrentState = ThrowPotEnemyState::ThrowPotEnemy_DoNothing;

			}
		}
		else if (collisionWith == CollisionWith::SwordBoundingBox)
		{
			if (!AABBresult)
				return;

			if (this->mCurrentState == ThrowPotEnemyState::ThrowPotEnemy_ThrowingPot)
			{
				this->mState.at(ThrowPotEnemyState::ThrowPotEnemy_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
				mCurrentState = ThrowPotEnemyState::ThrowPotEnemy_Explosion;
			}

		}
	}
}

bool ThrowPotEnemy::isDone()
{
	return mDone;
}

ThrowPotEnemyState ThrowPotEnemy::GetCurrentStateID()
{
	return mCurrentState;
}

void ThrowPotEnemy::PlaySoundOnState()
{
	if (!mState.at(mCurrentState)->isNextFrame)
		return;

	switch (mCurrentState)
	{
	case ThrowPotEnemyState::ThrowPotEnemy_Explosion:
		switch (mState.at(mCurrentState)->GetCurrentIdx())
		{
		case 0:
			SoundHelper::GetInstance()->Play("Explosion", false, 1);

			break;
		}
		break;

	}
}
