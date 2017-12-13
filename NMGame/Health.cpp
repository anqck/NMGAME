#include "Health.h"
#include "AladdinCharacter.h"
#include "DemoScene.h"
#include "SoundHelper.h"
Health::Health()
{
	this->mID = EObjectID::HEATH;

	mWidth = 30;
	mHeight = 30;

	this->mDone = false;
}

Health::Health(D3DXVECTOR3 pos) : Health()
{
	this->mPosition = pos;

	this->mCurrentState = HealthState::HeathState_Normal;

	std::vector<MyRECT> temp;

	//Normal
	temp.push_back(MyRECT(0, 38, 54, 21));
	temp.push_back(MyRECT(0, 20, 37, 21,D3DXVECTOR3(-1,1,0)));
	temp.push_back(MyRECT(0, 0, 19, 23, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(0, 20, 37, 21, D3DXVECTOR3(-1, 1, 0)));
	this->mState.push_back(new ObjectStateWithLoop(temp, 16, L"Object\\Health.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Disappear
	temp.push_back(MyRECT(31, 37, 42, 39, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(31, 30, 36, 40, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(31, 18, 29, 43, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(30, 0, 17, 46, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(0, 22, 42, 19, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(0, 0, 21, 15, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(13, 43, 62, 27, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(16, 0, 20, 29, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(0, 43, 63, 12, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(20, 21, 37, 30, D3DXVECTOR3(0, 5, 0)));
	this->mState.push_back(new ObjectState(temp, 14, L"Object\\AppleDisappear.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	this->mState.at(0)->SetPosition(mPosition);
	this->mState.at(1)->SetPosition(mPosition);

}

Health::~Health()
{
}

void Health::ResetDefault()
{
	mWidth = 30;
	mHeight = 30;

	this->mDone = false;

	this->mCurrentState = HealthState::HeathState_Normal;
}

void Health::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

void Health::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	switch (mCurrentState)
	{
	case HealthState::HeathState_Normal:


		break;
	case HealthState::HeathState_Disappear:
		if (this->mState.at(mCurrentState)->isDone())
		{
			this->mDone = true;

		}
		break;

	}
}

void Health::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::ALADDIN:
		if (this->mCurrentState == HealthState::HeathState_Normal)
		{
			((DemoScene*)SceneManager::GetInstance()->GetCurrentScene())->AddScore(150);
			((AladdinCharacter *)obj)->AddHP(2);
			this->mCurrentState = HealthState::HeathState_Disappear;
			SoundHelper::GetInstance()->Play("Health_Disappear");
		}
		
		break;
	}
}
