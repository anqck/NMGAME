#include "QuadTree.h"

#include "GameLog.h"
#include<fstream>

QuadTree::QuadTree()
{
}

QuadTree::~QuadTree()
{
}

void QuadTree::BuildQuadTree()
{
	std::fstream file;
	file.open("Map\\1.txt");

	if (!file.is_open())
	{
		printLog("Can't load QuadTree file");
		return;
	}
}
