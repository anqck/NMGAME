#include "AladdinLookUp.h"

void AladdinLookUp::LoadResource()
{
	this->ANIMATE_RATE = 20;
	this->mCurrentIdx = 0;
	this->mEndIdx = 3;

	vector<RECT> temp;
	/*RECT rect;
	rect.top = 1212;
	rect.bottom = 1275;
	rect.left = 60;
	rect.right = 110;
	temp.push_back(rect);*/
	for (int i = 1; i <= 3; i++)
	{
		RECT rect;
		rect.top = 488;
		rect.bottom = 551;
		switch (i)
		{
		case 1:
		{
			rect.left = 7;
			rect.right = 56;
			break;
		}
		case 2:
		{
			rect.left = 56;
			rect.right = 111;
			break;
		}
		case 3:
		{
			rect.left = 109;
			rect.right = 174;
			break;
		}
		}
		temp.push_back(rect);
	}
	this->mSprite = new Sprite(this->mSpriteHandle, L"Aladdin.png", D3DCOLOR_XRGB(255, 0, 255), temp);

}

void AladdinLookUp::Animate()
{
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)

	{
		
			this->mSprite->FlipVertical(this->mIsFlipVertical);

		this->nextFrameWithoutLoop();

		last_time = now;
	}
}
