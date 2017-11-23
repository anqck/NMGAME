#include "Ground.h"

Ground::Ground()
{
	this->mID = EObjectID::GROUND;
	this->mCanBeHitByFlyingObject = true;

}

Ground::Ground(MyRECT bb) : Ground()
{
	this->mBoundingBox = bb;
	this->mInteractBoundingBox = bb;
}
