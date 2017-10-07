#include "AladdinHelper.h"

AladdinHelper::AladdinHelper(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3	pos)
{
	this->_mAladdinWalk = new AladdinWalk(SpriteHandle);
	this->_mAladdinLookUp = new AladdinLookUp(SpriteHandle);
	this->_mAladdinStand = new AladdinStand(SpriteHandle);
	this->_mAladdinRest = new AladdinRest(SpriteHandle);
	this->_mAladdinAttack1 = new AladdinAttack1(SpriteHandle);
	this->_mAladdinSit = new AladdinSit(SpriteHandle);
	this->_mAladdinSitAttack = new AladdinSitAttack(SpriteHandle);

	this->mState = AladdinState::DoNothing;

	this->mPosition = pos;

	this->mAladdin = _mAladdinWalk;
	this->mAladdin->SetPosition(pos);
	this->mSpriteHandler = SpriteHandle;

	this->mDir = Direction::Right;
	//this->mAladdin->SetFlipVertical(false);
	this->mTime = 0;
	this->allowStateChange = true;
	
}

AladdinState AladdinHelper::getAladdinState()
{
	return this->mState;
}

void AladdinHelper::setAladdinState(AladdinState state)
{
	if (!this->allowStateChange)
		return;
	if (state == AladdinState::Sit && (this->mState == AladdinState::SitAttack))
	{
		
		this->mState = AladdinState::Sit;
		_mAladdinSit->GoToLastFrameIdx();
		return;
	}

	/*if (state == AladdinState::DoNothing && (this->mState == AladdinState::Stand || this->mState == AladdinState::Attack1|| this->mState == AladdinState::SitAttack))
		return; */

	

	if (this->mState != state)
	{
		_mAladdinAttack1->resetFrame();
		_mAladdinSitAttack->resetFrame();
		switch (this->mState)
		{
		case AladdinState::DoNothing:
		{			
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
		case AladdinState::Sit:
		{
			_mAladdinSit->resetFrame();
			break;
		}
		case AladdinState::Attack1:
		{
			_mAladdinAttack1->resetFrame();
			break;
		}
		case AladdinState::SitAttack:
		{
			_mAladdinSitAttack->resetFrame();
			break;
		}
		}

		this->mState = state;

		if (state == AladdinState::SitAttack|| state == AladdinState::Attack1)
			allowStateChange = false;
	}
}

void AladdinHelper::setDirection(Direction dir)
{
	mDir = dir;
}

void AladdinHelper::setAllowStateChange(bool allow)
{
	this->allowStateChange = allow;
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
		break;
	}
	case AladdinState::Sit:
	{
		this->mAladdin = _mAladdinSit;
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
		{
			this->mState = AladdinState::DoNothing;
			allowStateChange = true;
		}
			
			//

		break;
	}
	case AladdinState::SitAttack:
	{

 		this->mAladdin = _mAladdinSitAttack;
		


		if (this->mAladdin->GetCurrentIdx() == this->mAladdin->GetEndIdx() - 1)
		{
			allowStateChange = true;
			//this->mState = AladdinState::Sit;
		}

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
