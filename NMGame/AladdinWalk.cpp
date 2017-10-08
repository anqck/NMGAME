#include "AladdinWalk.h"



void AladdinWalk::Initialize()
{
	
}

void AladdinWalk::LoadResource()
{
	this->ANIMATE_RATE = 16;
	this->mCurrentIdx = 0;
	this->mEndIdx = 13;


	vector<MyRECT> temp;
	/*RECT rect;
	rect.top = 1212;
	rect.bottom = 1275;
	rect.left = 60;
	rect.right = 110;
	temp.push_back(rect);*/
	for (int i = 1; i <= 13; i++)
	{
		MyRECT rect;
		rect.top = 1212;
		rect.bottom = 1275;
		switch (i)
		{
		case 1:
		{
			rect.left = 9;
			rect.right = 57;
			break;
		}
		case 2:
		{
			rect.left = 60;
			rect.right = 112;
			break;
		}
		case 3:
		{
			rect.left = 117;
			rect.right = 163;
			break;
		}
		case 4:
		{
			rect.left = 161;
			rect.right = 215;
			break;
		}
		case 5:
		{
			rect.left = 216;
			rect.right = 277;
			break;
		}
		case 6:
		{
			rect.left = 276;
			rect.right = 331;
			break;
		}
		case 7:
		{
			rect.left = 329;
			rect.right = 383;
			break;
		}
		case 8:
		{
			rect.left = 378;
			rect.right = 432;
			break;
		}
		case 9:
		{
			rect.left = 429;
			rect.right = 485;
			break;
		}
		case 10:
		{
			rect.left = 486;
			rect.right = 541;
			break;
		}
		case 11:
		{
			rect.left = 544;
			rect.right = 607;
			break;
		}
		case 12:
		{
			rect.left = 607;
			rect.right = 670;
			break;
		}
		case 13:
		{
			rect.left = 670;
			rect.right = 727;
			break;
		}
		}
		temp.push_back(rect);
	}
	this->mSprite = new Sprite(this->mSpriteHandle, L"Aladdin.png", D3DCOLOR_XRGB(255, 0, 255), temp);
}

void AladdinWalk::Update(float DeltaTime)
{
	this->Animate(DeltaTime);
	this->SetVelocity(((!this->GetFlipVertical()) ? (1.0f) : (-1.0f)) * 0.5f, .0f);
	this->Move(DeltaTime);

}
