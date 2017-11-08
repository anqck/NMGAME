#include "MyRECT.h"

MyRECT::MyRECT()
{
	MyRECT(0, 0, 0, 0);
}

MyRECT::MyRECT(float top, float left, float right, float bottom)
{



	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
}

MyRECT::~MyRECT()
{
}

D3DXVECTOR3 MyRECT::GetCenterArchorPosision(CenterArchor mCenterArchor)
{
	switch (mCenterArchor)
	{
	case CenterArchor::CenterBottom:
		return D3DXVECTOR3((this->right - this->left) / 2, (this->bottom - this->top), 0);
	case CenterArchor::TopLeft:
		return D3DXVECTOR3(0, 0, 0);
	case CenterArchor::Center:
		return D3DXVECTOR3((this->right - this->left) / 2, (this->bottom - this->top)/2, 0);
	default:
		return D3DXVECTOR3(0, 0, 0);
	}
	
}
