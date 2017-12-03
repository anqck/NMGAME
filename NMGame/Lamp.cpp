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
	temp.push_back(MyRECT(74, 84, 166, 154));
	temp.push_back(MyRECT(0, 0, 83, 76));
	temp.push_back(MyRECT(0, 84, 167, 73));
	temp.push_back(MyRECT(136, 167, 247, 206));
	temp.push_back(MyRECT(63, 168, 250, 135));
	temp.push_back(MyRECT(0, 168, 251, 62));
	temp.push_back(MyRECT(155, 83, 164, 208));
	temp.push_back(MyRECT(0, 252, 329, 48));
	temp.push_back(MyRECT(164, 0, 53, 205));
	temp.push_back(MyRECT(99, 251, 293, 138));
	temp.push_back(MyRECT(139, 248, 268, 172));

	this->mState.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\LampDisappear.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));


	this->mState.at(0)->SetPosition(pos);
	this->mState.at(1)->SetPosition(pos);
	temp.clear();
}

Lamp::~Lamp()
{
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
		//((AladdinCharacter *)obj)->AddApple(1);
		this->mCurrentState = LampState::LampState_Disappear;
		this->mCollisioned = true;

		break;
	}
}

bool Lamp::GetCollisioned()
{
	return this->mCollisioned;
}
