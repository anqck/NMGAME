#include "ObjectStateWithLoop.h"

void ObjectStateWithLoop::nextFrame()
{
	if (this->ResetFlag)
	{
		flagLoop = false;
		ResetFlag = false;
		return;
	}

	if (flagLoop)
	{
		if (mCurrentIdx == mEndIdx - 1 )
			mCurrentIdx = this->mStartLoopIdx;
		else
			mCurrentIdx += 1;
		//mCurrentIdx = (mCurrentIdx + mEndIdx - 1) % (mEndIdx -4) + 4;
		//printLog( std::to_string(mCurrentIdx).c_str());
	}
	else
	{
		mCurrentIdx = mCurrentIdx + 1 ;

		if (this->GetCurrentIdx()  == this->GetEndIdx() - 1)
		{
			flagLoop = true;

		}
		
	}


	this->mSprite->SetFrame(mCurrentIdx);
}

void ObjectStateWithLoop::GoToFrame(int idx)
{
	ResetFlag = false;
	this->mCurrentIdx = idx;
	this->mSprite->SetFrame(idx);
	//if(this->mStartLoopIdx >= this->mStartLoopIdx)
}

bool ObjectStateWithLoop::isDone()
{
	return (this->mCurrentIdx == this->mEndIdx - 1);
}

