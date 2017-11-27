#include "SwingBar.h"

SwingBar::SwingBar()
{
	this->mID = EObjectID::SWINGBAR;
}

SwingBar::SwingBar(MyRECT bb) : SwingBar()
{
	this->mBoundingBox = bb;
	this->mInteractBoundingBox = bb;
}
