#include "AladdinHelper.h"

AladdinHelper::AladdinHelper(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3	pos)
{
	this->_mAladdinWalk = new AladdinWalk(SpriteHandle);
	this->_mAladdinLookUp = new AladdinLookUp(SpriteHandle);
	this->_mAladdinStand = new AladdinStand(SpriteHandle);
	this->_mAladdinRest = new AladdinRest(SpriteHandle);
	this->_mAladdinAttack1 = new AladdinAttack1(SpriteHandle);

	this->mState = AladdinState::DoNothing;

	this->mPosition = pos;

	this->mAladdin = _mAladdinWalk;
	this->mAladdin->SetPosition(pos);
	this->mSpriteHandler = SpriteHandle;

	this->mDir = Direction::Right;
	//this->mAladdin->SetFlipVertical(false);
	this->mTime = 0;
	
}

void AladdinHelper::setAladdinState(AladdinState state)
{
	if (state == AladdinState::DoNothing && (this->mState == AladdinState::Stand || this->mState == AladdinState::Attack1))
		return; 

	

	if (this->mState != state)
	{
		switch (this->mState)
		{
		case AladdinState::DoNothing:
		{
			_mAladdinAttack1->resetFrame();
			break;
		}
		case AladdinState::Walk:
		{
			_mAladdinWalk->resetFrame();
			break;
		}
		case AladdinState::LookUp:
		{
			_mAladdinLookUp->resetFrame();
			break;
		}
		case AladdinState::Attack1:
		{
			_mAladdinAttack1->resetFrame();
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
		//this->mAladdin->resetFrame();
		
		if (this->mTime >= 25 * DeltaTime)
		{
			this->mState = AladdinState::Stand;
			this->mTime = 0;
			
		}
		else
		{
			this->mTime += DeltaTime;
		}


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
	case AladdinState::Stand:
	{
		this->mAladdin = _mAladdinStand;

		break;
	}
	case AladdinState::Attack1:
	{
		this->mAladdin = _mAladdinAttack1;

		if (this->mAladdin->GetCurrentIdx() == this->mAladdin->GetEndIdx() - 1)
			this->mState = AladdinState::Walk;

		break;
	}
	case AladdinState::Rest:
	{
		this->mAladdin = _mAladdinRest;
		
		break;

	}
	}
	
	this->mAladdin->SetFlipVertical((mDir == Direction::Right) ? (false) : (true));
	this->mAladdin->SetPosition(this->mPosition);
	this->mAladdin->Animate(DeltaTime);
	this->mAladdin->Move(DeltaTime);
	this->mPosition = this->mAladdin->GetPosition();
	this->mAladdin->Draw();

}
