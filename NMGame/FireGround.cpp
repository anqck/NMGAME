#include "FireGround.h"
#include "AladdinCharacter.h"

FireGround::FireGround()
{
	this->mInteractWithInteractBB = true;
	this->mCanAttack = true;
	
	mOnFire = false;

	this->mID = EObjectID::FIREGROUND;

	this->mDone = false;

	
	//this->mCurrentState = FireGroundState::FireGroundState_Normal;

}

FireGround::FireGround(MyRECT bb):FireGround()
{
	this->mBoundingBox = this->mInteractBoundingBox = bb;
	
	this->mWidth = bb.right - bb.left;
	this->mHeight = bb.top - bb.bottom;

}

FireGround::~FireGround()
{
}

void FireGround::Update(float DeltaTime)
{
	//this->mState.at(mCurrentState)->Update(DeltaTime);
	//printLog(std::to_string(this->mFireArr.size()).c_str());

	for (int i = 0; i < mFireArr.size(); i++)
	{
		mFireArr.at(i)->Update(DeltaTime,mAladdin->getCurrentObjectState()->GetPosition(), mOnFire);
		if (mFireArr.at(i)->isDone())
		{
			delete mFireArr.at(i);
			mFireArr.erase(mFireArr.begin() + i);
			i--;
		}

	}
	/*switch (mCurrentState)
	{
	case FireGroundState::FireGroundState_Fire:
		{
			if (this->mState.at(mCurrentState)->isDone() && !mOnFire)
				mCurrentState = FireGroundState::FireGroundState_Normal;
		}

		break;
	}*/
}

void FireGround::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	for (int i = 0; i < mFireArr.size(); i++)
	{
		mFireArr.at(i)->Render(DeltaTime);

	}

	//this->mState.at(mCurrentState)->Render();
}

void FireGround::processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::ALADDIN:
		

		if (collisionWith == CollisionWith::InteractBoundingBox)
		{
			
			if (AABBresult)
			{
				mAladdin = ((AladdinCharacter*)obj);

				if ((this->mLastAladdinPosInInteractBox.x + 70  < mAladdin->getCurrentObjectState()->GetPosition().x || this->mLastAladdinPosInInteractBox.x - 70 > mAladdin->getCurrentObjectState()->GetPosition().x)&& (((AladdinCharacter*)obj)->GetBoundingBox().left > this->GetBoundingBox().left - 15) &&(((AladdinCharacter*)obj)->GetBoundingBox().right < this->GetBoundingBox().right + 15))
				{
					this->mLastAladdinPosInInteractBox = ((AladdinCharacter*)obj)->getCurrentObjectState()->GetPosition();
					mCurrentIntersectFire = new Fire(this->mLastAladdinPosInInteractBox);
					mFireArr.push_back(mCurrentIntersectFire);
				}
				mOnFire = true;
			}
			else
			{
				mLastAladdinPosInInteractBox = D3DXVECTOR3(0, 0, 0);
				mOnFire = false;
			}
				

		/*	if (AABBresult == true)
			{

			}*/
			//switch (mCurrentState)
			//{
			//case FireGroundState::FireGroundState_Normal:
			//	if (AABBresult == true)
			//	{
			//		//this->mState.at(FireGroundState::FireGroundState_Fire)->SetPosition(this->mState.at(mCurrentState)->GetPosition());
			//		mCurrentState = FireGroundState::FireGroundState_Fire;
			//	}
			//}
			//break;
			
		}
	}
}

MyRECT FireGround::GetAttackBoundingBox()
{
	for (int i = 0; i < mFireArr.size(); i++)
	{
		if (mFireArr.at(i)->GetAttackBoundingBox().top != 0 && mFireArr.at(i)->GetAttackBoundingBox().bottom != 0)
			return mFireArr.at(i)->GetAttackBoundingBox();

	}
	return MyRECT(0, 0, 0, 0);
}

Fire * FireGround::GetCurrentIntersectFire()
{
	return this->mCurrentIntersectFire;
}

