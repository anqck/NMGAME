#include "StoppingDust.h"

StoppingDust::StoppingDust()
{
}

StoppingDust::StoppingDust(D3DXVECTOR3 pos, Direction dir)
{
	this->mPosition = pos;
	this->mDone = 0;

	this->mDir = dir;

	vector<MyRECT> temp;

	temp.push_back(MyRECT(14, 83, 93, 20));
	temp.push_back(MyRECT(0, 83, 109, 13));
	temp.push_back(MyRECT(34, 79, 111, 51));
	temp.push_back(MyRECT(72, 39, 76, 93));
	temp.push_back(MyRECT(72, 0, 38, 98));
	temp.push_back(MyRECT(0, 42, 82, 33));
	temp.push_back(MyRECT(0, 0, 41, 34));
	temp.push_back(MyRECT(35, 0, 39, 71));
	temp.push_back(MyRECT(35, 40, 78, 71));
	temp.push_back(MyRECT(52, 79, 101, 82));
	mState = new ObjectState(temp, 20, L"AladdinCharacter\\StoppingDust.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom);
	temp.clear();
	this->mState->SetPosition(pos);

}

StoppingDust::~StoppingDust()
{
	delete mState;
}

void StoppingDust::Update(float DeltaTime)
{
	this->mState->SetFlipVertical((mDir == Direction::Right) ? (false) : (true));
	this->mState->Update(DeltaTime);
}

void StoppingDust::Render(float DeltaTime)
{
	this->mState->Render();
}

bool StoppingDust::isDone()
{
	return mState->isDone();
}
