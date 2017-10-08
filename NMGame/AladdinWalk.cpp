#include "AladdinWalk.h"
#include "GameLog.h"


void AladdinWalk::Initialize()
{
	
}

void AladdinWalk::LoadResource()
{
	this->ANIMATE_RATE = 15;
	this->mCurrentIdx = 0;
	


	vector<MyRECT> temp;

	temp.push_back(MyRECT(117, 42, 82, 165));
	temp.push_back(MyRECT(56, 103, 146, 107));
	temp.push_back(MyRECT(117, 83, 120, 167));
	temp.push_back(MyRECT(0, 0, 55, 58));
	temp.push_back(MyRECT(0, 56, 111, 55));
	temp.push_back(MyRECT(0, 159, 203, 57));
	temp.push_back(MyRECT(59, 189, 230, 112));
	temp.push_back(MyRECT(58, 147, 188, 115));
	temp.push_back(MyRECT(59, 0, 52, 116));
	temp.push_back(MyRECT(0, 112, 158, 54));
	temp.push_back(MyRECT(0, 204, 246, 58));
	temp.push_back(MyRECT(117, 0, 41, 169));
	temp.push_back(MyRECT(116, 121, 155, 170));
	temp.push_back(MyRECT(59, 53, 102, 116));


	this->mEndIdx = temp.size();

	this->mSprite = new Sprite(this->mSpriteHandle, L"AladdinWalk.png", D3DCOLOR_XRGB(255, 0, 255), temp);
}

void AladdinWalk::Update(float DeltaTime)
{
	this->Animate(DeltaTime);
	this->SetVelocity(((!this->GetFlipVertical()) ? (1.0f) : (-1.0f)) * 0.5f, .0f);
	this->Move(DeltaTime);

}

void AladdinWalk::nextFrame()
{
	if (this->ResetFlag)
	{
		flagLoop = false;
		ResetFlag = false;
		return;
	}

	if (flagLoop)
	{
		if (mCurrentIdx == mEndIdx - 1)
			mCurrentIdx = 4;
		else
			mCurrentIdx += 1;
		//mCurrentIdx = (mCurrentIdx + mEndIdx - 1) % (mEndIdx -4) + 4;
		//printLog( std::to_string(mCurrentIdx).c_str());
	}
	else
	{
		if (this->GetCurrentIdx() == 4)
			flagLoop = true;

		mCurrentIdx = (mCurrentIdx + mEndIdx - 1) % mEndIdx;
	}

	
	this->mSprite->SetFrame(mCurrentIdx);
}
