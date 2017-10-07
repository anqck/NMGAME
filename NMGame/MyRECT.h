#pragma once

#include"Global.h"

class MyRECT :public RECT
{
public:
	MyRECT();
	MyRECT(float top, float left, float right, float bottom);
	~MyRECT();
};