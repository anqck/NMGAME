#include "AladdinCharacter.h"

#include"KeyboardHelper.h"
#include <dinput.h>

#include <string> 

AladdinCharacter::AladdinCharacter()
{
}

AladdinCharacter::AladdinCharacter(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3  pos)
{
	this->mSpriteHandle = SpriteHandle;

	vector<MyRECT> temp;
	temp.push_back(MyRECT(1212, 9, 57, 1275));
	this->mAladdinState.push_back(new ObjectState(temp, 10, L"Aladdin.png", D3DXVECTOR2(0, 0)));
	temp.clear();

	temp.push_back(MyRECT(117, 42, 82, 165));
	temp.push_back(MyRECT(56, 103, 146, 107));
	temp.push_back(MyRECT(117, 83, 120, 167));
	temp.push_back(MyRECT(0, 0, 55, 58));
	temp.push_back(MyRECT(0, 56, 111, 55));
	temp.push_back(MyRECT(0, 159, 203, 57));
	temp.push_back(MyRECT(59, 189, 230, 112));
	temp.push_back(MyRECT(58, 147, 188, 115));
	temp.push_back(MyRECT(59, 0, 52, 116));
	temp.push_back(MyRECT(0, 112, 158, 54));
	temp.push_back(MyRECT(0, 204, 246, 58));
	temp.push_back(MyRECT(117, 0, 41, 169));
	temp.push_back(MyRECT(116, 121, 155, 170));
	temp.push_back(MyRECT(59, 53, 102, 116));
	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 15, L"AladdinWalk.png", D3DXVECTOR2(0.5f, 0.0f),4));
	temp.clear();

	temp.push_back(MyRECT(0, 56, 110, 57));
	temp.push_back(MyRECT(106, 105, 143, 162));
	temp.push_back(MyRECT(58, 53, 104, 124));
	temp.push_back(MyRECT(53, 155, 202, 118));
	temp.push_back(MyRECT(92, 0, 42, 156));
	temp.push_back(MyRECT(0, 0, 55, 46));
	temp.push_back(MyRECT(47, 0, 52, 91));
	temp.push_back(MyRECT(51, 203, 249, 103));
	temp.push_back(MyRECT(58, 105, 154, 105));
	temp.push_back(MyRECT(0, 111, 162, 52));
	temp.push_back(MyRECT(0, 163, 214, 50));
	temp.push_back(MyRECT(104, 203, 240, 154));
	this->mAladdinState.push_back(new ObjectState(temp, 20, L"WalkStop.png", D3DXVECTOR2(0.2, 0)));
	temp.clear();

	temp.push_back(MyRECT(488, 7, 56, 551));
	temp.push_back(MyRECT(488, 56, 111, 551));
	temp.push_back(MyRECT(488, 109, 174, 551));
	this->mAladdinState.push_back(new ObjectState(temp, 20, L"Aladdin.png", D3DXVECTOR2(0, 0)));
	temp.clear();

	temp.push_back(MyRECT(0, 0, 44, 53));
	temp.push_back(MyRECT(54, 0, 42, 105));
	temp.push_back(MyRECT(54, 43, 85, 105));
	temp.push_back(MyRECT(54, 86, 127, 105));
	temp.push_back(MyRECT(0, 45, 89, 53));
	temp.push_back(MyRECT(0, 132, 172, 52));
	temp.push_back(MyRECT(0, 173, 213, 52));
	temp.push_back(MyRECT(0, 90, 131, 47));
	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 7, L"AladdinStand.png", D3DXVECTOR2(0, 0)));
	temp.clear();

	temp.push_back(MyRECT(498, 204, 257, 550));
	temp.push_back(MyRECT(498, 257, 314, 550));
	temp.push_back(MyRECT(498, 314, 373, 550));
	temp.push_back(MyRECT(498, 376, 434, 550));
	this->mAladdinState.push_back(new ObjectState(temp, 20, L"Aladdin.png", D3DXVECTOR2(0, 0)));
	temp.clear();

	//Rest
	temp.push_back(MyRECT(498, 376, 434, 550));
	this->mAladdinState.push_back(new ObjectState(temp, 20, L"Aladdin.png", D3DXVECTOR2(0, 0)));
	temp.clear();

	temp.push_back(MyRECT(630, 4, 58, 674));
	temp.push_back(MyRECT(630, 62, 112, 674));
	temp.push_back(MyRECT(630, 113, 189, 674));
	temp.push_back(MyRECT(630, 190, 287, 674));
	temp.push_back(MyRECT(630, 297, 383, 674));
	temp.push_back(MyRECT(630, 390, 465, 674));
	temp.push_back(MyRECT(630, 473, 522, 674));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"Aladdin.png", D3DXVECTOR2(0, 0)));
	temp.clear();

	temp.push_back(MyRECT(313, 6, 54, 390));
	temp.push_back(MyRECT(313, 54, 110, 390));
	temp.push_back(MyRECT(313, 110, 169, 390));
	temp.push_back(MyRECT(313, 168, 256, 390));
	temp.push_back(MyRECT(313, 258, 318, 390));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"Aladdin.png", D3DXVECTOR2(0, 0)));
	temp.clear();

	temp.push_back(MyRECT(0, 43, 75, 63));
	temp.push_back(MyRECT(0, 0, 42, 62));
	temp.push_back(MyRECT(0, 76, 107, 76));
	temp.push_back(MyRECT(0, 167, 195, 81));
	temp.push_back(MyRECT(0, 108, 137, 86));
	temp.push_back(MyRECT(0, 138, 166, 89));
	temp.push_back(MyRECT(0, 196, 224, 79));
	temp.push_back(MyRECT(0, 225, 253, 74));
	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 13, L"RopeClimb.png", D3DXVECTOR2(0, 0)));
	temp.clear();

	temp.push_back( MyRECT(680, 7, 52, 748));
	temp.push_back( MyRECT(680, 62, 115, 766));
	temp.push_back( MyRECT(680, 120, 180, 766));
	temp.push_back( MyRECT(680, 180, 258, 766));
	temp.push_back( MyRECT(680, 260, 335, 766));
	temp.push_back( MyRECT(680, 348, 410, 766));
	temp.push_back( MyRECT(680, 410, 473, 766));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"Aladdin.png", D3DXVECTOR2(0, 0)));
	temp.clear();

	//this->mAladdinState.push_back(new AladdinDoNothing(SpriteHandle));
	//this->mAladdinState.push_back(new AladdinWalk(SpriteHandle));
	//this->mAladdinState.push_back(new AladdinStopWalk(SpriteHandle));
	//this->mAladdinState.push_back(new AladdinLookUp(SpriteHandle));
	//this->mAladdinState.push_back(new AladdinStand(SpriteHandle));
	//this->mAladdinState.push_back(new AladdinSit(SpriteHandle));
	//this->mAladdinState.push_back(new AladdinRest(SpriteHandle));
	//this->mAladdinState.push_back(new AladdinSitAttack(SpriteHandle));
	//this->mAladdinState.push_back(new AladdinAttack1(SpriteHandle));


	this->mCurrentState = AState::DoNothing;

	this->mPosition = pos;
	this->mAladdinState.at(mCurrentState)->SetPosition(pos);
	
	this->mDir = Direction::Right;

	this->mTime = 0;
	this->allowStateChange = true;


}

void AladdinCharacter::Update(float DeltaTime)
{
	/*switch (this->mCurrentState)
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
	}*/


	if (this->mPosition.x >= 500 && this->mCurrentState != AState::RopeClimb)
	{
		this->mCurrentState = AState::RopeClimb;
		this->allowStateChange = false;
	}

	this->mAladdinState.at(mCurrentState)->SetFlipVertical((mDir == Direction::Right) ? (false) : (true));
	this->mAladdinState.at(mCurrentState)->SetPosition(this->mPosition);
	//this->mAladdinState.at(mCurrentState)->Animate(DeltaTime);
	
	this->mAladdinState.at(mCurrentState)->Update(DeltaTime);

	


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
		//this->mAladdinState.at(mCurrentState)->SetVelocity(((mDir == Direction::Right) ? (1.0f) : (-1.0f)) * 0.5f, .0f);

			if (this->mTime >= 15 * DeltaTime)
			{
				this->mIsStopAnimation = true;
			//	printLog("OKOKOKO");
			}
			else
			{
				//printLog(std::to_string(mTime).c_str());
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
		//this->mAladdinState.at(mCurrentState)->SetVelocity(((mDir == Direction::Right) ? (1.0f) : (-1.0f)) * 0.1f, .0f);
		if (this->mAladdinState.at(mCurrentState)->isDone())
		{
			allowStateChange = true;
		}
		break;
	}
	case AState::Stand:
		break;
	case AState::RunAndJump:
		if (this->mAladdinState.at(mCurrentState)->isDone())
		{
			this->allowStateChange = true;
			this->setCurrentState(AState::DoNothing);
			//this->mCurrentState = AState::DoNothing;
		}
		break;

	default:
		break;
	}


	//this->mAladdinState.at(mCurrentState)->Move(DeltaTime);
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
		break;
	case VK_LEFT:
		this->setDirection(Direction::Left);
		//this->setAllowStateChange(true);
		break;
	case VK_UP:
		//this->setAllowStateChange(true);
		break;
	case VK_DOWN:
		//this->setAllowStateChange(true);
		break;
	case VK_NUMPAD1:
		this->setCurrentState(AState::RunAndJump);
		this->setAllowStateChange(false);		
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

void AladdinCharacter::ProcessInput()
{
	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_RIGHT))
	{
		this->setAllowStateChange(true);
		this->setCurrentState(AState::Walk);		
	}
	else if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		this->setAllowStateChange(true);
		this->setCurrentState(AState::Walk);
	}
	else if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_UP))
	{
		this->setAllowStateChange(true);
		if(this->mCurrentState != AState::RopeClimb)
			this->setCurrentState(AState::LookUp);
	}
	else if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_DOWN))
	{
		//this->setAllowStateChange(true);
		this->setCurrentState(AState::Sit);
	}
	else if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_D))
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
		case AState::RunAndJump:
		{
			this->mAladdinState.at(AState::RunAndJump)->resetFrame();
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


