#include "SlideColumn.h"

SlideColumn::SlideColumn()
{
	this->mID = EObjectID::SLIDECOLUMN;
}

SlideColumn::SlideColumn(MyRECT bb) : SlideColumn()
{
	this->mBoundingBox = bb;
	this->mInteractBoundingBox = bb;
}
