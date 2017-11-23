#include "Rope.h"

Rope::Rope()
{
	this->mID = EObjectID::ROPE;
}

Rope::Rope(MyRECT bb)
{
	this->mBoundingBox = MyRECT(bb.top, bb.left, bb.right, bb.bottom);
	this->mID = EObjectID::ROPE;
	this->mInteractBoundingBox = MyRECT(0, 0, 0, 0);
}
