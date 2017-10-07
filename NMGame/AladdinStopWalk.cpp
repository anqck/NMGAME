#include "AladdinStopWalk.h"

void AladdinStopWalk::LoadResource()
{
	vector<MyRECT> temp;
	float top = 1280, bottom = 1353;

	temp.push_back(MyRECT(top, 8, 70, bottom));
	temp.push_back(MyRECT(top, 81, 130, bottom));
	temp.push_back(MyRECT(top, 128, 187, bottom));
	temp.push_back(MyRECT(top, 194, 249, bottom));
	temp.push_back(MyRECT(top, 254, 301, bottom));
	temp.push_back(MyRECT(top, 301, 365, bottom));
	temp.push_back(MyRECT(top, 374, 428, bottom));
	temp.push_back(MyRECT(top, 431, 484, bottom));
	temp.push_back(MyRECT(top, 487, 550, bottom));

	this->ANIMATE_RATE = 20;
	this->mCurrentIdx = 0;
	this->mEndIdx = temp.size();

	this->mSprite = new Sprite(this->mSpriteHandle, L"Aladdin.png", D3DCOLOR_XRGB(255, 0, 255), temp);
}

void AladdinStopWalk::Animate(float DeltaTime)
{
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)

	{

		this->mSprite->FlipVertical(this->mIsFlipVertical);

		this->nextFrameWithoutLoop();

		last_time = now;


	}
}
