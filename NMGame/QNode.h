#pragma once

#include <vector>
#include "GameVisibleEntity.h"
#include "CTreeObject.h"

class QNode
{
public:
	QNode();
	~QNode();

protected:
	QNode**							mChilds;

	MyRECT							mBoundingBox;

	int								mNodeID;
	std::vector<CTreeObject*>		mListObject;
};