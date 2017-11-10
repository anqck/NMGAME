#pragma once

#include <map>

#include "QNode.h"
#include "CTreeObject.h"



class QuadTree
{
public:
	QuadTree();
	~QuadTree();

	void							LoadQuadTree(std::string filePath);


private:
	std::map<int, QNode*>			mMapQuadTree;
	std::map<int, CTreeObject*>		mListObject;


};