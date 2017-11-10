#pragma once

#include <vector>
#include "GameVisibleEntity.h"
#include "CTreeObject.h"

class QNode
{
public:
	QNode();
	QNode(int id, MyRECT  bb);
	~QNode();

	int								GetNodeID();

	void							AddCTreeObject(CTreeObject *object);
	void							AddChilds(QNode* lt, QNode* rt, QNode* lb, QNode* rb);

	QNode*							GetLT();
	QNode*							GetRT();
	QNode*							GetLB();
	QNode*							GetRB();

	MyRECT							GetBoundingBox();

	vector<CTreeObject*>			GetListCTreeObject();
protected:
	vector<QNode*>					mChilds;

	MyRECT							mBoundingBox;

	int								mNodeID;
	std::vector<CTreeObject*>		mListObject;
};