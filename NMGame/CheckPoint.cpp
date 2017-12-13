#include "CheckPoint.h"
#include "AladdinCharacter.h"
#include "SceneManager.h"
#include "SoundHelper.h"

CheckPoint::CheckPoint()
{
	this->mID = EObjectID::CHECKPOINT;

	this->mCanBeHitByFlyingObject = false;

	this->mCurrentState = CheckPointState::CheckPointState_Normal;

	mWidth = 50;
	mHeight = 90;

	this->mLastCheckPointScore = 0;

	this->mBoundingBox = MyRECT(0, 0, 0, 0);
}

CheckPoint::CheckPoint(D3DXVECTOR3 pos) : CheckPoint()
{
	std::vector<MyRECT> temp;

	//Normal
	temp.push_back(MyRECT(0, 0, 20, 33));
	this->mState.push_back(new ObjectState(temp, 13, L"Object\\CheckPoint\\CheckPoint.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Check
	temp.push_back(MyRECT(0, 0, 34, 20));
	temp.push_back(MyRECT(0, 121, 137, 38));
	temp.push_back(MyRECT(70, 91, 111, 103));
	temp.push_back(MyRECT(34, 27, 51, 63));
	temp.push_back(MyRECT(35, 100, 120, 69));
	temp.push_back(MyRECT(35, 52, 75, 69));
	temp.push_back(MyRECT(0, 35, 61, 33));
	temp.push_back(MyRECT(0, 87, 111, 34));
	temp.push_back(MyRECT(70, 70, 90, 104));
	temp.push_back(MyRECT(89, 0, 24, 118));
	temp.push_back(MyRECT(70, 49, 69, 104));
	temp.push_back(MyRECT(64, 25, 48, 98));
	temp.push_back(MyRECT(21, 0, 26, 54));
	temp.push_back(MyRECT(0, 62, 86, 34));
	temp.push_back(MyRECT(55, 0, 24, 88));
	temp.push_back(MyRECT(35, 76, 99, 68));
	this->mState.push_back(new ObjectState(temp, 14, L"Object\\CheckPoint\\Check.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Revise
	temp.push_back(MyRECT(0, 0, 64, 69,D3DXVECTOR3(3,0,0)));
	temp.push_back(MyRECT(0, 65, 123, 66, D3DXVECTOR3(2, 0, 0)));
	temp.push_back(MyRECT(39, 229, 249, 72));
	temp.push_back(MyRECT(0, 229, 252, 38, D3DXVECTOR3(1, 0, 0)));
	temp.push_back(MyRECT(205, 0, 25, 251, D3DXVECTOR3(2, 0, 0)));
	temp.push_back(MyRECT(116, 174, 201, 174, D3DXVECTOR3(-2, 0, 0)));
	temp.push_back(MyRECT(171, 46, 84, 238, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(173, 85, 122, 254, D3DXVECTOR3(2, 0, 0)));
	temp.push_back(MyRECT(88, 90, 132, 172, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(0, 124, 177, 87, D3DXVECTOR3(10, 0, 0)));
	temp.push_back(MyRECT(70, 46, 89, 170, D3DXVECTOR3(-6, 0, 0)));
	temp.push_back(MyRECT(0, 178, 228, 115, D3DXVECTOR3(-15, 0, 0)));
	temp.push_back(MyRECT(70, 0, 45, 204, D3DXVECTOR3(-12, 0, 0)));
	temp.push_back(MyRECT(88, 133, 173, 229, D3DXVECTOR3(-10, 0, 0)));
	this->mState.push_back(new ObjectState(temp, 14, L"Object\\CheckPoint\\Revise.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));


	this->mState.at(0)->SetPosition(pos);
	this->mState.at(1)->SetPosition(pos);
	this->mState.at(2)->SetPosition(pos);
	temp.clear();

	this->mPosition = pos;
}

CheckPoint::~CheckPoint()
{
}

void CheckPoint::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

void CheckPoint::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	//this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	switch (mCurrentState)
	{
	case CheckPointState::CheckPointState_Normal:

		break;

	case CheckPointState::CheckPointState_Check:
	{
		if (this->mState.at(mCurrentState)->isDone())
		{
			//this->mCurrentState = CheckPointState::CheckPointState_Normal;

		}

		break;
	}
	case CheckPointState::CheckPointState_Revise:
	{
		//this->mPosition = this->mState.at(mCurrentState)->GetPosition();

		if (this->mState.at(mCurrentState)->isDone())
		{
			
			this->mCurrentState = CheckPointState::CheckPointState_Check;
		}

		break;
	}

	}
}

void CheckPoint::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::ALADDIN:
		//((AladdinCharacter *)obj)->AddApple(1);
		if (this->mCurrentState == CheckPointState::CheckPointState_Normal)
		{
			this->mCurrentState = CheckPointState::CheckPointState_Check;
			((AladdinCharacter *)obj)->SetLastCheckPoint(this);
			SoundHelper::GetInstance()->Play("CheckPoint_Check");
		}
			


		break;
	}
}

CheckPointState CheckPoint::GetCurrentStateID()
{
	return this->mCurrentState;
}

void CheckPoint::SetScore(int score)
{
	this->mLastCheckPointScore = score;
}

int CheckPoint::GetScore()
{
	return this->mLastCheckPointScore;
}

void CheckPoint::GoToLastCheckPoint()
{
	this->mCurrentState = CheckPointState::CheckPointState_Revise;
	SoundHelper::GetInstance()->Play("CheckPoint_Revise");
}
