#include "AladdinHelper.h"

AladdinHelper::AladdinHelper(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3	pos)
{
	this->_mAladdinWalk = new AladdinWalk(SpriteHandle);

	this->mState = AladdinState::DoNothing;

	this->mAladdin = _mAladdinWalk;
	this->mAladdin->SetPosition(pos);
	this->mSpriteHandler = SpriteHandle;

	
}

void AladdinHelper::setAladdinState(AladdinState state)
{
	this->mState = state;
}

void AladdinHelper::setDirection(Direction dir)
{
	mDir = dir;
}

void AladdinHelper::Render(int DeltaTime)
{
	switch (this->mState)
	{
	case AladdinState::DoNothing:
	{
		this->mAladdin = _mAladdinWalk;
		this->mAladdin->resetFrame();
		this->mAladdin->SetVelocity(.0f, .0f);
		break;
	}
	case AladdinState::Walk:
	{
		this->mAladdin = _mAladdinWalk;
		this->mAladdin->SetVelocity(((mDir==Direction::Right)?(1.0f):(-1.0f)) * 0.5f, .0f);
		break;
	}
	}
	

	this->mAladdin->Animate();
	this->mAladdin->Move(DeltaTime);
	this->mAladdin->Draw();

}
