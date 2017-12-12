#include "JafarBullet.h"

JafarBullet::JafarBullet(D3DXVECTOR3 pos, AladdinCharacter* ala)
{
	this->mAladdin = ala;

	mCollisioned = false;

	this->mID = EObjectID::JAFAR_BULLET;

	this->mCanAttack = true;
	this->mPosition = pos;
	this->mTime = 0;
	this->mDone = 0;
	this->mCurrentState = JafarBulletState::JafarBulletState_Normal;

	this->mInteractBoundingBox = MyRECT(0, 0, 0, 0);
	this->mBoundingBox = MyRECT(0, 0, 0, 0);

	mWidth = 1;
	mHeight = 1;

	vector<MyRECT> temp;

	temp.push_back(MyRECT(0, 0, 28, 14));
	temp.push_back(MyRECT(0, 29, 53, 16));
	temp.push_back(MyRECT(15, 0, 26, 30));

	this->mState.push_back(new ObjectStateWithLoop(temp, 18, L"Object\\Boss\\JafarBullet.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	this->mState.at(0)->SetPosition(pos);
	temp.clear();

	temp.push_back(MyRECT(15, 0, 14, 28));
	temp.push_back(MyRECT(0, 0, 35, 14, D3DXVECTOR3(0,5,0)));
	temp.push_back(MyRECT(0, 36, 51, 2, D3DXVECTOR3(0, 10, 0)));

	this->mState.push_back(new ObjectState(temp, 13, L"Object\\Boss\\Explosion.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	//this->mState->SetPosition(pos);
	temp.clear();

	//this->mVelocity = D3DXVECTOR2(((mDir == Direction::Right) ? (1.0f) : (-1.0f)) * 1, 0.1);
	this->mState.at(mCurrentState)->SetVelocity(this->mVelocity);
}

JafarBullet::~JafarBullet()
{
}

void JafarBullet::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	this->mState.at(mCurrentState)->SetFlipVertical(((mDir == Direction::Right) ? (false) : (true)));

	if (this->mAladdin->GetBoundingBox().Intersects(this->GetBoundingBox()))
	{
		mCollisioned = true;
	}

	switch (mCurrentState)
	{
	case ThrowingAppleState::Normal:
		if (!mCollisioned)
		{
			if (mAladdin->GetCurrentState()->GetPosition().x < this->mState.at(mCurrentState)->GetPosition().x)
			{
				this->mDir = Direction::Left;

				if (mAladdin->GetCurrentState()->GetPosition().y < this->mState.at(mCurrentState)->GetPosition().y)
				{
					this->mState.at(mCurrentState)->SetVelocity(-DEFAULT_JARFARBULLET_VELOCITY, -DEFAULT_JARFARBULLET_VELOCITY);

					
				}
				else
				{
					this->mState.at(mCurrentState)->SetVelocity(-DEFAULT_JARFARBULLET_VELOCITY, DEFAULT_JARFARBULLET_VELOCITY);
				}
			//	this->mState.at(mCurrentState)->SetVelocity(, this->mState.at(mCurrentState)->GetVelocity().y);
			}
			else
			{
				this->mDir = Direction::Right;

				if (mAladdin->GetCurrentState()->GetPosition().y < this->mState.at(mCurrentState)->GetPosition().y)
				{
					this->mState.at(mCurrentState)->SetVelocity(DEFAULT_JARFARBULLET_VELOCITY, -DEFAULT_JARFARBULLET_VELOCITY);
				}
				else
				{
					this->mState.at(mCurrentState)->SetVelocity(DEFAULT_JARFARBULLET_VELOCITY, DEFAULT_JARFARBULLET_VELOCITY);
				}
			}

			
			//this->mState.at(mCurrentState)->SetVelocity(this->mVelocity.x, this->mState.at(mCurrentState)->GetVelocity().y - 0.032);
			//this->mVelocity = this->mState.at(mCurrentState)->GetVelocity();
		}
		else
		{
			this->mState.at(mCurrentState)->SetVelocity(0, 0);
			mCurrentState = JafarBulletState::JafarBulletState_Explosion;
			this->mState.at(mCurrentState)->SetPosition(this->mPosition);
		}


		break;


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
}

void JafarBullet::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

ObjectState * JafarBullet::GetCurrentState()
{
	return this->mState.at(mCurrentState);
}

bool JafarBullet::isDone()
{
	return this->mDone;
}

void JafarBullet::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::ALADDIN:

		this->mState.at(mCurrentState)->SetVelocity(this->mState.at(mCurrentState)->GetVelocity().x * collision.EntryTime, this->mState.at(mCurrentState)->GetVelocity().y * collision.EntryTime);

		mCollisioned = true;
		break;
	}
}

JafarBulletState JafarBullet::GetCurrentStateID()
{
	return this->mCurrentState;
}
