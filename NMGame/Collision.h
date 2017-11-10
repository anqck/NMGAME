#pragma once

#include "MyRECT.h"

class Collision
{
public:
	static Collision*		GetInstance();

	bool					AABB(MyRECT rect1, MyRECT rect2);

private:
	static Collision*		mInstance;


};