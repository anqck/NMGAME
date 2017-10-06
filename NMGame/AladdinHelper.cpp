#include "AladdinHelper.h"

AladdinHelper::AladdinHelper(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3	pos)
{
	this->_mAladdinWalk = new AladdinWalk(SpriteHandle);
	this->_mAladdinLookUp = new AladdinLookUp(SpriteHandle);

	this->mState = AladdinState::DoNothing;

	this->mPosition = pos;

	this->mAladdin = _mAladdinWalk;
	this->mAladdin->SetPosition(pos);
	this->mSpriteHandler = SpriteHandle;

	this->mDir = Direction::Right;
	//this->mAladdin->SetFlipVertical(false);
	
}

void AladdinHelper::setAladdinState(AladdinState state)
{
	if (this->mState != state)
	{
		switch (this->mState)
		{
		case AladdinState::DoNothing:
		{

			break;
		}
		case AladdinState::Walk:
		{

			break;
		}
		case AladdinState::LookUp:
		{
			_mAladdinLookUp->resetFrame();
			break;
		}
		}
		this->mState = state;
	}
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
		
		

		this->mAladdin->SetVelocity(((mDir==Direction::Right)?(1.0f):(-1.0f)) * 0.7f, .0f);
		

		break;
	}
	case AladdinState::LookUp:
	{
		this->mAladdin = _mAladdinLookUp;

		//this->mAladdin->SetPosition(this->mPosition);
		//this->mAladdin->SetVelocity(((mDir == Direction::Right) ? (1.0f) : (-1.0f)) * 0.7f, .0f);
		break;
	}
	}
	
	this->mAladdin->SetFlipVertical((mDir == Direction::Right) ? (false) : (true));
	this->mAladdin->SetPosition(this->mPosition);
	this->mAladdin->Animate();
	this->mAladdin->Move(DeltaTime);
	this->mPosition = this->mAladdin->GetPosition();
	this->mAladdin->Draw();

}
