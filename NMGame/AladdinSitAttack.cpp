#include "AladdinSitAttack.h"

void AladdinSitAttack::LoadResource()
{
	vector<MyRECT> temp;
	float top = 630, bottom = 674;
	temp.push_back(MyRECT(top, 4, 58, bottom));
	temp.push_back(MyRECT(top, 62, 112, bottom));
	temp.push_back(MyRECT(top, 113, 189, bottom));
	temp.push_back(MyRECT(top, 190, 287, bottom));
	temp.push_back(MyRECT(top, 297, 383, bottom));
	temp.push_back(MyRECT(top, 390, 465, bottom));
	temp.push_back(MyRECT(top, 473, 522, bottom));

	this->ANIMATE_RATE = 20;
	this->mCurrentIdx = 0;
	this->mEndIdx = temp.size();

	this->mSprite = new Sprite( L"Aladdin.png", D3DCOLOR_XRGB(255, 0, 255), temp);
}

void AladdinSitAttack::Animate(float DeltaTime)
{
  	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)

	{

		this->mSprite->FlipVertical(this->mIsFlipVertical);

		this->nextFrameWithoutLoop();

		last_time = now;


	}
}
