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

	MyRECT							mBound;

	int								mNodeID;
	std::vector<CTreeObject*>		mObject;
};