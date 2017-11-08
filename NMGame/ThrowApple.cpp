#include "ThrowApple.h"

ThrowingApple::ThrowingApple()
{
}

ThrowingApple::ThrowingApple(D3DXVECTOR3 pos, Direction dir)
{
	this->mPosition = pos;
	this->mTime = 0;
	this->mDone = 0;
	this->mCurrentState = ThrowingAppleState::Normal;

	this->mDir = dir;

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

}

ThrowingApple::~ThrowingApple()
{ 
}

void ThrowingApple::Update(float DeltaTime)
{
	switch (mCurrentState)
	{
	case ThrowingAppleState::Normal:
		this->mState.at(mCurrentState)->Update(mTime);
		mTime += DeltaTime / 15;


		this->mState.at(mCurrentState)->SetVelocity(((mDir == Direction::Left) ? (1.0f) : (-1.0f)) * 1.2, 0.5);
		this->mState.at(mCurrentState)->SetAcceleration(((mDir == Direction::Left) ? (1.0f) : (-1.0f)) * 0, -0.07);

		if (this->mState.at(mCurrentState)->GetPosition().y < WORLD_Y - MAP_HEIGHT + 90)
		{
			this->mCurrentState = ThrowingAppleState::Explosion;
			this->mState.at(mCurrentState)->SetPosition(this->mState.at(0)->GetPosition());

			//mDone = true;
			//this->mState->SetPosition(D3DXVECTOR3(100.0f, WORLD_Y - MAP_HEIGHT + 90, 0));
		}

		this->mPosition = this->mState.at(mCurrentState)->GetPosition();
		this->mState.at(mCurrentState)->mSprite->SetPosition(mPosition);
		break;
	case ThrowingAppleState::Explosion:
	{
		this->mState.at(mCurrentState)->Update(DeltaTime);

		if (this->mState.at(mCurrentState)->isDone())
		{
			mDone = true;
		}

		break;
	}

	}
}

void ThrowingApple::Render(float DeltaTime) 
{
	this->mState.at(mCurrentState)->Render();
}

bool ThrowingApple::isDone()
{
	return mDone;
}
