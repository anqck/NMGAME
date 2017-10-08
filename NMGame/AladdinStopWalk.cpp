#include "AladdinStopWalk.h"

void AladdinStopWalk::LoadResource()
{
	vector<MyRECT> temp;
	float top = 1280, bottom = 1353;

	temp.push_back(MyRECT(0, 56, 110, 57));
	temp.push_back(MyRECT(106, 105, 143, 162));
	temp.push_back(MyRECT(58, 53, 104, 124));
	temp.push_back(MyRECT(53, 155, 202, 118));
	temp.push_back(MyRECT(92, 0, 42, 156));
	temp.push_back(MyRECT(0, 0, 55, 46));
	temp.push_back(MyRECT(47, 0, 52, 91));
	temp.push_back(MyRECT(51, 203, 249, 103));
	temp.push_back(MyRECT(58, 105, 154, 105));
	temp.push_back(MyRECT(0, 111, 162, 52));
	temp.push_back(MyRECT(0, 163, 214, 50));
	temp.push_back(MyRECT(104, 203, 240, 154));



	this->ANIMATE_RATE = 20;
	this->mCurrentIdx = 0;
	this->mEndIdx = temp.size();

	this->mSprite = new Sprite(this->mSpriteHandle, L"WalkStop.png", D3DCOLOR_XRGB(255, 0, 255), temp);
}

void AladdinStopWalk::Animate(float DeltaTime)
{
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)

	{

		//this->mSprite->FlipVertical(this->mIsFlipVertical);

		this->nextFrameWithoutLoop();

		last_time = now;


	}
}
