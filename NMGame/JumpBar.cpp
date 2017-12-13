#include "JumpBar.h"
#include "SoundHelper.h"
JumpBar::JumpBar()
{
	this->mID = EObjectID::JUMPBAR;

	mWidth = 110;
	mHeight = 60;
}

JumpBar::JumpBar(MyRECT bb, D3DXVECTOR3 pos) : JumpBar()
{
	this->mBoundingBox = MyRECT(bb.top - 20,bb.left,bb.right,bb.bottom + 10);
	this->mInteractBoundingBox = bb;

 	this->mPosition = pos;

	this->mCurrentState = JumpBarState::JumpBarState_Normal;

	std::vector<MyRECT> temp;

	//Normal
	temp.push_back(MyRECT(0, 0, 43, 18));
	this->mState.push_back(new ObjectState(temp, 13, L"Object\\StaticObject\\JumpBar.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//JumpOn
	temp.push_back(MyRECT(71, 42, 82, 86, D3DXVECTOR3(-1, -8, 0)));
	temp.push_back(MyRECT(46, 45, 85, 70,D3DXVECTOR3(-1,0,0)));
	temp.push_back(MyRECT(0, 45, 88, 24, D3DXVECTOR3(0, -7, 0)));
	temp.push_back(MyRECT(55, 0, 41, 76, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(23, 0, 44, 38, D3DXVECTOR3(1, -1, 0)));
	temp.push_back(MyRECT(77, 0, 41, 98, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(39, 0, 44, 54, D3DXVECTOR3(1, -1, 0)));
	temp.push_back(MyRECT(0, 0, 44, 22, D3DXVECTOR3(1, 0, 0)));
	temp.push_back(MyRECT(25, 45, 87, 45));
	this->mState.push_back(new ObjectState(temp, 14, L"Object\\StaticObject\\JumpBar_JumpOn.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	temp.push_back(MyRECT(54, 44, 87, 72));
	temp.push_back(MyRECT(0, 55, 98, 22));
	temp.push_back(MyRECT(23, 55, 98, 44));
	temp.push_back(MyRECT(0, 0, 54, 27,D3DXVECTOR3(6,0,0)));
	temp.push_back(MyRECT(28, 0, 51, 53, D3DXVECTOR3(4, 0, 0)));
	temp.push_back(MyRECT(54, 0, 43, 75));
	this->mState.push_back(new ObjectState(temp,14, L"Object\\StaticObject\\JumpBarShine.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	this->mState.at(0)->SetPosition(pos);
	this->mState.at(1)->SetPosition(pos);
	this->mState.at(2)->SetPosition(pos);

}

JumpBar::~JumpBar()
{
}

void JumpBar::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

void JumpBar::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);

	switch (mCurrentState)
	{
	case JumpBarState::JumpBarState_Normal:
		if (rand() % 50 == 0)
		{
			this->mCurrentState = JumpBarState::JumpBarState_Shine;
			this->mState.at(mCurrentState)->resetFrame();
		}
		break;
	case JumpBarState::JumpBarState_Shine:

	case JumpBarState::JumpBarState_JumpOn:
		if (this->mState.at(mCurrentState)->isDone())
			this->mCurrentState = JumpBarState::JumpBarState_Normal;
	}
}

void JumpBar::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	if (obj->GetID() != EObjectID::ALADDIN)
		return;

	if (collision.dir == Direction::Up)
	{
		this->mCurrentState = JumpBarState::JumpBarState_JumpOn;
		this->mState.at(this->mCurrentState)->resetFrame();
		SoundHelper::GetInstance()->Play("JumpBar_JumpOn", false, 1);
	}
		
}
