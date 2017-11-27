#include "StairFlagChange.h"

StairFlagChange::StairFlagChange()
{
	this->mID = EObjectID::STAIRFLAGCHANGE;
}

StairFlagChange::StairFlagChange(MyRECT bb, int change1, int change2) : StairFlagChange()
{
	this->mBoundingBox = bb;
	this->mInteractBoundingBox = bb;

	this->change1 = change1;
	this->change2 = change2;
}
