#include "AladdinCharacter.h"

AladdinCharacter::AladdinCharacter()
{
	this->mPosition = D3DXVECTOR3(0, 0, 0);
	this->mVelocity = D3DXVECTOR2(0, 0);
	
}

AladdinCharacter::AladdinCharacter(LPD3DXSPRITE SpriteHandle)
{
	this->mSpriteHandle = SpriteHandle;
	this->mPosition = D3DXVECTOR3(0, 0, 0);
	this->mVelocity = D3DXVECTOR2(0, 0);
	
}

AladdinCharacter::AladdinCharacter(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position)
{
	this->mSpriteHandle = SpriteHandle;
	this->mPosition = D3DXVECTOR3(0, 0, 0);
	this->mVelocity = D3DXVECTOR2(0, 0);
	this->SetPosition(Position);
}

AladdinCharacter::AladdinCharacter(LPD3DXSPRITE SpriteHandle, int X, int Y)
{
	this->mSpriteHandle = SpriteHandle;
	this->mPosition = D3DXVECTOR3(0, 0, 0);
	this->mVelocity = D3DXVECTOR2(0, 0);
	this->SetPosition(X, Y);
}

AladdinCharacter::~AladdinCharacter()
{
	if (this->mSprite)
		delete(this->mSprite);
}

void AladdinCharacter::Draw()
{
	this->mSprite->Render();
}

void AladdinCharacter::Animate()
{
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		//if (kitty_vx > 0) this->mSprite->Next();
		if (this->GetVelocity().x > 0) { this->mSprite->FlipVertical(false); this->nextFrame(); }
		else if (this->GetVelocity().x < 0) { this->mSprite->FlipVertical(true);  this->nextFrame(); }
		last_time = now;
	}
}

void AladdinCharacter::Move(int delta_time)
{
	SetPosition(mSprite->GetPosition().x + this->GetVelocity().x * delta_time, mSprite->GetPosition().y + this->GetVelocity().y * delta_time);
}

void AladdinCharacter::nextFrame()
{
	//this->mSprite->Next();
	mCurrentIdx = (mCurrentIdx + mEndIdx - 1) % mEndIdx;
	this->mSprite->SetFrame(mCurrentIdx);
}

void AladdinCharacter::resetFrame()
{
	this->mSprite->Reset();
	this->mSprite->SetFrame(0);
}

D3DXVECTOR3 AladdinCharacter::GetPosition()
{
	return this->mPosition;
}

D3DXVECTOR2 AladdinCharacter::GetVelocity()
{
	return this->mVelocity;
}

void AladdinCharacter::SetVelocity(D3DXVECTOR2 Velocity)
{
	this->mVelocity = Velocity;
}

void AladdinCharacter::SetVelocity(float X, float Y)
{
	this->mVelocity.x = X;
	this->mVelocity.y = Y;
}



void AladdinCharacter::SetPosition(D3DXVECTOR3 Position)
{
	this->mPosition = Position;
	this->mSprite->SetPosition(this->mPosition);
}

void AladdinCharacter::SetPosition(int X, int Y)
{
	this->mPosition.x = X;
	this->mPosition.y = Y;
	this->mSprite->SetPosition(this->mPosition);
}
