#include "AladdinSit.h"

void AladdinSit::LoadResource()
{
	vector<MyRECT> temp;
	float top = 498, bottom = 550;
	/*temp.push_back(MyRECT(top, 4, 58, bottom));
	temp.push_back(MyRECT(top, 62, 112, bottom));
	temp.push_back(MyRECT(top, 113, 189, bottom));
	temp.push_back(MyRECT(top, 190, 287, bottom));
	temp.push_back(MyRECT(top, 297, 383, bottom));
	temp.push_back(MyRECT(top, 390, 465, bottom));
	temp.push_back(MyRECT(top, 473, 522, bottom));*/

	temp.push_back(MyRECT(top, 204, 257, bottom));
	temp.push_back(MyRECT(top, 257, 314, bottom));
	temp.push_back(MyRECT(top, 314, 373, bottom));
	temp.push_back(MyRECT(top, 376, 434, bottom));

	this->ANIMATE_RATE = 20;
	this->mCurrentIdx = 0;
	this->mEndIdx = temp.size();

	this->mSprite = new Sprite(this->mSpriteHandle, L"Aladdin.png", D3DCOLOR_XRGB(255, 0, 255), temp);
}

void AladdinSit::Animate(float DeltaTime)
{
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)

	{

		this->mSprite->FlipVertical(this->mIsFlipVertical);

		this->nextFrameWithoutLoop();

		last_time = now;
	}
}
