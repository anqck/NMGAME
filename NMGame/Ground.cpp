#include "Ground.h"

Ground::Ground()
{
	this->mID = EObjectID::GROUND;
}

Ground::Ground(MyRECT bb)
{
	this->mID = EObjectID::GROUND;
	this->mBoundingBox = MyRECT(bb.top,bb.left,bb.right,bb.bottom);
	this->mInteractBoundingBox = MyRECT(0, 0, 0, 0);
}
