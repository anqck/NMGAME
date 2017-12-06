#include "GenieToken.h"

#include "DemoScene.h"
GenieToken::GenieToken()
{
	this->mID = EObjectID::GENIE;

	this->mCanBeHitByFlyingObject = false;

	mWidth = 30;
	mHeight = 30;

	this->mDone = false;
}

GenieToken::GenieToken(D3DXVECTOR3 pos) : GenieToken()
{
	this->mPosition = pos;

	this->mCurrentState = GenieTokenState::GenieTokenState_Normal;

	std::vector<MyRECT> temp;

	temp.push_back(MyRECT(53, 44, 82, 103));
	this->mState.push_back(new ObjectState(temp, 13, L"Object\\GenieToken.png", D3DXVECTOR2(0, -0.04), CenterArchor::CenterBottom));
	temp.clear();

	temp.push_back(MyRECT(53, 44, 82, 103));
	temp.push_back(MyRECT(0, 46, 89, 52));
	temp.push_back(MyRECT(45, 0, 43, 89));
	temp.push_back(MyRECT(0, 0, 45, 44));
	temp.push_back(MyRECT(0, 0, 45, 44));
	this->mState.push_back(new ObjectState(temp, 14, L"Object\\GenieToken.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	temp.push_back(MyRECT(101, 209, 228, 121));
	temp.push_back(MyRECT(135, 171, 197, 162, D3DXVECTOR3(0, -2, 0)));
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
	temp.clear();
}

GenieToken::~GenieToken()
{
}

void GenieToken::ResetDefault()
{

	mWidth = 30;
	mHeight = 30;

	this->mDone = false;
	this->mCurrentState = GenieTokenState::GenieTokenState_Normal;


	this->mState.at(GenieTokenState::GenieTokenState_Disappear)->resetFrame();

}

void GenieToken::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();

}

void GenieToken::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);

	if (this->mCurrentState != GenieTokenState::GenieTokenState_Disappear)
	{
		if (this->mState.at(mCurrentState)->GetPosition().y <= this->mPosition.y - 15)
		{
			//this->mState.at(mCurrentState)->SetPosition(this->mState.at(mCurrentState)->GetPosition().x, this->mPosition.y - 19);
			this->mState.at(mCurrentState)->SetVelocity(D3DXVECTOR2(0, 0.08));
		}
		else if (this->mState.at(mCurrentState)->GetPosition().y >= this->mPosition.y + 15)
		{
			//this->mState.at(mCurrentState)->SetPosition(this->mState.at(mCurrentState)->GetPosition().x, this->mPosition.y + 19);
			this->mState.at(mCurrentState)->SetVelocity(D3DXVECTOR2(0, -0.04));
		}
	}

	switch (mCurrentState)
	{
	case GenieTokenState::GenieTokenState_Normal:
		//if (this->mState.at(this->mCurrentState)->isDone())



			if (rand() % 200 == 0)
			{
				this->mState.at(GenieTokenState::GenieTokenState_NhayMat)->SetVelocity(this->mState.at(mCurrentState)->GetVelocity());
				this->mState.at(GenieTokenState::GenieTokenState_NhayMat)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
				this->mState.at(GenieTokenState::GenieTokenState_NhayMat)->resetFrame();
				this->mCurrentState = GenieTokenState::GenieTokenState_NhayMat;
			}
		break;
	case GenieTokenState::GenieTokenState_NhayMat:
		

		if (this->mState.at(this->mCurrentState)->isDone())
		{
			this->mState.at(GenieTokenState::GenieTokenState_Normal)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			this->mState.at(GenieTokenState::GenieTokenState_Normal)->resetFrame();
			this->mCurrentState = GenieTokenState::GenieTokenState_Normal;
		}
		break;
	case GenieTokenState::GenieTokenState_Disappear:
		if (this->mState.at(this->mCurrentState)->isDone())
		{
			this->mDone = true;

		}
	}
}

void GenieToken::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::ALADDIN:
		if (this->mCurrentState == GenieTokenState::GenieTokenState_Normal)
		{
			((DemoScene*)SceneManager::GetInstance()->GetCurrentScene())->AddScore(250);
			this->mCurrentState = GenieTokenState::GenieTokenState_Disappear;
		}
		break;
	}
}
