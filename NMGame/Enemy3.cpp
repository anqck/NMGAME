#include "Enemy3.h"

Enemy3::Enemy3() : Enemy::Enemy()
{
	this->mCanBeAttack = true;
	this->mCanBeHitByFlyingObject = true;

	this->mID = EObjectID::ENEMY3;

	this->mDone = false;

	this->mCurrentState = Eneymy3State::Eneymy3State_Normal;

	mWidth = 140;
	mHeight = 140;
}

Enemy3::Enemy3(MyRECT bb, D3DXVECTOR3 pos) : Enemy3::Enemy3()
{
	this->mBoundingBox = MyRECT(0, 0, 0, 0);
	this->mInteractBoundingBox = bb;

	this->mCurrentState = Eneymy3State::Eneymy3State_Normal;

	this->mPosition = pos;
	

	vector<MyRECT> temp;

	//Normal
	temp.push_back(MyRECT(83, 108, 156, 164));
	temp.push_back(MyRECT(81, 157, 204, 167));
	temp.push_back(MyRECT(165, 102, 141, 247));
	temp.push_back(MyRECT(83, 56, 107, 161));
	temp.push_back(MyRECT(0, 0, 64, 78));
	temp.push_back(MyRECT(79, 0, 55, 147));
	temp.push_back(MyRECT(0, 191, 247, 80));
	temp.push_back(MyRECT(148, 0, 52, 235));
	temp.push_back(MyRECT(0, 65, 128, 82));
	temp.push_back(MyRECT(162, 53, 101, 241));
	temp.push_back(MyRECT(0, 129, 190, 78));

	this->mState.push_back(new ObjectStateWithLoop(temp, 20, L"Object\\Enemy\\Enemy3.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();

	this->mState.at(mCurrentState)->SetPosition(pos);

}

Enemy3::~Enemy3()
{
}

void Enemy3::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
}

void Enemy3::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}
