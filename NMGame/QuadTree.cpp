#include "QuadTree.h"

#include "GameLog.h"
#include<fstream>

QuadTree::QuadTree()
{
}

QuadTree::~QuadTree()
{
}

void QuadTree::LoadQuadTree(std::string filePath)
{
	std::ifstream file;
	file.open(filePath);

	if (!file.is_open())
	{
		printLog("Can't load QuadTree file");
		return;
	}

	std::string ObjectNumber;
	file >> ObjectNumber;
	int numberOfObject = std::atoi(ObjectNumber.c_str());

	std::string MapWitdh, MapHeight;
	file >> MapWitdh >> MapHeight;

	std::string ObjectKey, EObjectID, PosX, PosY, Top, Left, Right, Bottom;
	
	//Load danh sách các Object trên map
	for (int i = 0; i < numberOfObject; i++)
	{
		file >> ObjectKey >> EObjectID >> PosX >> PosY >> Top >> Left >> Right >> Bottom;
		mListObject[std::atoi(ObjectKey.c_str())] = new CTreeObject(std::atoi(ObjectKey.c_str()), std::atoi(EObjectID.c_str()), D3DXVECTOR3(std::atoi(PosX.c_str()), std::atoi(PosY.c_str()), 0), MyRECT(std::atoi(Top.c_str()), std::atoi(Left.c_str()), std::atoi(Left.c_str()), std::atoi(Left.c_str())));
	}

	
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		int NodeID, Top, Left, Right, Bottom, numberObject, ObjectKey;
		if (!(iss >> NodeID >> Top >> Left >> Right >> Bottom >> numberObject))  
		{
			break;
		} // error

		printLog(line.c_str());
		mMapQuadTree[NodeID] = new QNode(NodeID, MyRECT(Top, Left, Right, Bottom));

		for (int i = 0; i < numberObject; i++)
		{
			iss >> ObjectKey;
			mMapQuadTree.find(NodeID)->second->AddCTreeObject(mListObject.find(ObjectKey)->second);
		}
	}



	for (map<int, QNode *>::iterator it = mMapQuadTree.begin(); it != mMapQuadTree.end(); ++it) {
		if (mMapQuadTree.find(it->second->GetNodeID()* 10) != mMapQuadTree.end()) //Kiểm tra xem node có con không (Node con có nằm trong map)
		{
			mMapQuadTree.find(it->second->GetNodeID())->second->AddChilds(mMapQuadTree.find(it->second->GetNodeID() * 10)->second, mMapQuadTree.find(it->second->GetNodeID() * 10 + 1)->second, mMapQuadTree.find(it->second->GetNodeID() * 10 + 2)->second, mMapQuadTree.find(it->second->GetNodeID() * 10 + 3)->second);
		}
	}
}
