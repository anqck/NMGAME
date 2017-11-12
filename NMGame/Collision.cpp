#include "Collision.h"

#include<iostream>
using namespace std;


CollisionResult Collision::SweptAABB(float DeltaTime,MyRECT rect1, D3DXVECTOR2 v1, MyRECT rect2, D3DXVECTOR2 v2)
{
	CollisionResult result;

	//Xét mốc tọa độ tại vật 2. Coi vật 2 đứng yên, vật 1 chuyển động
	v1.x = (v1.x - v2.x) *DeltaTime;
	v1.y = (v1.y - v2.y) *DeltaTime;



	//Khoảng cách ngắn nhất để 2 vật va chạm và kết thúc va chạm
	float xEntry, yEntry;
	float xExit, yExit;


	//Tính 
	if(v1.x > 0.0f)
	{
		xEntry = rect2.left - rect1.right;
		xExit = rect2.right - rect1.left;
	}
	else
	{
		xEntry = rect2.right - rect1.left;
		xExit = rect2.left - rect1.right;
	}

	if (v1.y > 0.0f)
	{
		yEntry = rect2.bottom - rect1.top;
		yExit = rect2.top - rect1.bottom;
	}
	else
	{
		yEntry = rect2.top - rect1.bottom;
		yExit = rect2.bottom - rect1.top;
	}



	//Tính thời gian va chạm và kết thúc va chạm
	float txEntry, tyEntry;
	float txExit, tyExit;

	if (v1.x == 0.0f) //Tránh TH chia cho 0
	{
		txEntry = -numeric_limits<float>::infinity();
		txExit = numeric_limits<float>::infinity();
	}
	else
	{
		txEntry = xEntry / v1.x;
		txExit = xExit / v1.x;
	}

	if (v1.y == 0.0f)
	{
		tyEntry = -numeric_limits<float>::infinity();
		tyExit = numeric_limits<float>::infinity();
	}
	else
	{
		tyEntry = yEntry / v1.y;
		tyExit = yExit / v1.y;
	}

	if (v1.x == 0)
	{
		if (rect1.left > rect2.right || rect1.right < rect2.left)
		{
			result.dir = Direction::None;
			result.EntryTime = 1.0f;
			return result;
		}
	}

	if (v1.y == 0)
	{
		//if (rect1.top > rect2.bottom || rect1.bottom < rect2.top)
		if (rect1.bottom > rect2.top || rect1.top < rect2.bottom)
		{
			result.dir = Direction::None;
			result.EntryTime = 1.0f;
			return result;
		}
	}

	

	//Tính thời gian nhỏ nhất và lớn nhất khi va chạm
	float entryTime = max(txEntry, tyEntry);
	float exitTime = min(txExit, tyExit);

	//Nêu không có va chạm
	if (entryTime > exitTime
		|| (txEntry<0.0f && tyEntry<0.0f)
		||( txEntry>1.0f || tyEntry>1.0f ))
	{
		result.dir = Direction::None;
		result.EntryTime = 1.0f;
		return result;
	}

	//Có va chạm thì xác định hướng va chạm
	if (txEntry > tyEntry)
	{
		if (xEntry < 0.0f) // Bên phải
		{
			result.dir = Direction::Right;
		}
		else //Bên trái
		{
			result.dir = Direction::Left;
		}
	}
	else
	{
		if (yEntry <= 0.0f) // Bên trên
		{
			result.dir = Direction::Up;
		}
		else // Bên dưới
		{
			result.dir = Direction::Down;
		}
	}

	result.EntryTime = entryTime;
	result.ExitTime = exitTime;

	return result;

}
