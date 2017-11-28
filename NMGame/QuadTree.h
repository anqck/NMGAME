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

	void							ListObjectInViewport(MyRECT viewport, QNode* node);
	vector<GameVisibleEntity*>		GetListObjectInViewport(MyRECT viewport);

	static void						DrawQuadtree(QNode* node);

	QNode*							GetRoot();

private:
	QNode*							mRoot;

	std::map<int, QNode*>			mMapQuadTree;
	std::map<int, CTreeObject*>		mListObject;

	vector<GameVisibleEntity*>		mListObjectInViewport;
	std::map<int, CTreeObject*>		_mListObjectInViewport;




};