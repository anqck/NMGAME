#include "Peddler.h"

Peddler::Peddler()
{
	this->mInteractWithInteractBB = true;

	mWidth = 100;
	mHeight = 100;

	this->mDone = false;
}

Peddler::Peddler(MyRECT bb, D3DXVECTOR3 pos) : Peddler()
{
	this->mPosition = pos;

	this->mCurrentState = PeddlerState::PeddlerState_Wait;

	this->mInteractBoundingBox = bb;

	std::vector<MyRECT> temp;

	//DoNothing
	temp.push_back(MyRECT(0, 0, 26, 52,D3DXVECTOR3(13,-2,0)));
	this->mState.push_back(new ObjectState(temp, 13, L"Object\\Peddler\\DoNothing.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//DoNothingWithShop
	temp.push_back(MyRECT(0, 0, 123, 70));
	this->mState.push_back(new ObjectState(temp, 14, L"Object\\Peddler\\WithShopDoNothing.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//ShopAppear
	temp.push_back(MyRECT(402, 477, 528, 454, D3DXVECTOR3(36 - 36, 0 - 2, 0)));
	temp.push_back(MyRECT(250, 642, 697, 305, D3DXVECTOR3(35 - 36, 0- 2, 0)));
	temp.push_back(MyRECT(250, 581, 641, 315, D3DXVECTOR3(33 - 36, 0- 2, 0)));
	temp.push_back(MyRECT(164, 617, 698, 249, D3DXVECTOR3(21 - 36, 0- 2, 0)));
	temp.push_back(MyRECT(243, 495, 580, 329, D3DXVECTOR3(19 - 36, 0- 2, 0)));
	temp.push_back(MyRECT(77, 623, 713, 163, D3DXVECTOR3(20 - 36, 0- 2, 0)));
	temp.push_back(MyRECT(150, 524, 616, 236, D3DXVECTOR3(21 - 36, 0- 2, 0)));
	temp.push_back(MyRECT(330, 493, 570, 401, D3DXVECTOR3(34 - 36, 0- 2, 0)));
	temp.push_back(MyRECT(78, 524, 622, 149, D3DXVECTOR3(45 - 36, 0- 2, 0)));
	temp.push_back(MyRECT(0, 639, 735, 70, D3DXVECTOR3(46 - 36, 0- 2, 0)));
	temp.push_back(MyRECT(166, 408, 512, 242, D3DXVECTOR3(47 - 36, -3- 2, 0)));
	temp.push_back(MyRECT(0, 424, 531, 77, D3DXVECTOR3(29 - 17, -3- 2, 0)));
	temp.push_back(MyRECT(0, 532, 638, 76, D3DXVECTOR3(31- 17, 0- 2, 0)));
	temp.push_back(MyRECT(81, 417, 523, 159, D3DXVECTOR3(31- 17, 0- 2, 0)));
	temp.push_back(MyRECT(166, 277, 407, 245, D3DXVECTOR3(25- 17, -3- 2, 0)));
	temp.push_back(MyRECT(71, 147, 285, 146, D3DXVECTOR3(23- 17, -3- 2, 0)));
	temp.push_back(MyRECT(0, 287, 423, 80, D3DXVECTOR3(22- 17, -8- 2, 0)));
	temp.push_back(MyRECT(0, 0, 146, 75, D3DXVECTOR3(18- 17, -8- 2, 0)));
	temp.push_back(MyRECT(0, 147, 286, 70, D3DXVECTOR3(14- 17, -8- 2, 0)));
	temp.push_back(MyRECT(76, 0, 146, 140, D3DXVECTOR3(18- 17, -8- 2, 0)));
	temp.push_back(MyRECT(141, 0, 141, 206, D3DXVECTOR3(15- 17, -8- 2, 0)));
	temp.push_back(MyRECT(207, 0, 129, 266, D3DXVECTOR3(20- 17, -2- 2, 0)));
	temp.push_back(MyRECT(352, 368, 476, 407, D3DXVECTOR3(30- 17, -2- 2, 0)));
	temp.push_back(MyRECT(368, 249, 365, 420, D3DXVECTOR3(26- 17, 1- 2, 0)));
	temp.push_back(MyRECT(246, 378, 494, 294, D3DXVECTOR3(26- 17, 2- 2, 0)));
	temp.push_back(MyRECT(403, 0, 120, 451, D3DXVECTOR3(24- 17, 2- 2, 0)));
	temp.push_back(MyRECT(246, 254, 377, 306, D3DXVECTOR3(24- 17, 2- 2, 0)));
	temp.push_back(MyRECT(267, 0, 126, 328, D3DXVECTOR3(23- 17, 1- 2, 0)));
	temp.push_back(MyRECT(355, 125, 248, 416, D3DXVECTOR3(20- 17, 1- 2, 0)));
	temp.push_back(MyRECT(307, 251, 367, 367, D3DXVECTOR3(24- 17, 2- 2, 0)));
	temp.push_back(MyRECT(295, 378, 492, 351, D3DXVECTOR3(22- 17, 2- 2, 0)));
	temp.push_back(MyRECT(147, 142, 276, 211, D3DXVECTOR3(12- 17, 2- 2, 0)));
	temp.push_back(MyRECT(81, 286, 416, 165, D3DXVECTOR3(14- 17, 2- 2, 0)));
	temp.push_back(MyRECT(329, 0, 124, 402, D3DXVECTOR3(17- 17, 2- 2, 0)));
	temp.push_back(MyRECT(284, 127, 250, 354, D3DXVECTOR3(17- 17, 2- 2, 0)));

	this->mState.push_back(new ObjectState(temp,25, L"Object\\Peddler\\ShopAppear.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Wait
	temp.push_back(MyRECT(57, 87, 115, 112,D3DXVECTOR3(12,-3,0)));
	temp.push_back(MyRECT(0, 0, 28, 56, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(0, 29, 57, 56, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(0, 58, 86, 56, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(0, 87, 115, 56, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(57, 0, 28, 113, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(57, 29, 57, 113, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(57, 58, 86, 113, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(0, 87, 115, 56, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(57, 0, 28, 113, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(57, 29, 57, 113, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(57, 58, 86, 113, D3DXVECTOR3(12, -3, 0)));

	this->mState.push_back(new ObjectState(temp, 14, L"Object\\Peddler\\Wait.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//WaitWithShop
	temp.push_back(MyRECT(57, 87, 115, 112, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(0, 0, 28, 56, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(0, 29, 57, 56, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(0, 58, 86, 56, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(0, 87, 115, 56, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(57, 0, 28, 113, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(57, 29, 57, 113, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(57, 58, 86, 113, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(0, 87, 115, 56, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(57, 0, 28, 113, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(57, 29, 57, 113, D3DXVECTOR3(12, -3, 0)));
	temp.push_back(MyRECT(57, 58, 86, 113, D3DXVECTOR3(12, -3, 0)));

	this->mState.push_back(new ObjectState(temp, 14, L"Object\\Peddler\\WithShopWait.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	this->mState.at(0)->SetPosition(pos);
	this->mState.at(1)->SetPosition(pos);
	this->mState.at(2)->SetPosition(pos);
	this->mState.at(3)->SetPosition(pos);


}

Peddler::~Peddler()
{
}

void Peddler::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	switch (mCurrentState)
	{
	case PeddlerState::PeddlerState_DoNothing:
		if (rand() % 60 == 0)
		{
			this->mCurrentState = PeddlerState::PeddlerState_Wait;
			this->mState.at(mCurrentState)->resetFrame();
		}
		break;
	case PeddlerState::PeddlerState_Wait:
		if (this->mState.at(this->mCurrentState)->isDone())
		{
			this->mCurrentState = PeddlerState::PeddlerState_DoNothing;
		}
		break;
	case PeddlerState::PeddlerState_ShopAppear:
		if (this->mState.at(this->mCurrentState)->isDone()) 
		{
			this->mCurrentState = PeddlerState::PeddlerState_WithShopDoNothing;
		}
		break;
	}
}

void Peddler::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	GraphicsHelper::GetInstance()->DrawBoundingBox(this->GetItem1BoundingBox(), D3DCOLOR_XRGB(255, 255, 255));

	this->mState.at(mCurrentState)->Render();
}

void Peddler::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
	switch (obj->GetID())
	{
	case EObjectID::ALADDIN:
		if (AABBresult == true)
		{
			if (this->mCurrentState == PeddlerState::PeddlerState_DoNothing)
			{
				this->mCurrentState = PeddlerState::PeddlerState_ShopAppear;
				this->mState.at(this->mCurrentState)->resetFrame();
			}
				
		}
		else
		{
			if(this->mCurrentState  != PeddlerState::PeddlerState_Wait)
				this->mCurrentState = PeddlerState::PeddlerState_DoNothing;
		}
	}
}

void Peddler::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
}

MyRECT Peddler::GetItem1BoundingBox()
{
	if (this->mCurrentState == PeddlerState::PeddlerState_WithShopDoNothing)
		return MyRECT(this->GetBoundingBox().top, this->GetBoundingBox().left + 10, this->GetBoundingBox().right - 40, this->GetBoundingBox().bottom);
	else
		return MyRECT(0, 0, 0, 0);
}
