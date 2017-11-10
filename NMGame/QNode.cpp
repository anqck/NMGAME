#include "QNode.h"

QNode::QNode()
{
}

QNode::QNode(int id, MyRECT bb)
{
	this->mNodeID = id;
	mBoundingBox = bb;
}

QNode::~QNode()
{
}

int QNode::GetNodeID()
{
	return this->mNodeID;
}

void QNode::AddCTreeObject(CTreeObject *object)
{
	this->mListObject.push_back(object);
}

void QNode::AddChilds(QNode * lt, QNode * rt, QNode * lb, QNode * rb)
{
	this->mChilds.push_back(lt);
	this->mChilds.push_back(rt);
	this->mChilds.push_back(lb);
	this->mChilds.push_back(rt);
}
