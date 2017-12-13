#include "LevelCompleteObject.h"

LevelCompleteObject::LevelCompleteObject()
{
	this->mID = EObjectID::LEVELCOMPLETE;
	this->mCanBeHitByFlyingObject = true;
}

LevelCompleteObject::LevelCompleteObject(MyRECT bb) : LevelCompleteObject()
{
	this->mBoundingBox = bb;
	this->mInteractBoundingBox = bb;
}
