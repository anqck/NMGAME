#include "JumpBar.h"

JumpBar::JumpBar()
{
	this->mID = EObjectID::JUMPBAR;
}

JumpBar::JumpBar(MyRECT bb) : JumpBar()
{
	this->mBoundingBox = bb;
	this->mInteractBoundingBox = bb;

}

JumpBar::~JumpBar()
{
}

void JumpBar::Render(float DeltaTime)
{
	this->mState.at(mCurrentState)->Render();
}

void JumpBar::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update();
}

void JumpBar::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
}
