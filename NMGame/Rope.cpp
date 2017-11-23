#include "Rope.h"

Rope::Rope()
{
	this->mID = EObjectID::ROPE;
}

Rope::Rope(MyRECT bb): Rope()
{
	this->mBoundingBox = bb;
	this->mInteractBoundingBox = bb;
}
