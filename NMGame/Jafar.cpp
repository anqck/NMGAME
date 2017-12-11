#include "Jafar.h"

Jafar::Jafar()
{
	this->mCanBeAttack = true;
	this->mCanBeHitByFlyingObject = true;
	this->mInteractWithInteractBB = true;
	this->mCanBeHitByFlyingObject = true;
	this->mCanAttack = true;

	this->mDir = Direction::Right;
	this->mID = EObjectID::BOSS_JAFAR;

	this->mDone = false;

	this->mCurrentState = JafarState::JafarState_Hut;
		
	mWidth = 10;
	mHeight = 140;

	this->mHP = 15;

}

Jafar::Jafar(D3DXVECTOR3 pos, AladdinCharacter* aladdin) : Jafar()
{
	this->mPosition = pos;

	vector<MyRECT> temp;

	//DoNothing
	temp.push_back(MyRECT(0, 312, 369, 70));
	this->mState.push_back(new ObjectState(temp, 20, L"Object\\Boss\\Jafar.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();


	//Hut
	temp.push_back(MyRECT(0, 312, 369, 70));
	temp.push_back(MyRECT(72, 279, 334, 141,D3DXVECTOR3(-1,0,0)));
	temp.push_back(MyRECT(143, 203, 254, 211, D3DXVECTOR3(-3, 0, 0)));
	temp.push_back(MyRECT(140, 0, 68, 209, D3DXVECTOR3(7, 0, 0)));
	temp.push_back(MyRECT(0, 83, 165, 69, D3DXVECTOR3(13, 0, 0)));
	temp.push_back(MyRECT(70, 83, 151, 139, D3DXVECTOR3(7, 0, 0)));
	temp.push_back(MyRECT(0, 166, 248, 69, D3DXVECTOR3(13, 0, 0)));
	temp.push_back(MyRECT(140, 69, 137, 209, D3DXVECTOR3(7, 0, 0)));
	temp.push_back(MyRECT(70, 0, 82, 139, D3DXVECTOR3(13, 0, 0)));
	temp.push_back(MyRECT(70, 152, 220, 139, D3DXVECTOR3(7, 0, 0)));
	temp.push_back(MyRECT(0, 0, 82, 69, D3DXVECTOR3(13, 0, 0)));
	temp.push_back(MyRECT(140, 138, 202, 209, D3DXVECTOR3(5, 0, 0)));
	temp.push_back(MyRECT(0, 249, 311, 71, D3DXVECTOR3(4, 0, 0)));
	temp.push_back(MyRECT(72, 221, 278, 142));
	this->mState.push_back(new ObjectStateWithLoop(temp, 10, L"Object\\Boss\\Jafar.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));

	temp.clear();

	this->mState.at(0)->SetPosition(pos);
	this->mState.at(1)->SetPosition(pos);

}

Jafar::~Jafar()
{
}

void Jafar::ResetDefault()
{
}

void Jafar::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	//if(mAladdin->Ge)
	this->mState.at(mCurrentState)->SetFlipVertical(((mDir == Direction::Right) ? (false) : (true)));
}

void Jafar::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

void Jafar::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
}

void Jafar::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
}

MyRECT Jafar::GetAttackRange()
{
	return MyRECT();
}

MyRECT Jafar::GetAttackBoundingBox()
{
	return MyRECT();
}

D3DXVECTOR2 Jafar::GetVelocity()
{
	return D3DXVECTOR2();
}

bool Jafar::isDone()
{
	return false;
}
