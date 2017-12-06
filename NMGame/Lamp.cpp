#include "Lamp.h"
#include "AladdinCharacter.h"
#include "Camera.h"

Lamp::Lamp()
{
	this->mID = EObjectID::LAMP;

	this->mCanBeHitByFlyingObject = false;
	this->mInteractWithInteractBB = true;

	mWidth = 30;
	mHeight = 30;

	this->mBoundingBox = MyRECT(0, 0, 0, 0);
	
	this->mCollisioned = false;

	this->mDone = false;
}

Lamp::Lamp(D3DXVECTOR3 pos, MyRECT bb) : Lamp()
{
	this->mInteractBoundingBox = bb;

	this->mPosition = pos;

	this->mCurrentState = LampState::LampState_Normal;

	std::vector<MyRECT> temp;

	temp.push_back(MyRECT(0, 0, 32, 16));
	this->mState.push_back(new ObjectState(temp, 13, L"Object\\Lamp.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	temp.push_back(MyRECT(164, 54, 80, 188));
	temp.push_back(MyRECT(49, 252, 312, 98));
	temp.push_back(MyRECT(77, 0, 82, 163));
	temp.push_back(MyRECT(74, 84, 166, 154,D3DXVECTOR3(0,3,0)));
	temp.push_back(MyRECT(0, 0, 83, 76, D3DXVECTOR3(0, 4, 0)));
	temp.push_back(MyRECT(0, 84, 167, 73, D3DXVECTOR3(0, 4, 0)));
	temp.push_back(MyRECT(136, 167, 247, 206, D3DXVECTOR3(0, 6, 0)));
	temp.push_back(MyRECT(63, 168, 250, 135, D3DXVECTOR3(0, 4, 0)));
	temp.push_back(MyRECT(0, 168, 251, 62, D3DXVECTOR3(0, 9, 0)));
	temp.push_back(MyRECT(155, 83, 164, 208, D3DXVECTOR3(0, 14, 0)));
	temp.push_back(MyRECT(0, 252, 329, 48, D3DXVECTOR3(0, 20, 0)));
	temp.push_back(MyRECT(164, 0, 53, 205, D3DXVECTOR3(0, 24, 0)));
	temp.push_back(MyRECT(99, 251, 293, 138, D3DXVECTOR3(4, 26, 0)));
	temp.push_back(MyRECT(139, 248, 268, 172, D3DXVECTOR3(0, 29, 0)));

	this->mState.push_back(new ObjectState(temp, 21, L"Object\\LampDisappear.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));


	this->mState.at(0)->SetPosition(pos);
	this->mState.at(1)->SetPosition(pos);
	temp.clear();
}

Lamp::~Lamp()
{
}

void Lamp::ResetDefault()
{
	mWidth = 30;
	mHeight = 30;

	this->mDone = false;
	this->mCollisioned = false;

	this->mCurrentState = LampState::LampState_Normal;
}

void Lamp::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

void Lamp::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	//this->mInteractBoundingBox = MyRECT(Camera::GetInstance()->GetPosition().y - 30 , Camera::GetInstance()->GetPosition().x + 30, Camera::GetInstance()->GetPosition().x + GLOBAL::GetWindowsWidth() - 30, Camera::GetInstance()->GetPosition().y - GLOBAL::GetWindowsHeight() + 30);

	switch (mCurrentState)
	{
	case LampState::LampState_Normal:

		break;

	case LampState::LampState_Disappear:
	{
		this->mPosition = this->mState.at(mCurrentState)->GetPosition();

		if (this->mState.at(mCurrentState)->isDone())
		{
			mDone = true;
		}

		break;
	}

	}
}

void Lamp::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::ALADDIN:
		if (this->mCurrentState == LampState::LampState_Normal)
		{
			
			this->mCurrentState = LampState::LampState_Disappear;
			this->mState.at(LampState::LampState_Disappear)->resetFrame();
			this->mCollisioned = true;
		}
		

		break;
	}
}

bool Lamp::GetCollisioned()
{
	return this->mCollisioned;
}
