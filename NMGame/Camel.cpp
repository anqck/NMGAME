#include "Camel.h"

void Camel::Render(float DeltaTime)
{
	this->mSprite->Render();
}

void Camel::Update(float DeltaTime)
{

	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		mCurrentIdx = (mCurrentIdx + mEndIdx - 1) % mEndIdx;
		this->mSprite->SetFrame(mCurrentIdx);
		last_time = now;
	}
}

void Camel::Initialize()
{
	LPD3DXSPRITE temp;

	this->ANIMATE_RATE = 12;
	this->mCurrentIdx = 0;

	this->LoadResource();
}

void Camel::LoadResource()
{


	std::vector<MyRECT> temp;

	temp.push_back(MyRECT(0, 0, 170, 60));
	temp.push_back(MyRECT(61, 0, 170, 121));
	temp.push_back(MyRECT(122, 0, 170, 182));
	temp.push_back(MyRECT(0, 171, 341, 60));
	temp.push_back(MyRECT(61, 171, 341, 121));
	temp.push_back(MyRECT(122, 171, 341, 182));



	this->mEndIdx = temp.size();

	
	this->mSprite = new Sprite( L"Camel.png", D3DCOLOR_XRGB(255, 0, 255), temp);
	this->mSprite->SetPosition(this->mPosition);
}
