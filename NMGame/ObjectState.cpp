#include "ObjectState.h"

ObjectState::ObjectState(std::vector<MyRECT> rect, int Animate_rate, LPWSTR filePath, D3DXVECTOR2 velocity, CenterArchor center)
{
	this->mVelocity = velocity;
	this->ResetFlag = true;

	this->ANIMATE_RATE = Animate_rate;

	this->mCurrentIdx = 0;

	this->mEndIdx = rect.size();

	this->mSprite = new Sprite(filePath, D3DCOLOR_XRGB(255, 0, 255), rect, center);

	this->mAcceleration = D3DXVECTOR2(0, 0);

	isNextFrame = false;
}

ObjectState::ObjectState(std::vector<MyRECT> rect, int Animate_rate, LPWSTR filePath, D3DXVECTOR2 velocity, D3DXVECTOR2 acceleration, CenterArchor center)
{
	this->mVelocity = velocity;
	this->ResetFlag = true;

	this->ANIMATE_RATE = Animate_rate;

	this->mCurrentIdx = 0;

	this->mEndIdx = rect.size();

	this->mSprite = new Sprite(filePath, D3DCOLOR_XRGB(255, 0, 255), rect, center);

	this->mAcceleration = acceleration;

	isNextFrame = false;
}

ObjectState::~ObjectState()
{
}

void ObjectState::Render()
{
	this->mSprite->Render();
}

void ObjectState::Update(float DeltaTime)
{
	this->Animate(DeltaTime);


	if (this->GetVelocity() == D3DXVECTOR2(0, 0))
		return;

	
	this->Move(DeltaTime);
}

void ObjectState::Animate(float DeltaTime)
{
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{	
			this->nextFrame();
			isNextFrame = true;

		last_time = now;
	}
	else
		isNextFrame = false;
}

void ObjectState::Move(float delta_time)
{

	SetPosition(this->GetPosition().x + ((GetFlipVertical() == false) ? (1.0f) : (-1.0f))* ( this->GetVelocity().x * delta_time + 0.5 *  this->mAcceleration.x * pow(delta_time,2)), this->GetPosition().y + this->GetVelocity().y * delta_time + 0.5 *  this->mAcceleration.y * pow(delta_time, 2));

}

void ObjectState::nextFrame()
{
	if (this->ResetFlag)
	{
		this->mSprite->SetFrame(mCurrentIdx);
		ResetFlag = false;
		return;
	}
	else
	{
		if (mCurrentIdx < mEndIdx)
		{
			mCurrentIdx += 1;

		}
	}
	if (mCurrentIdx < mEndIdx)
		this->mSprite->SetFrame(mCurrentIdx);
}

bool ObjectState::isDone()
{
	if (this->mCurrentIdx == this->mEndIdx)
		return true;

	return false;
}

void ObjectState::resetFrame()
{
	mCurrentIdx = 0;
	this->mSprite->SetFrame(0);
	this->ResetFlag = true;
}

void ObjectState::GoToLastFrameIdx()
{
	this->mCurrentIdx = this->mEndIdx - 1;
	this->mSprite->SetFrame(this->mEndIdx - 1);
}

bool ObjectState::GetIsNextFrame()
{
	return isNextFrame;
}
