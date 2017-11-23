#pragma once


#include "MyRECT.h"

struct CollisionResult
{
	Direction dir;
	float EntryTime;
	float ExitTime;
};

enum CollisionWith
{
	BoundingBox,
	InteractBoundingBox,
	SwordBoundingBox
};


class Collision
{
public:

	//bool					AABB(MyRECT rect1, MyRECT rect2);
	static CollisionResult	SweptAABB(float DeltaTime, MyRECT rect1, D3DXVECTOR2 v1, MyRECT rect2, D3DXVECTOR2 v2);
private:




};