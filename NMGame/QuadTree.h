#pragma once

#include <map>

#include "QNode.h"
#include "CTreeObject.h"



class QuadTree
{
public:
	QuadTree();
	~QuadTree();

	void							BuildQuadTree();


private:
	std::map<int, QNode*>			mRoot;
	std::map<int, CTreeObject*>		mListObject;

};