#include "AladdinCharacter.h"

#include"KeyboardHelper.h"

#include <dinput.h>
#include <string> 


#pragma region Init
AladdinCharacter::AladdinCharacter()
{
}

AladdinCharacter::AladdinCharacter( D3DXVECTOR3  pos)
{
	LoadResource();


	this->mCurrentState = AState::DoNothing;
	this->mPosition = pos;
	this->mAladdinState.at(mCurrentState)->SetPosition(pos);	
	this->mDir = Direction::Right;
	
	this->mWidth = 35;
	this->mHeight = 120;

	this->mTime = 0;

	this->allowStateChange = true;
	this->allowAttack = true;
	this->allowJump = true;

	this->mIsGrounded = false;
	isClimbing = false;
	mWallCollision = false;



	
}

void AladdinCharacter::LoadResource()
{
	vector<MyRECT> temp;

	/*this->mWidth = 63 * 2;
	this->mHeight = 48 * 2.5 ;*/

	//DoNothing
	temp.push_back(MyRECT(53, 128, 165, 103));
	this->mAladdinState.push_back(new ObjectState(temp, 10, L"AladdinCharacter\\AladdinStand.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Walk
	temp.push_back(MyRECT(117, 83, 120, 167));
	temp.push_back(MyRECT(117, 42, 82, 165, D3DXVECTOR3(6,0,0)));
	temp.push_back(MyRECT(56, 103, 146, 107, D3DXVECTOR3(8, 0, 0)));
	temp.push_back(MyRECT(0, 0, 55, 58, D3DXVECTOR3(2, 0, 0)));
	temp.push_back(MyRECT(0, 56, 111, 55));
	temp.push_back(MyRECT(0, 159, 203, 57, D3DXVECTOR3(2, 0, 0)));
	temp.push_back(MyRECT(59, 189, 230, 112));
	temp.push_back(MyRECT(58, 147, 188, 115, D3DXVECTOR3(4, 0, 0)));
	temp.push_back(MyRECT(59, 0, 52, 116, D3DXVECTOR3(3, 0, 0)));
	temp.push_back(MyRECT(0, 112, 158, 54));
	temp.push_back(MyRECT(0, 204, 246, 58));
	temp.push_back(MyRECT(117, 0, 41, 169));
	temp.push_back(MyRECT(116, 121, 155, 170));
	temp.push_back(MyRECT(59, 53, 102, 116));

	//this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 12, L"AladdinCharacter\\AladdinWalk.png", D3DXVECTOR2(0.7f, 0.0f), 3, CenterArchor::CenterBottom));
	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 13, L"AladdinCharacter\\AladdinWalk.png", D3DXVECTOR2(0.7f, 0.0f), 3, CenterArchor::CenterBottom));
	temp.clear();


	//Stop walk
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
	this->mAladdinState.push_back(new ObjectState(temp, 20, L"WalkStop.png", D3DXVECTOR2(0.1, 0), CenterArchor::CenterBottom));
	temp.clear();

	//LookUp
	temp.push_back(MyRECT(60, 39, 76, 110, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(59, 0, 38, 112, D3DXVECTOR3(0.7, - 0.3, 0)));
	temp.push_back(MyRECT(0, 50, 95, 59, D3DXVECTOR3(-1, -0.3, 0)));
	temp.push_back(MyRECT(0, 0, 49, 58, D3DXVECTOR3(-1.5, -0.3, 0)));

	this->mAladdinState.push_back(new ObjectState(temp, 20, L"AladdinCharacter//LookUp.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	//this->mAladdinState.push_back(new ObjectState(temp, 20, L"AladdinCharacter//LookUp.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//Stand
	temp.push_back(MyRECT(53, 128, 165, 103));
	temp.push_back(MyRECT(0, 90, 131, 47));
	temp.push_back(MyRECT(0, 132, 172, 52, D3DXVECTOR3(1,0,0)));
	temp.push_back(MyRECT(0, 0, 44, 53, D3DXVECTOR3(2.65, 0, 0)));
	temp.push_back(MyRECT(0, 173, 213, 52, D3DXVECTOR3(1, 0, 0)));
	temp.push_back(MyRECT(54, 86, 127, 105, D3DXVECTOR3(-0.5, 0, 0)));
	temp.push_back(MyRECT(54, 0, 42, 105, D3DXVECTOR3(-1.5, 0, 0)));
	temp.push_back(MyRECT(0, 45, 89, 53, D3DXVECTOR3(-2.25, 0, 0)));
	temp.push_back(MyRECT(54, 43, 85, 105, D3DXVECTOR3(-0.5, 0, 0)));

	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 8, L"AladdinCharacter\\AladdinStand.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//Sit
	temp.push_back(MyRECT(36, 49, 86, 86));
	temp.push_back(MyRECT(72, 0, 41, 121, D3DXVECTOR3(-2, 0.4, 0)));
	temp.push_back(MyRECT(31, 0, 48, 71, D3DXVECTOR3(-2, 0.4, 0)));
	temp.push_back(MyRECT(0, 0, 54, 30, D3DXVECTOR3(0.5, -1.2, 0)));
	temp.push_back(MyRECT(0, 55, 108, 35, D3DXVECTOR3(5, -1.2, 0)));

	this->mAladdinState.push_back(new ObjectState(temp, 20, L"AladdinCharacter//AladdinSit.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Rest
	temp.push_back(MyRECT(498, 376, 434, 550));
	this->mAladdinState.push_back(new ObjectState(temp, 20, L"Aladdin.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//SitAttack
	temp.push_back(MyRECT(35, 85, 132, 68, D3DXVECTOR3(4.5, -1.2, 0)));
	temp.push_back(MyRECT(69, 72, 117, 100, D3DXVECTOR3(3.6, -1.2, 0)));
	temp.push_back(MyRECT(69, 0, 71, 102, D3DXVECTOR3(17, -1.2, 0)));
	temp.push_back(MyRECT(0, 0, 92, 34, D3DXVECTOR3(27, -1.2, 0)));
	temp.push_back(MyRECT(35, 0, 84, 68, D3DXVECTOR3(24, -1.2, 0)));
	temp.push_back(MyRECT(0, 93, 164, 33, D3DXVECTOR3(16.6, -1.2, 0)));
	temp.push_back(MyRECT(0, 165, 210, 31, D3DXVECTOR3(4, -1.2, 0)));

	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinCharacter//SitAttack.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//Attack1
	temp.push_back(MyRECT(54, 204, 241, 104, D3DXVECTOR3(0.2, 0, 0)));
	temp.push_back(MyRECT(54, 106, 151, 105, D3DXVECTOR3(-3.5, 0, 0)));
	temp.push_back(MyRECT(53, 54, 105, 115, D3DXVECTOR3(-3.5, 0, 0)));
	temp.push_back(MyRECT(0, 158, 203, 74));
	temp.push_back(MyRECT(0, 0, 82, 52, D3DXVECTOR3(23, 0, 0)));
	temp.push_back(MyRECT(0, 106, 157, 53));
	temp.push_back(MyRECT(117, 0, 37, 167));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinCharacter//AladdinAttack.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//RopeClimb
	temp.push_back(MyRECT(0, 43, 75, 63));
	temp.push_back(MyRECT(0, 0, 42, 62));
	temp.push_back(MyRECT(0, 76, 107, 76));
	temp.push_back(MyRECT(0, 167, 195, 81));
	temp.push_back(MyRECT(0, 108, 137, 86));
	temp.push_back(MyRECT(0, 138, 166, 89));
	temp.push_back(MyRECT(0, 196, 224, 79));
	temp.push_back(MyRECT(0, 225, 253, 74));
	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 13, L"RopeClimb.png", D3DXVECTOR2(0, -0.2), CenterArchor::CenterBottom));
	temp.clear();


	//RunAndJump
	temp.push_back(MyRECT(77, 159, 196, 127));
	temp.push_back(MyRECT(59, 117, 158, 101));
	temp.push_back(MyRECT(0, 175, 220, 76));
	temp.push_back(MyRECT(54, 59, 116, 111));
	temp.push_back(MyRECT(49, 0, 58, 91));
	temp.push_back(MyRECT(49, 0, 58, 91));
	temp.push_back(MyRECT(0, 0, 61, 48));
	temp.push_back(MyRECT(0, 62, 120, 53));
	temp.push_back(MyRECT(0, 121, 174, 58));

	this->mAladdinState.push_back(new ObjectState(temp, 11, L"AladdinAction\\AladdinRunJump.png", D3DXVECTOR2(0, 0.8), D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//Throw apple
	temp.push_back(MyRECT(0, 177, 214, 50));
	temp.push_back(MyRECT(64, 0, 43, 120, D3DXVECTOR3(2.5,0,0)));
	temp.push_back(MyRECT(64, 44, 85, 123, D3DXVECTOR3(1.2, 0, 0)));
	temp.push_back(MyRECT(0, 100, 138, 58));
	temp.push_back(MyRECT(0, 0, 52, 63, D3DXVECTOR3(6.5, 0, 0)));
	temp.push_back(MyRECT(0, 53, 99, 60, D3DXVECTOR3(2.5, 0, 0)));
	temp.push_back(MyRECT(0, 139, 176, 58, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(61, 86, 125, 113, D3DXVECTOR3(-1, 0, 0)));

	this->mAladdinState.push_back(new ObjectState(temp, 20, L"AladdinCharacter\\Throw.png", D3DXVECTOR2(0, 0), D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Sit Throw
	temp.push_back(MyRECT(38, 58, 111, 73, D3DXVECTOR3(5, -1.2, 0)));
	temp.push_back(MyRECT(38, 0, 57, 75, D3DXVECTOR3(3, -0.2, 0)));
	temp.push_back(MyRECT(0, 150, 187, 44, D3DXVECTOR3(0, -0.2, 0)));
	temp.push_back(MyRECT(0, 112, 149, 48, D3DXVECTOR3(0, -0.2, 0)));
	temp.push_back(MyRECT(74, 58, 108, 122,  D3DXVECTOR3(7, -4.3, 0)));
	temp.push_back(MyRECT(0, 0, 82, 37, D3DXVECTOR3(12, -0.5, 0)));
	temp.push_back(MyRECT(76, 0, 57, 113, D3DXVECTOR3(3, -0.5, 0)));

	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinCharacter\\SitThrow.png", D3DXVECTOR2(0, 0), D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	//this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinCharacter\\SitThrow.png", D3DXVECTOR2(0, 0), D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//RunAttack
	temp.push_back(MyRECT(61, 112, 147, 113));
	temp.push_back(MyRECT(0, 74, 125, 60, D3DXVECTOR3(4, 8, 0)));
	temp.push_back(MyRECT(61, 61, 111, 114, D3DXVECTOR3(5, 8, 0)));
	temp.push_back(MyRECT(0, 126, 174, 60, D3DXVECTOR3(3, 6, 0)));
	temp.push_back(MyRECT(0, 0, 73, 60, D3DXVECTOR3(12, 4, 0)));
	temp.push_back(MyRECT(61, 0, 60, 111, D3DXVECTOR3(12, 2, 0)));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinAction\\RunAttack.png", D3DXVECTOR2(0.5f, 0.0f), CenterArchor::CenterBottom));
	temp.clear();

	//StandJump
	temp.push_back(MyRECT(77, 159, 196, 127));
	temp.push_back(MyRECT(59, 117, 158, 101));
	temp.push_back(MyRECT(0, 175, 220, 76));
	temp.push_back(MyRECT(54, 59, 116, 111));
	temp.push_back(MyRECT(49, 0, 58, 91));
	temp.push_back(MyRECT(49, 0, 58, 91));
	temp.push_back(MyRECT(0, 0, 61, 48));
	temp.push_back(MyRECT(0, 62, 120, 53));
	temp.push_back(MyRECT(0, 121, 174, 58));

	this->mAladdinState.push_back(new ObjectState(temp, 11, L"AladdinAction\\AladdinRunJump.png", D3DXVECTOR2(0, 0), D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//JumpAttack
	temp.push_back(MyRECT(0, 137, 189, 54));
	temp.push_back(MyRECT(57, 114, 164, 109));
	temp.push_back(MyRECT(0, 190, 237, 66));
	temp.push_back(MyRECT(0, 84, 136, 56));
	temp.push_back(MyRECT(0, 0, 83, 59));
	temp.push_back(MyRECT(60, 60, 113, 118));
	temp.push_back(MyRECT(60, 0, 59, 115));

	this->mAladdinState.push_back(new ObjectState(temp, 14, L"AladdinCharacter\\JumpAttack.png", D3DXVECTOR2(0, 0.8f), D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Push
	temp.push_back(MyRECT(91, 124, 161, 141));
	temp.push_back(MyRECT(90, 67, 123, 136));
	temp.push_back(MyRECT(135, 0, 65, 179));
	temp.push_back(MyRECT(45, 154, 224, 90));
	temp.push_back(MyRECT(45, 0, 77, 89));
	temp.push_back(MyRECT(0, 158, 230, 44));
	temp.push_back(MyRECT(90, 0, 66, 134));
	temp.push_back(MyRECT(0, 82, 157, 44));
	temp.push_back(MyRECT(0, 0, 81, 44));
	temp.push_back(MyRECT(45, 78, 153, 89));

	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 11, L"AladdinCharacter\\Push.png", D3DXVECTOR2(0.2f, 0),2, CenterArchor::CenterBottom));
	temp.clear();
}

#pragma endregion

#pragma region Update&Render
void AladdinCharacter::Update(float DeltaTime)
{
	this->PrintLogState();	

	this->mAladdinState.at(mCurrentState)->SetFlipVertical((mDir == Direction::Left) ? (true) : (false));

	//this->mAladdinState.at(mCurrentState)->SetVelocity(this->mAladdinState.at(mCurrentState)->GetVelocity().x, -0.5);
	if (this->mCurrentState != AState::RunAndJump && this->mCurrentState != AState::StandJump && this->mCurrentState != AState::JumpAttack)
	{
		/*if (mIsGrounded)
		{
			this->mAladdinState.at(mCurrentState)->SetVelocity(this->mAladdinState.at(mCurrentState)->GetVelocity().x, 0);
		}
		else*/
		{
			this->mAladdinState.at(mCurrentState)->SetVelocity(this->mAladdinState.at(mCurrentState)->GetVelocity().x, -0.5);
		}
	}
	if (this->mCurrentState == AState::Push)
	{
		this->mAladdinState.at(mCurrentState)->ResetDefaultVelocity();
	}
	
	
	
	

	switch (this->mCurrentState)
	{
	case AState::DoNothing: //Trường hợp không làm gì
	{
		if (this->mTime >= 50 * DeltaTime)
		{
			this->allowStateChange = true;
			this->setCurrentState(AState::Stand);
			this->mTime = 0;
		}
		else
		{			
			this->mTime += DeltaTime;			
		}
		break;
	}
	case AState::Walk: //Trường hợp đang đi
	{
		if (this->mTime >= 30 * DeltaTime)
		{
			this->mIsStopAnimation = true;	//Cờ hiệu cho hành động dừng
		}
		else
		{
			this->mTime += DeltaTime;
		}
		break;
	}
	
	case AState::RunAndJump:
	{
		//if (!mIsGrounded)
		{
			float vx = (KeyboardHelper::GetInstance()->IsKeyDown(DIK_RIGHT)
				|| KeyboardHelper::GetInstance()->IsKeyDown(DIK_LEFT)) ?
				0.36 : 0;
			/*if (mIsGrounded == true)
			{
			mJumpHeight = this->mAladdinState.at(mCurrentState)->GetPosition().y + 170;
			this->mAladdinState.at(mCurrentState)->SetVelocity(0, 0);
			mIsGrounded = false;
			mIsFalling = false;
			mIsReachJumpHeight = false;
			}
			else
			{

			if ( mIsReachJumpHeight == false)
			{
			this->mAladdinState.at(mCurrentState)->SetVelocity(vx, 0.5);
			if (this->mAladdinState.at(mCurrentState)->GetPosition().y >= mJumpHeight)
			{
			mIsReachJumpHeight = true;
			}
			}
			else
			{

			if (mIsFalling == false)
			{
			this->mAladdinState.at(mCurrentState)->SetVelocity(vx, 0.06);
			if (this->mAladdinState.at(mCurrentState)->GetPosition().y >= mJumpHeight + 18)
			{
			mIsFalling = true;
			}
			}
			else
			{
			this->mAladdinState.at(mCurrentState)->SetVelocity(vx , -0.5);
			}

			}
			}*/

			//float vy = -2 * 0.5 *0.7;//Sin(PI/4) ~ 0.7
			/*float vy = -10;
			printLog(to_string(this->mAladdinState.at(mCurrentState)->GetPosition().y).c_str());*/

			//mTime += DeltaTime/16;

			this->mAladdinState.at(mCurrentState)->SetVelocity(vx, this->mAladdinState.at(mCurrentState)->GetVelocity().y - 0.05);
			//this->mAladdinState.at(mCurrentState)->SetAcceleration(0, -0.05);
		}
		//else
		{
			//this->mAladdinState.at(mCurrentState)->SetVelocity(0,0);
		}

	}
	break;
	case AState::StandJump:
	{
		float vx = (KeyboardHelper::GetInstance()->IsKeyDown(DIK_RIGHT)
			|| KeyboardHelper::GetInstance()->IsKeyDown(DIK_LEFT)) ?
			0.15 : 0;

		this->mAladdinState.at(mCurrentState)->SetVelocity(vx, this->mAladdinState.at(mCurrentState)->GetVelocity().y - 0.05);

	}
	break;
	case AState::JumpAttack:
	{
		float vx = (KeyboardHelper::GetInstance()->IsKeyDown(DIK_RIGHT)
			|| KeyboardHelper::GetInstance()->IsKeyDown(DIK_LEFT)) ?
			0.3 : 0;

		this->mAladdinState.at(mCurrentState)->SetVelocity(vx, this->mAladdinState.at(mCurrentState)->GetVelocity().y - 0.0555);
		
	}
	break;
	

	case AState::Stand:
		
		break;
	case AState::ThrowApple:
		if (this->mAladdinState.at(mCurrentState)->GetCurrentIdx() == 3 && this->mAladdinState.at(mCurrentState)->isNextFrame == true)
		{
			mListThrowingApple.push_back(new ThrowingApple(D3DXVECTOR3(this->mAladdinState.at(mCurrentState)->GetPosition().x + ((this->mDir == Direction::Right)? 1: -1) * 40, this->mAladdinState.at(mCurrentState)->GetPosition().y +  125, 0),this->mDir));
		}			
		break;
	case AState::SitThrow:
		if (this->mAladdinState.at(mCurrentState)->GetCurrentIdx() == 3 && this->mAladdinState.at(mCurrentState)->isNextFrame == true)
		{
			mListThrowingApple.push_back(new ThrowingApple(D3DXVECTOR3(this->mAladdinState.at(mCurrentState)->GetPosition().x + ((this->mDir == Direction::Right) ? 1 : -1)* 32, this->mAladdinState.at(mCurrentState)->GetPosition().y +  95 , 0), this->mDir));
		}
		break;
	}

	//Kiểm tra danh sách các táo đã ném ra nếu xong thì bỏ khỏi list;
	//for (int i = 0; i < mListThrowingApple.size(); i++)
	//{
	//	mListThrowingApple.at(i)->Update(DeltaTime);
	//	if (mListThrowingApple.at(i)->isDone() == true)
	//	{
	//		mListThrowingApple.erase(mListThrowingApple.begin() + i);
	//	}
	//}

	this->CheckCollisionWithGround(DeltaTime, mListGround);

		if (this->mCurrentState != AState::RopeClimb)
		{

				this->mAladdinState.at(mCurrentState)->Update(DeltaTime);
		
		}
		else
		{
			if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_UP))
			{
				this->mAladdinState.at(this->mCurrentState)->Animate(DeltaTime);
				this->mAladdinState.at(mCurrentState)->Move(DeltaTime);
			}
		}
	

	
	this->mPosition = this->mAladdinState.at(mCurrentState)->GetPosition();


}

void AladdinCharacter::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);
	//this->Transform();
	this->mAladdinState.at(this->mCurrentState)->Render();

	for (int i = 0; i < mListThrowingApple.size(); i++)
	{
		mListThrowingApple.at(i)->Render(DeltaTime);
		
	}
}

#pragma endregion

#pragma region Keyboard
void AladdinCharacter::OnKeyDown(int keyCode)
{

	switch (keyCode)
	{
	case VK_SPACE:
		this->mPosition = D3DXVECTOR3(100, WORLD_Y - MAP_HEIGHT + 220, 0);
		this->mAladdinState.at(this->mCurrentState)->SetPosition(this->mPosition);
		break;
	case VK_RIGHT:
		this->setDirection(Direction::Right);		
		break;
	case VK_LEFT:
		this->setDirection(Direction::Left);
		break;	
	case VK_ESCAPE:
		PostMessage(GLOBAL::GetHWND(), WM_CLOSE, 0, 0);
	}
}

void AladdinCharacter::OnKeyUp(int keyCode)
{
	if(keyCode	== 83) //S
		this->allowAttack = true;

	if (keyCode == 65) //A
		this->allowAttack = true;
	
	if (keyCode == 68) //D
		this->allowJump = true;

}

void AladdinCharacter::ProcessInput()
{
	flagKeyPressed = false;
	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_RIGHT) || KeyboardHelper::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		this->mAladdinState.at(mCurrentState)->SetFlipVertical((mDir == Direction::Left) ? (true) : (false));
		switch (this->mCurrentState)
		{
		case AState::Sit:
		case AState::LookUp:
		case AState::RopeClimb:
		case AState::RunAttack: //Chuyển từ chạy đánh sang chạy
			flagKeyPressed = true;
			if (this->mAladdinState.at(mCurrentState)->isDone())
			{				
				this->setAllowStateChange(true);
				this->setCurrentState(AState::Walk);
				
			
			}
			break;
		
		case AState::RunAndJump:
		case AState::JumpAttack:
			break;
		default:
			if (mWallCollision == false)
			{
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::Walk);
			}
			else
			{
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::Push);
			}

		}			
	}

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_UP))
	{
		switch (this->mCurrentState)
		{
		case AState::Sit:
		case AState::RopeClimb:
		case AState::RunAndJump:
			break;
		default:
			flagKeyPressed = true;
			this->setAllowStateChange(true);
			this->setCurrentState(AState::LookUp);
		}
	}

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_DOWN))
	{
		
		switch (this->mCurrentState)
		{
		case AState::SitAttack:
		case AState::SitThrow:
			if (this->mAladdinState.at(mCurrentState)->isDone())
			{
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::Sit);
			}

			break;
		case AState::RunAndJump:
		case AState::RopeClimb:
			break;
		default:
			flagKeyPressed = true;
			this->setAllowStateChange(true);
			this->setCurrentState(AState::Sit);
		}
	}

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_A))
	{
		switch (this->mCurrentState)
		{
		//case AState::Attack1:
		
		case AState::RunAndJump:
		case AState::RopeClimb:
		case AState::ThrowApple:
		case AState::SitThrow:
			break;
		case AState::SitAttack:
		case AState::Sit:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::SitThrow);

				break;
			}

		default:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::ThrowApple);

				break;
			}
		}
	}
	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_S))
	{
		switch (this->mCurrentState)
		{
		case AState::RunAttack:
		case AState::Attack1:
		case AState::JumpAttack:
		case AState::SitAttack:
		case AState::RopeClimb:
			break;
		
		case AState::Walk:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::RunAttack);
				break;
			}
		case AState::RunAndJump:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::JumpAttack);
				break;
			}
		case AState::SitThrow:
		case AState::Sit:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::SitAttack);
				break;
			}
		default:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::Attack1);
				break;
			}			
		}
	}
	

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_D))
	{
		switch (this->mCurrentState)
		{
		case AState::Stand:
		case AState::DoNothing:
			if (allowJump)
			{
				mIsGrounded = false;
				allowJump = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::RunAndJump);
				break;
			}
			break;
		case AState::RopeClimb:
		case AState::Walk:
		case AState::Push:
			if(allowJump)
			{
				mIsGrounded = false;
				allowJump = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::RunAndJump);
				break;
			}
		case AState::SitAttack:
			break;
		default:
	
			break;
		}
	}

	if (flagKeyPressed == false)
	{
		switch (this->mCurrentState)
		{
		
		case AState::Attack1:
		case AState::StopWalk:
		case AState::SitAttack:
		case AState::ThrowApple:
		case AState::SitThrow:			
			if (this->mAladdinState.at(mCurrentState)->isDone())
			{
				this->setAllowStateChange(true);
				this->setCurrentState(AState::DoNothing);
			}
			break;
		case AState::JumpAttack:
			if (this->mAladdinState.at(mCurrentState)->isDone())
			{
				this->setAllowStateChange(true);
				this->setCurrentState(AState::RunAndJump);
			}
			else if (isGrounded() == true)
			{
				this->allowStateChange = true;
				this->setCurrentState(AState::DoNothing);
			}
			break;
		case AState::Stand:
		case AState::RopeClimb:
			break;
		case AState::StandJump:
		case AState::RunAndJump:
			if (isGrounded() == true)
			{
				this->allowStateChange = true;
				this->setCurrentState(AState::DoNothing);
			}			
			break;
		case AState::RunAttack:
		default:
			this->setAllowStateChange(true);
			this->setCurrentState(AState::DoNothing);
			break;
		}
	}

	
}

#pragma endregion

#pragma region StateChange
void AladdinCharacter::setCurrentState(AState state)
{
	//Kiểm tra xem state thay đổi có khác state hiện tại
	if (this->mCurrentState == state)
	{
		return;
	}
		


	//Kiểm tra biến cho phép sự thay đổi
	if (this->allowStateChange == false)
		return;
	else
		this->allowStateChange = false;

	this->_BeforeStateChange(state);

	this->mCurrentState = state;

	this->_AfterStateChange();

}

ObjectState * AladdinCharacter::getCurrentObjectState()
{
	return this->mAladdinState.at(mCurrentState);
}

void AladdinCharacter::_BeforeStateChange(AState &changeTo)
{	
	

	//Khi chuyển từ hành động chạy sang hành động đứng và biến cờ hiệu hành động dừng
	if ((this->mCurrentState == AState::Walk) && (changeTo == AState::DoNothing) && (this->mIsStopAnimation == true))
	{
		changeTo = AState::StopWalk;
		this->mIsStopAnimation = false;
	}
	
	//Khi chuyển từ SitAttack qua Sit thì set frame cuối cùng
	if ((this->mCurrentState == AState::SitAttack || this->mCurrentState == AState::SitThrow) && (changeTo == AState::Sit) )
	{
		this->mAladdinState.at(AState::Sit)->GoToLastFrameIdx();
		this->allowStateChange = true;
	}

	//Khi chuyển từ RunAttack qua Run thì set frame cuối cùng
	if ((this->mCurrentState == AState::RunAttack) && (changeTo == AState::Walk))
	{
		this->mAladdinState.at(AState::RunAttack)->GoToFrame(12);

		this->allowStateChange = true;
	}

	//Thay vị trí hiện tại cho state khác
	this->mPosition = this->mAladdinState.at(this->mCurrentState)->GetPosition();
	this->mAladdinState.at(changeTo)->SetPosition(this->mPosition);
	
	//Reset lại frame idx của state cũ
	this->mAladdinState.at(this->mCurrentState)->resetFrame();

	if (mCurrentState != AState::RopeClimb)
		isClimbing = false;
	
	//Nếu chuyển sang hành động JumpAttack thì lấy vận tốc của hành động nhảy
	if ((mCurrentState == AState::RunAndJump || mCurrentState == AState::StandJump) && changeTo == AState::JumpAttack) 
		this->mAladdinState.at(changeTo)->SetVelocity(0,this->mAladdinState.at(mCurrentState)->GetVelocity().y);
	else if (mCurrentState == AState::JumpAttack && changeTo == AState::RunAndJump)
	{
		this->mAladdinState.at(changeTo)->SetVelocity(0, this->mAladdinState.at(mCurrentState)->GetVelocity().y);
		this->mAladdinState.at(changeTo)->GoToFrame(4);
	}

	this->mAladdinState.at(mCurrentState)->ResetDefaultVelocity();
}

void AladdinCharacter::_AfterStateChange()
{
	
	//this->mAladdinState.at(mCurrentState)->SetVelocity(this->mAladdinState.at(mCurrentState)->GetVelocity().x, -10);
	switch (this->mCurrentState)
	{
	case AState::DoNothing:
		this->mTime = 0;
		break;
	case AState::Walk:
		this->mTime = 0;
		break;
	case AState::RunAndJump:
		this->mTime = 0;
		break;
	}
}

#pragma endregion

#pragma region GetSet

Direction AladdinCharacter::getDirection()
{
	return this->mDir;
}

void AladdinCharacter::setDirection(Direction dir)
{
	mDir = dir;
}

void AladdinCharacter::setAllowStateChange(bool allow)
{
	this->allowStateChange = allow;
}

bool AladdinCharacter::isGrounded()
{
	return this->mIsGrounded;
}

void AladdinCharacter::SetGrounded(bool allow)
{
	this->mIsGrounded = allow;
}



MyRECT AladdinCharacter::GetBoundingBox()
{
	mBoundingBox.left = mPosition.x - mWidth / 2;
	mBoundingBox.right = mPosition.x + mWidth / 2;

	/*mBoundingBox.top = mPosition.y - mHeight / 2;
	mBoundingBox.bottom = mPosition.y + mHeight / 2;*/

	mBoundingBox.top = mPosition.y + mHeight;
	mBoundingBox.bottom = mPosition.y;


	return mBoundingBox;;
}

AState AladdinCharacter::getCurrentState()
{
	return this->mCurrentState;
}

#pragma endregion

#pragma region Collision

void AladdinCharacter::CheckCollision(float DeltaTime, vector<GameVisibleEntity*> mListObjectInViewPort)
{
	//vector<GameVisibleEntity*> mListGround;

	mListGround.clear();

	for (int i = 0; i < mListObjectInViewPort.size(); i++)
	{
		switch (mListObjectInViewPort.at(i)->GetID())
		{
		case EObjectID::GROUND: //Kiểm tra va chạm với đất
			mListGround.push_back(mListObjectInViewPort.at(i));
			break;
		case EObjectID::CAMEL:
			CollisionResult res = Collision::SweptAABB(DeltaTime, this->GetBoundingBox(), this->mAladdinState.at(mCurrentState)->GetVelocity(), mListObjectInViewPort.at(i)->GetBoundingBox(), D3DXVECTOR2(0, 0));
			if (res.EntryTime < 1 && res.EntryTime >= 0)
			{
				int c = 0;
			}
			break;
		}
	}

	//this->CheckCollisionWithGround(DeltaTime,mListGround);
	
}

void AladdinCharacter::processCollision(float DeltaTime,GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::GROUND:

		if (collision.dir == Direction::Up)
		{
			_yCollision = this->mAladdinState.at(mCurrentState)->GetVelocity().y*collision.EntryTime;

			//printLog("AAAAAAA");
			/*if (this->mCurrentState == (AState::RunAndJump))
			{
				this->allowStateChange = true;
				this->setCurrentState(AState::DoNothing);
			}*/
			

			this->mAladdinState.at(mCurrentState)->SetVelocity(this->mAladdinState.at(mCurrentState)->GetVelocity().x, _yCollision);
			mIsGrounded = true;
			//this->mAladdinState.at(mCurrentState)->SetPosition(this->mAladdinState.at(mCurrentState)->GetPosition().x, this->mAladdinState.at(mCurrentState)->GetPosition().y + _yCollision * DeltaTime);
			//this->mPosition = this->mAladdinState.at(mCurrentState)->GetPosition();

		}
		else  if (collision.dir == Direction::Left) 
		{
			//printLog("Left");
			mWallCollision = true;
			/*if (this->mCurrentState == (AState::Walk))
			{
			this->allowStateChange = true;
			this->mAladdinState.at(AState::Push)->SetPosition(this->mAladdinState.at(AState::Walk)->GetPosition());
			this->mCurrentState = AState::Push;
			}*/
			if (this->mCurrentState == (AState::Push))
			{
				int c = 0;
			}
			this->mAladdinState.at(mCurrentState)->SetVelocity(this->mAladdinState.at(mCurrentState)->GetVelocity().x*collision.EntryTime, this->mAladdinState.at(mCurrentState)->GetVelocity().y);
			//this->mAladdinState.at(mCurrentState)->SetPosition(this->mAladdinState.at(mCurrentState)->GetPosition().x + this->mAladdinState.at(mCurrentState)->GetVelocity().x*collision.EntryTime , this->mAladdinState.at(mCurrentState)->GetPosition().y);
			
			this->mPosition = this->mAladdinState.at(mCurrentState)->GetPosition();
		}

			
		

		break;
	}

	
}

void AladdinCharacter::CheckCollisionWithGround(float DeltaTime, vector<GameVisibleEntity*> mListGround)
{
	mIsGrounded = false;
	mWallCollision = false;

	for (int i = 0; i < mListGround.size(); i++)
	{
		CollisionResult res = Collision::SweptAABB(DeltaTime, this->GetBoundingBox(), this->getCurrentObjectState()->GetVelocity(), mListGround.at(i)->GetBoundingBox(), D3DXVECTOR2(0, 0));
		if (res.EntryTime < 1 && res.EntryTime >= 0)
		{
			this->processCollision(DeltaTime, mListGround.at(i), res);
			//_StandingGround = mListGround.at(i);
			
		}
	/*	else if (this->mBoundingBox.bottom == mListGround.at(i)->GetBoundingBox().top && this->mBoundingBox.left >= mListGround.at(i)->GetBoundingBox().left && this->mBoundingBox.right <= mListGround.at(i)->GetBoundingBox().right && this->mCurrentState != AState::RunAndJump)
		{
			mIsGrounded = true;
		}*/

	}
	
}

#pragma endregion

#pragma region Debug

void AladdinCharacter::PrintLogState()
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
	case AState::SitAttack:
		printLog("SitAttack");
		break;
	case AState::RunAndJump:
		printLog("RunAndJump");
		break;
	case AState::ThrowApple:
		printLog("ThrowApple");
		break;
	case AState::SitThrow:
		printLog("SitThrow");
		break;
	case AState::Push:
		printLog("Push");
		break;
	default:
		printLog("Else");

		break;
	}
}

#pragma endregion





