//#include "AladdinState.h"
//
//AladdinState::AladdinState()
//{
//	this->mPosition = D3DXVECTOR3(0, 0, 0);
//	this->mVelocity = D3DXVECTOR2(0, 0);
//	this->ResetFlag = true;
//}
//
//AladdinState::AladdinState(LPD3DXSPRITE SpriteHandle)
//{
//	this->mSpriteHandle = SpriteHandle;
//	this->mPosition = D3DXVECTOR3(0, 0, 0);
//	this->mVelocity = D3DXVECTOR2(0, 0);
//	this->ResetFlag = true;
//}
//
//AladdinState::AladdinState(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position)
//{
//	this->mSpriteHandle = SpriteHandle;
//	this->mPosition = D3DXVECTOR3(0, 0, 0);
//	this->mVelocity = D3DXVECTOR2(0, 0);
//	this->SetPosition(Position);
//	this->ResetFlag = true;
//}
//
//AladdinState::AladdinState(LPD3DXSPRITE SpriteHandle, int X, int Y)
//{
//	this->mSpriteHandle = SpriteHandle;
//	this->mPosition = D3DXVECTOR3(0, 0, 0);
//	this->mVelocity = D3DXVECTOR2(0, 0);
//	this->SetPosition(X, Y);
//	this->ResetFlag = true;
//}
//
//AladdinState::~AladdinState()
//{
//	if (this->mSprite)
//		delete(this->mSprite);
//}
//
//void AladdinState::Render()
//{
//	this->mSprite->Render();
//}
//
//void AladdinState::Update(float DeltaTime)
//{
//}
//
//
//void AladdinState::Animate(float DeltaTime)
//{
//
//	DWORD now = GetTickCount();
//	if (now - last_time > 1000 / ANIMATE_RATE)
//	{
//		if (this->GetVelocity().x != 0)
//			this->nextFrame();
//
//		last_time = now;
//	}
//}
//
//void AladdinState::Move(float delta_time)
//{
//	SetPosition(mSprite->GetPosition().x + this->GetVelocity().x * delta_time, mSprite->GetPosition().y + this->GetVelocity().y * delta_time);
//}
//
//void AladdinState::nextFrame()
//{
//	if (this->ResetFlag)
//	{
//		ResetFlag = false;
//		return;
//	}
//
//	mCurrentIdx = (mCurrentIdx + mEndIdx - 1) % mEndIdx;
//	this->mSprite->SetFrame(mCurrentIdx);
//}
//
//void AladdinState::nextFrameWithoutLoop()
//{
//	if (this->ResetFlag)
//	{
//		this->mSprite->SetFrame(mCurrentIdx);
//		ResetFlag = false;
//	}
//	else
//	{
//		if (mCurrentIdx < mEndIdx)
//		{
//			mCurrentIdx += 1;
//			
//		}
//	}	
//	if (mCurrentIdx < mEndIdx)
//		this->mSprite->SetFrame(mCurrentIdx);
//}
//
//void AladdinState::resetFrame()
//{
//	mCurrentIdx = 0;
//	this->mSprite->SetFrame(0);
//	this->ResetFlag = true;
//}
//
//D3DXVECTOR3 AladdinState::GetPosition()
//{
//	return this->mPosition;
//}
//
//D3DXVECTOR2 AladdinState::GetVelocity()
//{
//	return this->mVelocity;
//}
//
//void AladdinState::SetVelocity(D3DXVECTOR2 Velocity)
//{
//	this->mVelocity = Velocity;
//}
//
//void AladdinState::SetVelocity(float X, float Y)
//{
//	this->mVelocity.x = X;
//	this->mVelocity.y = Y;
//}
//
//bool AladdinState::GetFlipVertical()
//{
//	return this->mIsFlipVertical;
//}
//
//void AladdinState::SetFlipVertical(bool flipV)
//{
//	this->mIsFlipVertical = flipV;
//
//	if (this->mIsFlipVertical != this->mSprite->IsFlipVertical())
//		this->mSprite->FlipVertical(this->mIsFlipVertical);
//}
//
//int AladdinState::GetCurrentIdx()
//{
//	return this->mCurrentIdx;
//}
//
//int AladdinState::GetEndIdx()
//{
//	return this->mEndIdx;
//}
//
//bool AladdinState::isDone()
//{
//	if (this->mCurrentIdx == this->mEndIdx)
//		return true;
//
//	return false;
//}
//
//void AladdinState::GoToLastFrameIdx()
//{
//	this->mCurrentIdx = this->mEndIdx - 1;
//	this->mSprite->SetFrame(this->mEndIdx - 1);
//}
//
//
//
//void AladdinState::SetPosition(D3DXVECTOR3 Position)
//{
//	this->mPosition = Position;
//	this->mSprite->SetPosition(this->mPosition);
//}
//
//void AladdinState::SetPosition(int X, int Y)
//{
//	this->mPosition.x = X;
//	this->mPosition.y = Y;
//	this->mSprite->SetPosition(this->mPosition);
//}
