#include "FalledSand.h"

FalledSand::FalledSand()
{
}

FalledSand::FalledSand(D3DXVECTOR3 pos)
{
	this->mPosition = pos;
	this->mDone = 0;

	vector<MyRECT> temp;

	temp.push_back(MyRECT(0, 200, 225, 9));
	temp.push_back(MyRECT(96, 146, 202, 109));
	temp.push_back(MyRECT(105, 77, 145, 122));
	temp.push_back(MyRECT(105, 0, 76, 126));
	temp.push_back(MyRECT(69, 97, 183, 95));
	temp.push_back(MyRECT(35, 103, 199, 68));
	temp.push_back(MyRECT(0, 103, 199, 34));
	temp.push_back(MyRECT(68, 0, 96, 104));
	temp.push_back(MyRECT(0, 0, 102, 36));
	temp.push_back(MyRECT(37, 0, 102, 67));
	mState = new ObjectState(temp, 14, L"AladdinCharacter\\FalledSand.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom);
	temp.clear();
	this->mState->SetPosition(pos);
}

FalledSand::~FalledSand()
{
	delete mState;
}

void FalledSand::Update(float DeltaTime)
{
	this->mState->Update(DeltaTime);
}

void FalledSand::Render(float DeltaTime)
{
	this->mState->Render();
}

bool FalledSand::isDone()
{

	return mState->isDone();
}
