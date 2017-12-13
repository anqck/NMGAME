#include "Enemy3.h"
#include "Lamp.h"
#include "SoundHelper.h"
Enemy3::Enemy3() : Enemy::Enemy()
{
	this->mCanBeAttack = true;
	this->mCanBeHitByFlyingObject = true;
	this->mInteractWithInteractBB = true;
	this->mCanBeHitByFlyingObject = true;
	this->mCanAttack = false;

	mLastAladdinPosInInteractBox = D3DXVECTOR3(0, 0, 0);

	this->mID = EObjectID::ENEMY3;

	this->mDone = false;

	this->mCurrentState = Enemy3State::Eneymy3State_Normal;

	mWidth = 10;
	mHeight = 140;

	this->mHP = 2;
}

Enemy3::Enemy3(MyRECT bb, D3DXVECTOR3 pos) : Enemy3::Enemy3()
{
	this->mBoundingBox = MyRECT(0, 0, 0, 0);
	this->mInteractBoundingBox = bb;

	this->mCurrentState = Enemy3State::Eneymy3State_Normal;

	this->mPosition = this->mDefaultPosition = pos;
	

	vector<MyRECT> temp;

	//Normal
	temp.push_back(MyRECT(83, 108, 156, 164));
	temp.push_back(MyRECT(81, 157, 204, 167,D3DXVECTOR3(-2,0,0)));
	temp.push_back(MyRECT(165, 102, 141, 247));
	temp.push_back(MyRECT(83, 56, 107, 161));
	temp.push_back(MyRECT(0, 0, 64, 78, D3DXVECTOR3(5, 0, 0)));
	temp.push_back(MyRECT(79, 0, 55, 147, D3DXVECTOR3(3, 0, 0)));
	temp.push_back(MyRECT(0, 191, 247, 80, D3DXVECTOR3(-4, 0, 0)));
	temp.push_back(MyRECT(148, 0, 52, 235, D3DXVECTOR3(-4, 0, 0)));
	temp.push_back(MyRECT(0, 65, 128, 82, D3DXVECTOR3(13, 0, 0)));
	temp.push_back(MyRECT(162, 53, 101, 241, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(0, 129, 190, 78, D3DXVECTOR3(6, 0, 0)));

	this->mState.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\Enemy\\\\Enemy3\\Normal.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

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

Enemy3::~Enemy3()
{
}

void Enemy3::ResetDefault()
{
	mLastAladdinPosInInteractBox = D3DXVECTOR3(0, 0, 0);


	this->mDone = false;

	this->mCurrentState = Enemy3State::Eneymy3State_Normal;
	this->mPosition = mDefaultPosition;

	this->mState.at(mCurrentState)->SetPosition(mDefaultPosition);

	mLastAladdinPosInInteractBox = D3DXVECTOR3(0, 0, 0);

	mWidth = 10;
	mHeight = 140;

	this->mHP = 2;

	mCollision = false;

	this->mState.at(Enemy3State::Enemy3State_Explosion)->resetFrame();
}

void Enemy3::Update(float DeltaTime)
{
	PlaySoundOnState();

	this->mState.at(mCurrentState)->Update(DeltaTime);

	if (mLastAladdinPosInInteractBox.x <= this->mPosition.x)
		this->mDir = Direction::Left;
	else
		this->mDir = Direction::Right;

	this->mState.at(mCurrentState)->SetFlipVertical(((mDir == Direction::Right) ? (false) : (true)));

	switch (mCurrentState)
	{
	case Enemy3State::Eneymy3State_Normal:
		if (this->mState.at(mCurrentState)->GetCurrentIdx() == 1 && this->mState.at(mCurrentState)->isNextFrame == true && mCollision)
		{
			if (this->mLastAladdinPosInInteractBox.x <= this->mPosition.x - 200 && this->mDir == Direction::Left || this->mLastAladdinPosInInteractBox.x >= this->mPosition.x + 200 && this->mDir == Direction::Right )
				SceneManager::GetInstance()->GetCurrentScene()->AddFlyingObject(new FlyingKnife(D3DXVECTOR3(this->mState.at(mCurrentState)->GetPosition().x + ((this->mDir == Direction::Right) ? 1 : -1) * 32, this->mState.at(mCurrentState)->GetPosition().y + 95, 0), this->mDir, D3DXVECTOR2(((mDir == Direction::Right) ? (1.0f) : (-1.0f)) * 0.3, 1.1),D3DXVECTOR2(0,-0.04)));
			else
				SceneManager::GetInstance()->GetCurrentScene()->AddFlyingObject(new FlyingKnife(D3DXVECTOR3(this->mState.at(mCurrentState)->GetPosition().x + ((this->mDir == Direction::Right) ? 1 : -1) * 32, this->mState.at(mCurrentState)->GetPosition().y + 25, 0), this->mDir, D3DXVECTOR2(((mDir == Direction::Right) ? (1.0f) : (-1.0f)) * 1.1, 0.8), D3DXVECTOR2(0, -0.18)));
			
		}
		break;
	case Enemy3State::Enemy3State_Explosion:
		if (this->mState.at(mCurrentState)->isDone())
		{

			mDone = true;
		}
		break;
	}
}

void Enemy3::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

void Enemy3::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
	switch (obj->GetID())
	{
	case EObjectID::LAMP:
		if (((Lamp*)obj)->GetCollisioned() && this->GetBoundingBox().Intersects(obj->GetInteractBoundingBox()))
		{
			this->mState.at(Enemy3State::Enemy3State_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy3State::Enemy3State_Explosion;
			this->mWidth = 0;
			this->mHeight = 0;
		}
		break;
	case EObjectID::ALADDIN:
		if (AABBresult == true)
		{
			mLastAladdinPosInInteractBox = obj->GetCurrentState()->GetPosition();
			mCollision = true;
		}
		else
			mCollision = false;

		if ((collisionWith == CollisionWith::InteractBoundingBox))
		{
			/*switch (mCurrentState)
			{
			case Enemy3State::Eneymy3State_Normal:
				if (this->mState.at(mCurrentState)->GetCurrentIdx() == 1 && this->mState.at(mCurrentState)->isNextFrame == true)
				{
					if (this->mLastAladdinPosInInteractBox.x <= this->mPosition.x - 200 && this->mDir == Direction::Left || this->mLastAladdinPosInInteractBox.x >= this->mPosition.x + 200 && this->mDir == Direction::Right)
						SceneManager::GetInstance()->GetCurrentScene()->AddFlyingObject(new FlyingKnife(D3DXVECTOR3(this->mState.at(mCurrentState)->GetPosition().x + ((this->mDir == Direction::Right) ? 1 : -1) * 32, this->mState.at(mCurrentState)->GetPosition().y + 95, 0), this->mDir, D3DXVECTOR2(((mDir == Direction::Right) ? (1.0f) : (-1.0f)) * 0.3, 1.1), D3DXVECTOR2(0, -0.04)));
					else
						SceneManager::GetInstance()->GetCurrentScene()->AddFlyingObject(new FlyingKnife(D3DXVECTOR3(this->mState.at(mCurrentState)->GetPosition().x + ((this->mDir == Direction::Right) ? 1 : -1) * 32, this->mState.at(mCurrentState)->GetPosition().y + 25, 0), this->mDir, D3DXVECTOR2(((mDir == Direction::Right) ? (1.0f) : (-1.0f)) * 1.1, 0.8), D3DXVECTOR2(0, -0.18)));

				}
				break;
			}*/
		}
		else if ((collisionWith == CollisionWith::SwordBoundingBox))
		{
			if (!AABBresult)
				return;

			switch (mCurrentState)
			{
			default:

				this->mState.at(Enemy3State::Enemy3State_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
				mCurrentState = Enemy3State::Enemy3State_Explosion;
				this->mWidth = 0;
				this->mHeight = 0;
			}
			}
	}
}

void Enemy3::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::THROWINGKNIFE:
	case EObjectID::THROWINGAPPLE:
		if (this->mHP >= 2)
		{
			this->mHP--;

			//this->mState.at(Eneymy3State::Eneymy3State_Normal)->resetFrame();
			//this->mState.at(Eneymy3State::Eneymy1State_Damage)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			//mCurrentState = Eneymy3State::Eneymy1State_Damage;
		}
		else if (this->mHP == 1)
		{
			this->mState.at(Enemy3State::Enemy3State_Explosion)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			mCurrentState = Enemy3State::Enemy3State_Explosion;

			this->mWidth = 0;
			this->mHeight = 0;

		}

	}
}

void Enemy3::PlaySoundOnState()
{
	if (!mState.at(mCurrentState)->isNextFrame)
		return;

	switch (mCurrentState)
	{
	case Enemy3State::Eneymy3State_Normal:
		switch (mState.at(mCurrentState)->GetCurrentIdx())
		{
		case 1:
				SoundHelper::GetInstance()->Play("Enemy_Throw", false, 1);

			break;
		}
		break;
	case Enemy3State::Enemy3State_Explosion:
		switch (mState.at(mCurrentState)->GetCurrentIdx())
		{
		case 1:
			SoundHelper::GetInstance()->Play("Explosion", false, 1);
			break;
		}
		break;
	}
}
