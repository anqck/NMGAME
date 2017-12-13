#include "AbuToken.h"

#include "DemoScene.h"
AbuToken::AbuToken()
{
	this->mID = EObjectID::MONKEY;

	this->mCanBeHitByFlyingObject = false;

	mWidth = 30;
	mHeight = 30;

	this->mDone = false;
}

AbuToken::AbuToken(D3DXVECTOR3 pos) : AbuToken()
{
	this->mPosition = pos;

	this->mCurrentState = AbuTokenState::AbuTokenState_1;

	std::vector<MyRECT> temp;

	temp.push_back(MyRECT(105, 71, 90, 124));
	temp.push_back(MyRECT(83, 71, 90, 104));
	temp.push_back(MyRECT(85, 0, 37, 122,D3DXVECTOR3(2,-13,0)));
	temp.push_back(MyRECT(0, 76, 113, 41, D3DXVECTOR3(-1, -12, 0)));
	temp.push_back(MyRECT(0, 0, 37, 42, D3DXVECTOR3(-4, -12, 0)));
	temp.push_back(MyRECT(0, 38, 75, 42, D3DXVECTOR3(-4, -13, 0)));
	temp.push_back(MyRECT(43, 0, 37, 84, D3DXVECTOR3(-1, -12, 0)));
	temp.push_back(MyRECT(43, 38, 75, 82, D3DXVECTOR3(2, -9, 0)));
	temp.push_back(MyRECT(42, 76, 108, 78, D3DXVECTOR3(2, -7, 0)));
	temp.push_back(MyRECT(83, 38, 70, 119, D3DXVECTOR3(2, -12, 0)));
	temp.push_back(MyRECT(79, 91, 110, 98));
	this->mState.push_back(new ObjectStateWithLoop(temp, 13, L"Object\\AbuToken\\1.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	temp.push_back(MyRECT(0, 55, 74, 19));
	temp.push_back(MyRECT(27, 20, 39, 48));
	temp.push_back(MyRECT(27, 0, 19, 50, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, 32, 26, D3DXVECTOR3(-2, 0, 0)));
	temp.push_back(MyRECT(0, 33, 54, 24, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(25, 40, 59, 45));
	temp.push_back(MyRECT(0, 75, 94, 19));
	this->mState.push_back(new ObjectState(temp, 13, L"Object\\AbuToken\\2.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();



	temp.push_back(MyRECT(101, 209, 228, 121));
	temp.push_back(MyRECT(135, 171, 197, 162,D3DXVECTOR3(0,-2,0)));
	temp.push_back(MyRECT(135, 198, 224, 162, D3DXVECTOR3(0, -2, 0)));
	temp.push_back(MyRECT(51, 200, 230, 80, D3DXVECTOR3(2, -2, 0)));
	temp.push_back(MyRECT(103, 79, 122, 146, D3DXVECTOR3(-1, -10, 0)));
	temp.push_back(MyRECT(162, 131, 169, 199, D3DXVECTOR3(-2, -6, 0)));
	temp.push_back(MyRECT(103, 0, 78, 146, D3DXVECTOR3(0, -8, 0)));
	temp.push_back(MyRECT(50, 0, 108, 102, D3DXVECTOR3(0, -13, 0)));
	temp.push_back(MyRECT(51, 109, 199, 98, D3DXVECTOR3(0, -7, 0)));
	temp.push_back(MyRECT(0, 111, 219, 50, D3DXVECTOR3(0, -14, 0)));
	temp.push_back(MyRECT(0, 0, 110, 49, D3DXVECTOR3(1, -14, 0)));
	temp.push_back(MyRECT(147, 44, 87, 186, D3DXVECTOR3(0, -4, 0)));
	temp.push_back(MyRECT(99, 123, 166, 136, D3DXVECTOR3(0, -4, 0)));
	temp.push_back(MyRECT(147, 88, 130, 184, D3DXVECTOR3(0, -4, 0)));
	temp.push_back(MyRECT(147, 0, 43, 191, D3DXVECTOR3(0, -10, 0)));
	temp.push_back(MyRECT(99, 167, 208, 134, D3DXVECTOR3(0, -5, 0)));
	temp.push_back(MyRECT(185, 88, 128, 209, D3DXVECTOR3(1, 4, 0)));
	temp.push_back(MyRECT(137, 131, 170, 161, D3DXVECTOR3(1, 5, 0)));
	temp.push_back(MyRECT(187, 44, 69, 207, D3DXVECTOR3(0, 8, 0)));
	temp.push_back(MyRECT(81, 209, 229, 100, D3DXVECTOR3(0, 8, 0)));
	this->mState.push_back(new ObjectState(temp, 18, L"Object\\Explosion.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	this->mState.at(0)->SetPosition(pos);
	this->mState.at(1)->SetPosition(pos);
	this->mState.at(2)->SetPosition(pos);
}

AbuToken::~AbuToken()
{
}

void AbuToken::ResetDefault()
{
	mWidth = 30;
	mHeight = 30;

	this->mDone = false;
	this->mCurrentState = AbuTokenState::AbuTokenState_1;

	this->mState.at(AbuTokenState::AbuTokenState_Disappear)->resetFrame();
}

void AbuToken::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

void AbuToken::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);

	switch (mCurrentState)
	{
	case AbuTokenState::AbuTokenState_2:
		if (this->mState.at(this->mCurrentState)->isDone())
			if (rand() % 70 == 0)
			{
				this->mState.at(AbuTokenState::AbuTokenState_1)->resetFrame();
				this->mCurrentState = AbuTokenState::AbuTokenState_1;
			}
		break;
	case AbuTokenState::AbuTokenState_1:
		if (this->mState.at(this->mCurrentState)->isDone())
		{
			this->mState.at(AbuTokenState::AbuTokenState_2)->resetFrame();
			this->mCurrentState = AbuTokenState::AbuTokenState_2;
		}
		break;
	case AbuTokenState::AbuTokenState_Disappear:
		if (this->mState.at(this->mCurrentState)->isDone())
		{
			this->mDone = true;

		}
	}
}

void AbuToken::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::ALADDIN:
		if (this->mCurrentState == AbuTokenState::AbuTokenState_1 || this->mCurrentState == AbuTokenState::AbuTokenState_2)
		{
			((DemoScene*)SceneManager::GetInstance()->GetCurrentScene())->AddScore(150);
			this->mCurrentState = AbuTokenState::AbuTokenState_Disappear;
			SoundHelper::GetInstance()->Play("GenieToken_Disappear");
			SoundHelper::GetInstance()->Play("GenieToken_Wow");
		}
		break;
	}
}
