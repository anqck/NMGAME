#include "AladdinStand.h"

AladdinStand::~AladdinStand()
{
}

void AladdinStand::LoadResource()
{
	vector<MyRECT> temp;
	float top = 0, bottom = 60;

	temp.push_back(MyRECT(0, 0, 44, 53));
	temp.push_back(MyRECT(54, 0, 42, 105));
	temp.push_back(MyRECT(54, 43, 85, 105));
	temp.push_back(MyRECT(54, 86, 127, 105));
	temp.push_back(MyRECT(0, 45, 89, 53));
	temp.push_back(MyRECT(0, 132, 172, 52));
	temp.push_back(MyRECT(0, 173, 213, 52));
	temp.push_back(MyRECT(0, 90, 131, 47));


	this->ANIMATE_RATE = 7;
	this->mCurrentIdx = 0;
	this->mEndIdx = temp.size();

	this->mSprite = new Sprite( L"AladdinStand.png", D3DCOLOR_XRGB(255, 0, 255), temp);
}

void AladdinStand::Animate(float DeltaTime)
{
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		this->nextFrame();

		last_time = now;

	}
}
