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

QNode * QNode::GetLT()
{
	if (mChilds.size() > 0)
		return mChilds.at(0);
	else
		return NULL;
}

QNode * QNode::GetRT()
{
	return mChilds.at(1);
}

QNode * QNode::GetLB()
{
	return mChilds.at(2);
}

QNode * QNode::GetRB()
{
	return mChilds.at(3);
}

MyRECT QNode::GetBoundingBox()
{
	return this->mBoundingBox;
}

vector<CTreeObject*> QNode::GetListCTreeObject()
{
	return mListObject;
}
