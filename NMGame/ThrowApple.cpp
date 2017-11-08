#include "ThrowApple.h"

ThrowingApple::ThrowingApple()
{
}

ThrowingApple::ThrowingApple(D3DXVECTOR3 pos, Direction dir)
{
	this->mPosition = pos;
	this->mTime = 0;
	this->mDone = 0;

	this->mDir = dir;

	vector<MyRECT> temp;

	temp.push_back(MyRECT(0, 18, 25, 7));
	temp.push_back(MyRECT(0, 0, 9, 7));
	temp.push_back(MyRECT(0, 10, 17, 8));
	temp.push_back(MyRECT(8, 0, 9, 14));

	this->mState = new ObjectStateWithLoop(temp, 18, L"Object\\ThrowingApple.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom);
	this->mState->SetPosition(pos);
}

ThrowingApple::~ThrowingApple()
{ 
}

void ThrowingApple::Update(float DeltaTime)
{

	this->mState->Update(mTime);
	mTime += DeltaTime/10;


	this->mState->SetVelocity(((mDir == Direction::Left) ? (1.0f) : (-1.0f)) * 0.5, 0.5);
	this->mState->SetAcceleration(((mDir == Direction::Left) ? (1.0f) : (-1.0f)) * 0.03, -0.045);

	if (this->mState->GetPosition().y <  WORLD_Y - MAP_HEIGHT + 90)
	{
		mDone = true;
		//this->mState->SetPosition(D3DXVECTOR3(100.0f, WORLD_Y - MAP_HEIGHT + 90, 0));
	}

	this->mPosition = this->mState->GetPosition();
	this->mState->mSprite->SetPosition(mPosition);
}

void ThrowingApple::Render(float DeltaTime) 
{
	this->mState->Render();
}

bool ThrowingApple::isDone()
{
	return mDone;
}
