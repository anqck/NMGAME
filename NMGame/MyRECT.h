#pragma once

#include"Global.h"

enum CenterArchor
{
	TopLeft,
	CenterBottom,
	Center
};

class MyRECT :public RECT
{
public:
	
	MyRECT();
	MyRECT(float top, float left, float right, float bottom);
	~MyRECT();

	D3DXVECTOR3 GetCenterArchorPosision(CenterArchor mCenterArchor);
private:
	
	
};