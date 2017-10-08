#include "AladdinCharacter.h"
#include <dinput.h>

#include <string> 

AladdinCharacter::AladdinCharacter()
{
}

AladdinCharacter::AladdinCharacter(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3  pos)
{
	this->mSpriteHandle = SpriteHandle;

	this->mAladdinState.push_back(new AladdinDoNothing(SpriteHandle));
	this->mAladdinState.push_back(new AladdinWalk(SpriteHandle));
	this->mAladdinState.push_back(new AladdinStopWalk(SpriteHandle));
	this->mAladdinState.push_back(new AladdinLookUp(SpriteHandle));
	this->mAladdinState.push_back(new AladdinStand(SpriteHandle));
	this->mAladdinState.push_back(new AladdinSit(SpriteHandle));
	this->mAladdinState.push_back(new AladdinRest(SpriteHandle));
	this->mAladdinState.push_back(new AladdinSitAttack(SpriteHandle));
	this->mAladdinState.push_back(new AladdinAttack1(SpriteHandle));

	this->mCurrentState = AState::DoNothing;

	this->mPosition = pos;
	this->mAladdinState.at(mCurrentState)->SetPosition(pos);
	
	this->mSpriteHandle = SpriteHandle;

	this->mDir = Direction::Right;

	this->mTime = 0;
	this->allowStateChange = true;


}

void AladdinCharacter::Update(float DeltaTime)
{
	switch (this->mCurrentState)
	{
	case AState::DoNothing:
		printLog("DoNothing");
		break;
	case AState::Walk:
		printLog("Walk");
		break;
	case AState::StopWalk:
		printLog("StopWalk");
		break;
	case AState::LookUp:
		printLog("LookUp");
		break;
	case AState::Attack1:
		printLog("Attack1");
		break;
	case AState::Stand:
		printLog("Stand");
		break;
	case AState::Sit:
		printLog("Sit");
		break;
	default:
		printLog("Else");
		break;
	}

	this->mAladdinState.at(mCurrentState)->SetFlipVertical((mDir == Direction::Right) ? (false) : (true));
	this->mAladdinState.at(mCurrentState)->SetPosition(this->mPosition);
	this->mAladdinState.at(mCurrentState)->Animate(DeltaTime);
	
	//this->mAladdinState.at(mCurrentState)->Update(DeltaTime);
	switch (this->mCurrentState)
	{
	case AState::DoNothing:
	{
		if (this->mTime >= 50 * DeltaTime)
		{
			this->mAladdinState.at(AState::Stand)->SetPosition(this->mPosition);
			this->mCurrentState = AState::Stand;
			this->allowStateChange = false;
			this->mTime = 0;
		}
		else
		{
			this->mTime += DeltaTime;
		}
		this->mAladdinState.at(mCurrentState)->SetVelocity(.0f, .0f);
		break;
	}
	case AState::Walk:
		this->mAladdinState.at(mCurrentState)->SetVelocity(((mDir == Direction::Right) ? (1.0f) : (-1.0f)) * 0.5f, .0f);

			if (this->mTime >= 15 * DeltaTime)
			{
				this->mIsStopAnimation = true;
				printLog("OKOKOKO");
			}
			else
			{
				printLog(std::to_string(mTime).c_str());
				this->mTime += DeltaTime;
			}
		break;
	case AState::Attack1:
		if (this->mAladdinState.at(mCurrentState)->isDone())
		{
			this->allowStateChange = true;
			this->setCurrentState(AState::DoNothing);
			//this->mCurrentState = AState::DoNothing;
		}
		break;
	case AState::SitAttack:
	{
		if (this->mAladdinState.at(mCurrentState)->GetCurrentIdx() == this->mAladdinState.at(mCurrentState)->GetEndIdx()  )
		{
			allowStateChange = true;
			//this->mCurrentState = AState::Sit;
		}
			break;
	}
	case AState::StopWalk:
	{			
		this->mAladdinState.at(mCurrentState)->SetVelocity(((mDir == Direction::Right) ? (1.0f) : (-1.0f)) * 0.3f, .0f);
		if (this->mAladdinState.at(mCurrentState)->isDone())
		{
			allowStateChange = true;
		}
		break;
	}
	case AState::Stand:
		break;
	default:
		break;
	}


	this->mAladdinState.at(mCurrentState)->Move(DeltaTime);
	this->mPosition = this->mAladdinState.at(mCurrentState)->GetPosition();


}

void AladdinCharacter::Render(float DeltaTime)
{
	this->mAladdinState.at(this->mCurrentState)->Render();
}

void AladdinCharacter::OnKeyDown(int keyCode)
{
	switch (keyCode)
	{
	case VK_RIGHT:
		this->setDirection(Direction::Right);
		this->setAllowStateChange(true);
		break;
	case VK_LEFT:
		this->setDirection(Direction::Left);
		this->setAllowStateChange(true);
		break;
	case VK_UP:
		this->setAllowStateChange(true);
		break;
	case VK_DOWN:
		this->setAllowStateChange(true);
		break;
	case VK_SPACE:
		if (allowAttack && (this->getCurrentState() != AState::Attack1) && (this->getCurrentState() != AState::SitAttack))
		{
			allowAttack = false;
			this->setAllowStateChange(true);

			if (this->getCurrentState() == AState::Sit)
				this->setCurrentState(AState::SitAttack);
			else
				this->setCurrentState(AState::Attack1);
			//this->setAllowStateChange(false);
		}
		break;
	default:
		
		break;
	}
}

void AladdinCharacter::OnKeyUp(int keyCode)
{
	switch (keyCode)
	{
	case VK_SPACE:
		allowAttack = true;
		break;

	}
}

void AladdinCharacter::ProcessInput(std::map<int, bool> keys)
{
	if (keys[VK_RIGHT])
	{
		this->setCurrentState(AState::Walk);		
	}
	else if (keys[VK_LEFT])
	{
		this->setCurrentState(AState::Walk);
	}
	else if (keys[VK_UP])
	{
		this->setCurrentState(AState::LookUp);
	}
	else if (keys[VK_DOWN])
	{
		this->setCurrentState(AState::Sit);
	}
	else if (keys[VK_SPACE])
	{

	}
	else
	{
		if((this->getCurrentState() != AState::Attack1) )
			this->setCurrentState(AState::DoNothing);
	}
}

AState AladdinCharacter::getCurrentState()
{
	return this->mCurrentState;
}

void AladdinCharacter::setCurrentState(AState state)
{
	if ((this->mCurrentState == state)|| (this->allowStateChange == false))
		return;


	if (state == AState::Sit && (this->mCurrentState == AState::SitAttack))
	{
		this->mCurrentState = AState::Sit;
		this->mAladdinState.at(AState::Sit)->GoToLastFrameIdx();
		return;
	}

	if ((state == AState::DoNothing) && (this->mCurrentState == AState::Walk) && (this->mIsStopAnimation == true))
	{
		this->mCurrentState = AState::StopWalk;
		this->allowStateChange = false;
		return;
	}


	_BeforeStateChange(state);

	this->mCurrentState = state;

	_AfterStateChange();
	
}
void AladdinCharacter::setDirection(Direction dir)
{
	mDir = dir;
}
void AladdinCharacter::setAllowStateChange(bool allow)
{
	this->allowStateChange = allow;
}
void AladdinCharacter::_BeforeStateChange(AState changeTo)
{
	this->mAladdinState.at(changeTo)->SetPosition(this->mAladdinState.at(mCurrentState)->GetPosition());
	if (this->mCurrentState != changeTo)
	{
		this->mAladdinState.at(AState::StopWalk)->resetFrame();
		this->mAladdinState.at(AState::Walk)->resetFrame();
		this->mAladdinState.at(AState::Attack1)->resetFrame();
		this->mAladdinState.at(AState::SitAttack)->resetFrame();		

		switch (this->mCurrentState)
		{
		case AState::DoNothing:
		{
			break;
		}
		case AState::Walk:
		{
			this->mAladdinState.at(AState::Walk)->resetFrame();
			break;
		}
		case AState::LookUp:
		{
			this->mAladdinState.at(AState::LookUp)->resetFrame();
			break;
		}
		case AState::Sit:
		{
			this->mAladdinState.at(AState::Sit)->resetFrame();
			break;
		}
		case AState::Attack1:
		{
			this->mAladdinState.at(AState::Attack1)->resetFrame();
			break;
		}
		case AState::SitAttack:
		{
			this->mAladdinState.at(AState::SitAttack)->resetFrame();
			break;
		}
		}
	}

}
void AladdinCharacter::_AfterStateChange()
{
	if (this->mCurrentState == AState::SitAttack || this->mCurrentState == AState::Attack1)
		allowStateChange = false;

	if (this->mCurrentState == AState::Walk)
	{
		this->mIsStopAnimation = false;
		this->mTime = 0;
	}

	if (this->mCurrentState == AState::DoNothing)
	{
		this->mTime = 0;
	}

	this->mTime = 0;
}


