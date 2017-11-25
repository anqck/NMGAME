#include "Wall.h"

Wall::Wall()
{
	this->mID = EObjectID::WALL;
	this->mCanBeHitByFlyingObject = true;
}

Wall::Wall(MyRECT bb) :Wall()
{
	this->mBoundingBox = bb;
	this->mInteractBoundingBox = bb;
}
