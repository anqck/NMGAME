#include "Gem.h"
#include "AladdinCharacter.h"
#include <stdlib.h>

Gem::Gem()
{
	this->mID = EObjectID::GEM;

	mWidth = 30;
	mHeight = 30;
}

Gem::Gem(D3DXVECTOR3 pos) : Gem()
{
	this->mPosition = pos;

	this->mCurrentState = GemState::GemState_Shine;

	std::vector<MyRECT> temp;

	//Normal
	temp.push_back(MyRECT(42, 0, 17, 58));
	this->mState.push_back(new ObjectState(temp, 13, L"Object\\Gem.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Shiny
	temp.push_back(MyRECT(42, 0, 17, 58));
	temp.push_back(MyRECT(24, 18, 35, 40));
	temp.push_back(MyRECT(41, 18, 35, 57));
	temp.push_back(MyRECT(19, 36, 53, 35));
	temp.push_back(MyRECT(24, 0, 17, 41));
	temp.push_back(MyRECT(0, 0, 32, 23,D3DXVECTOR3(2,-3,0)));
	temp.push_back(MyRECT(0, 33, 56, 18, D3DXVECTOR3(3, 0, 0)));
	temp.push_back(MyRECT(36, 36, 53, 52));
	temp.push_back(MyRECT(0, 57, 74, 16));
	this->mState.push_back(new ObjectState(temp, 14, L"Object\\Gem.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Disappear
	temp.push_back(MyRECT(31, 37, 42, 39,D3DXVECTOR3(0,5,0)));
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
	this->mState.at(2)->SetPosition(mPosition);
}

Gem::~Gem()
{
}

void Gem::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

void Gem::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	switch (mCurrentState)
	{
	case GemState::GemState_Normal:

		if (rand() % 50 == 0)
		{
			this->mCurrentState = GemState::GemState_Shine;
			this->mState.at(mCurrentState)->resetFrame();
		}
		break;
	case GemState::GemState_Shine:
		if (this->mState.at(mCurrentState)->isDone())
		{
			this->mCurrentState = GemState::GemState_Normal;
			
		}
		break;
	case GemState::GemState_Disappear:
	
		this->mPosition = this->mState.at(mCurrentState)->GetPosition();
		if (this->mState.at(mCurrentState)->isDone())
		{
			mDone = true;
		}
		break;
	

	}
}

void Gem::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::ALADDIN:
		((AladdinCharacter *)obj)->AddGem(1);
		this->mCurrentState = GemState::GemState_Disappear;


		break;
	}
}
