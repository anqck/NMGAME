#include "Camel.h"

Camel::Camel()
{
	this->mID = EObjectID::CAMEL;

	this->mCanBeHitByFlyingObject = true;

	mWidth = 110;
	mHeight = 60;
	
}

Camel::Camel(D3DXVECTOR3 pos) : Camel()
{
	this->mPosition = pos;

	this->mCurrentState = CamelState::DoNothing1;
	
	std::vector<MyRECT> temp;

	temp.push_back(MyRECT(170, 82, 145, 214));
	this->mState.push_back(new ObjectState(temp, 13, L"Object\\Camel.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	temp.push_back(MyRECT(170, 82, 145, 214));
	temp.push_back(MyRECT(170, 0, 81, 224));
	temp.push_back(MyRECT(56, 114, 209, 112, D3DXVECTOR3(3,0,0)));
	temp.push_back(MyRECT(56, 0, 113, 112, D3DXVECTOR3(9, 0, 0)));
	temp.push_back(MyRECT(0, 0, 130, 55, D3DXVECTOR3(18, 0, 0)));
	temp.push_back(MyRECT(0, 131, 241, 46, D3DXVECTOR3(14, 0, 0)));
	temp.push_back(MyRECT(113, 0, 95, 169, D3DXVECTOR3(3, 0, 0)));
	temp.push_back(MyRECT(113, 96, 177, 167));
	temp.push_back(MyRECT(113, 178, 241, 157));


	this->mState.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\Camel.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));


	this->mState.at(0)->SetPosition(pos);
	this->mState.at(1)->SetPosition(pos);
	temp.clear();


}

Camel::~Camel()
{
}

void Camel::Render(float DeltaTime) 
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
	
}

void Camel::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(mTime);

	switch (mCurrentState)
	{
	case CamelState::DoNothing1:
	case CamelState::JumpOn:
		if (this->mState.at(mCurrentState)->isDone())
			this->mCurrentState = CamelState::DoNothing1;
	}
	

}

void Camel::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	if (obj->GetID() != EObjectID::ALADDIN)
		return;

	if(collision.dir == Direction::Up)
		this->mCurrentState = CamelState::JumpOn;
}


