#include "AladdinDoNothing.h"

void AladdinDoNothing::LoadResource()
{
	vector<MyRECT> temp;
	float top = 1212, bottom = 1275;
	temp.push_back(MyRECT(top, 9, 57, bottom));


	this->ANIMATE_RATE = 10;
	this->mCurrentIdx = 0;
	this->mEndIdx = temp.size();

	this->mSprite = new Sprite(this->mSpriteHandle, L"Aladdin.png", D3DCOLOR_XRGB(255, 0, 255), temp);
}

void AladdinDoNothing::Update(float DeltaTime)
{
}
