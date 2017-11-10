#include "Camel.h"

Camel::Camel()
{
}

Camel::Camel(D3DXVECTOR3 pos)
{
	this->mPosition = pos;

	this->mCurrentState = CamelState::DoNothing1;

	std::vector<MyRECT> temp;

	temp.push_back(MyRECT(0, 0, 170, 60));
	this->mState.push_back(new ObjectState(temp, 13, L"Object\\Camel.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	temp.push_back(MyRECT(0, 0, 170, 60));
	temp.push_back(MyRECT(61, 0, 170, 121));
	temp.push_back(MyRECT(122, 0, 170, 182));
	temp.push_back(MyRECT(0, 171, 341, 60));
	temp.push_back(MyRECT(61, 171, 341, 121));
	temp.push_back(MyRECT(122, 171, 341, 182));

	this->mState.push_back(new ObjectStateWithLoop(temp, 13, L"Object\\Camel.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));


	this->mState.at(0)->SetPosition(pos);
	this->mState.at(1)->SetPosition(pos);
	temp.clear();
}

Camel::~Camel()
{
}

void Camel::Render(float DeltaTime)
{
	this->mState.at(mCurrentState)->Render();
	
}

void Camel::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(mTime);
}


