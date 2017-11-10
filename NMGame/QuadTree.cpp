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
	std::fstream file;
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


}
