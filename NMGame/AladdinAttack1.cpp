#include "AladdinAttack1.h"

void AladdinAttack1::LoadResource()
{
	vector<MyRECT> temp;
	float top = 313, bottom = 390;




	temp.push_back( MyRECT(top, 6, 54, bottom));
	temp.push_back( MyRECT(top, 54, 110, bottom));
	temp.push_back( MyRECT(top, 110, 169, bottom));
	temp.push_back( MyRECT(top, 168, 256, bottom));
	temp.push_back( MyRECT(top, 258, 318, bottom));

	this->ANIMATE_RATE = 20;
	this->mCurrentIdx = 0;
	this->mEndIdx = temp.size();

	this->mSprite = new Sprite(this->mSpriteHandle, L"Aladdin.png", D3DCOLOR_XRGB(255, 0, 255), temp);
}

void AladdinAttack1::Animate(float DeltaTime)
{
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)

	{

		this->mSprite->FlipVertical(this->mIsFlipVertical);

		this->nextFrameWithoutLoop();

		last_time = now;

		
	}
}


