#include "Block.h"

Block::Block()
{
	this->mID = EObjectID::BLOCK;
	this->mCanBeHitByFlyingObject = true;
}

Block::Block(MyRECT bb) : Block()
{
	this->mBoundingBox = bb;
	this->mInteractBoundingBox = bb;
}
