#include "HalfApple.h"

HalfApple::HalfApple()
{
	this->mID = EObjectID::APPLE;

	this->mCanBeHitByFlyingObject = false;

	mWidth = 30;
	mHeight = 30;
}

HalfApple::HalfApple(D3DXVECTOR3 pos, Direction dir, float vy) : HalfApple()
{
	mDir = dir;
	this->mPosition = pos;

	this->mCurrentState = HalfAppleState::HalfState_Explosion;

	std::vector<MyRECT> temp;

	temp.push_back(MyRECT(25, 0, 20, 45));
	temp.push_back(MyRECT(0, 37, 57, 24));
	temp.push_back(MyRECT(0, 0, 36, 24));
	this->mState.push_back(new ObjectState(temp, 16, L"Object\\HalfApple\\Explosion.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	temp.push_back(MyRECT(0, 15, 28, 10));
	temp.push_back(MyRECT(0, 0, 14, 5));
	temp.push_back(MyRECT(12, 0, 13, 22));
	temp.push_back(MyRECT(6, 0, 14, 11));

	this->mState.push_back(new ObjectState(temp, 14, L"Object\\HalfApple\\Normal.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));


	this->mState.at(0)->SetPosition(pos);
	this->mState.at(1)->SetPosition(pos);
	temp.clear();

	this->mVelocity = D3DXVECTOR2(((mDir == Direction::Right) ? (1.0f) : (-1.0f)) * vy, 0.1);
}

HalfApple::~HalfApple()
{
}

void HalfApple::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

void HalfApple::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	switch (mCurrentState)
	{
	case HalfAppleState::HalfState_Explosion:
		if (this->mState.at(mCurrentState)->isDone())
		{
			this->mCurrentState = HalfAppleState::HalfState_Normal;
		}
		break;
	case HalfAppleState::HalfState_Normal:
		this->mState.at(mCurrentState)->SetVelocity(this->mVelocity.x, this->mState.at(mCurrentState)->GetVelocity().y - 0.032);

		if (this->mState.at(mCurrentState)->GetPosition().y <= -5)
			mDone = true;
	}
}

ObjectState * HalfApple::GetCurrentState()
{
	return this->mState.at(mCurrentState);
}

void HalfApple::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
}

bool HalfApple::isDone()
{
	return this->mDone;
}
