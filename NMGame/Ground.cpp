#include "Ground.h"

Ground::Ground()
{
}

Ground::Ground(MyRECT bb)
{
	this->mBoundingBox = MyRECT(bb.top,bb.left,bb.right,bb.bottom);
}
