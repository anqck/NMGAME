#include "Rope.h"

Rope::Rope()
{
}

Rope::Rope(MyRECT bb)
{
	this->mBoundingBox = MyRECT(bb.top, bb.left, bb.right, bb.bottom);
}
