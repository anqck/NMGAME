#include "Stair.h"

Stair::Stair()
{
	this->mID = EObjectID::STAIR;
	this->mCanBeHitByFlyingObject = true;
}

Stair::Stair(MyRECT bb) : Stair()
{
	this->mBoundingBox = bb;
	this->mInteractBoundingBox = bb;
}
