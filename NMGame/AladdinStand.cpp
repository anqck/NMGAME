#include "AladdinStand.h"

AladdinStand::~AladdinStand()
{
}

void AladdinStand::LoadResource()
{
	vector<MyRECT> temp;
	float top = 0, bottom = 60;

	temp.push_back(MyRECT(top, 0, 45, bottom));
	temp.push_back(MyRECT(top, 44, 90, bottom));
	temp.push_back(MyRECT(top, 93, 142, bottom));
	temp.push_back(MyRECT(top, 141, 195, bottom));
	temp.push_back(MyRECT(top, 191, 241, bottom));
	temp.push_back(MyRECT(top, 243, 294, bottom));
	temp.push_back(MyRECT(top, 295, 349, bottom));
	temp.push_back(MyRECT(top, 243, 294, bottom));
	temp.push_back(MyRECT(top, 191, 241, bottom));

	this->ANIMATE_RATE = 7;
	this->mCurrentIdx = 0;
	this->mEndIdx = temp.size();

	this->mSprite = new Sprite(this->mSpriteHandle, L"Aladdin.png", D3DCOLOR_XRGB(255, 0, 255), temp);
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
