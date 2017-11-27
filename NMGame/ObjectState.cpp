#include "ObjectState.h"

ObjectState::ObjectState(std::vector<MyRECT> rect, int Animate_rate, LPWSTR filePath, D3DXVECTOR2 velocity, CenterArchor center)
{
	this->mVelocity = this->mDefaultVelocity = velocity;
	this->ResetFlag = true;
	this->mIsFlipVertical = false;
	this->ANIMATE_RATE = Animate_rate;

	this->mCurrentIdx = 0;

	this->mEndIdx = rect.size();

	this->mSprite = new Sprite(filePath, D3DCOLOR_XRGB(255, 0, 255), rect, center);

	this->mAcceleration = D3DXVECTOR2(0, 0);

	isNextFrame = false;
}

ObjectState::ObjectState(std::vector<MyRECT> rect, int Animate_rate, LPWSTR filePath, D3DXVECTOR2 velocity, D3DXVECTOR2 acceleration, CenterArchor center)
{
	this->mVelocity = this->mDefaultVelocity = velocity;
	this->ResetFlag = true;
	this->mIsFlipVertical = false;
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



void ObjectState::OpacityRender(DWORD AlphaValue)
{
	this->mSprite->Render(AlphaValue);
}

void ObjectState::Update(float DeltaTime)
{
	
	this->Animate(DeltaTime);


	if (this->GetVelocity() == D3DXVECTOR2(0, 0))
	{
		this->mSprite->SetPosition(mPosition);
		return;
	}
	else
	{
		this->Move(DeltaTime);
		
	}
		
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

void ObjectState::InverseAnimate(float DeltaTime)
{
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		if (this->ResetFlag)
		{
			this->mSprite->SetFrame(mCurrentIdx);
			ResetFlag = false;
			return;
		}
		else
		{
			if (mCurrentIdx >= 0)
			{
				mCurrentIdx -= 1;
			}

			if (mCurrentIdx == -1)
				mCurrentIdx = mEndIdx - 1;
		}
		if (mCurrentIdx < mEndIdx)
			this->mSprite->SetFrame(mCurrentIdx);
	

		isNextFrame = true;

		last_time = now;
	}
	else
		isNextFrame = false;
}

void ObjectState::Move(float delta_time)
{

	SetPosition(this->GetPosition().x + (mVelocity.x * delta_time  ) , this->GetPosition().y + GetVelocity().y * delta_time  );
	this->mSprite->SetPosition(mPosition);
}

void ObjectState::MoveVertical(float delta_time, Direction dirVer)
{
	SetPosition(this->GetPosition().x + (mVelocity.x * delta_time),  this->GetPosition().y + ((dirVer == Up) ? (1) : (-1)) * GetVelocity().y * delta_time );
	this->mSprite->SetPosition(mPosition);
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

void ObjectState::GoToFrame(int idx)
{
	ResetFlag = false;
	this->mSprite->SetFrame(idx);
	this->mCurrentIdx = idx;
}

void ObjectState::GoToLastFrameIdx()
{
	this->mCurrentIdx = this->mEndIdx - 1;
	this->mSprite->SetFrame(this->mEndIdx - 1);
}

D3DXVECTOR2 ObjectState::GetVelocity()
{
	/*if(this->mIsFlipVertical == false)
		 return D3DXVECTOR2(this->mVelocity.x  , this->mVelocity.y); 
	else
		return D3DXVECTOR2(-this->mVelocity.x, this->mVelocity.y);*/

	if (mIsFlipVertical == true && this->mVelocity.x > 0)
		return D3DXVECTOR2(-this->mVelocity.x, this->mVelocity.y);
	else if (mIsFlipVertical == false && this->mVelocity.x < 0)
		return D3DXVECTOR2(-this->mVelocity.x, this->mVelocity.y);

	return this->mVelocity;
}

void ObjectState::SetVelocity(float X, float Y)
{
	 this->mVelocity.x = X; this->mVelocity.y = Y; 

	 //if (mIsFlipVertical == true && this->mVelocity.x > 0)
		// this->mVelocity = D3DXVECTOR2(-this->mVelocity.x, this->mVelocity.y);
	 //else if (mIsFlipVertical == false && this->mVelocity.x < 0)
		// this->mVelocity =  D3DXVECTOR2(-this->mVelocity.x, this->mVelocity.y);
}



void ObjectState::ResetDefaultVelocity()
{
	this->mVelocity = mDefaultVelocity;
	return ;
}

void ObjectState::SetFlipVertical(bool flipV)
{
	this->mIsFlipVertical = flipV;
	if (this->mIsFlipVertical != this->mSprite->IsFlipVertical())
		this->mSprite->FlipVertical(this->mIsFlipVertical);

	if (flipV == true && this->mVelocity.x > 0)
		this->mVelocity.x = -this->mVelocity.x;
	else if (flipV == false && this->mVelocity.x < 0)
		this->mVelocity.x = -this->mVelocity.x;
}

bool ObjectState::GetIsNextFrame()
{
	return isNextFrame;
}

MyRECT ObjectState::GetCurrentFrameBoundingBox()
{
	return mSprite->GetCurrentFrameBoundingBox();
}
