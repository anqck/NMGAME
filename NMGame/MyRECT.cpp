#include "MyRECT.h"

MyRECT::MyRECT()
{
	MyRECT(0, 0, 0, 0);
}

MyRECT::MyRECT(float top, float left, float right, float bottom)
{
	centerTranslation = D3DXVECTOR3(0, 0, 0);

	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
}

MyRECT::MyRECT(float top, float left, float right, float bottom, D3DXVECTOR3 translation)
{
	centerTranslation = translation;

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
		return D3DXVECTOR3((this->right - this->left) / 2 - centerTranslation.x, (this->bottom - this->top) + centerTranslation.y, 0);
	case CenterArchor::TopLeft:
		return D3DXVECTOR3(0, 0, 0);
	case CenterArchor::Center:
		return D3DXVECTOR3((this->right - this->left) / 2 + centerTranslation.x, (this->bottom - this->top)/2, 0);
	case CenterArchor::CenterTop:
		return D3DXVECTOR3((this->right - this->left) / 2 - centerTranslation.x , centerTranslation.y, 0);
	default:
		return D3DXVECTOR3(0, 0, 0);
	}
	
}

void MyRECT::setCenterTranslation(int x, int y)
{
	centerTranslation.x = x;
	centerTranslation.y = y;
}

D3DXVECTOR3 MyRECT::getCenterTranslation()
{
	return this->centerTranslation;
}

bool MyRECT::Intersects(MyRECT rect)
{
	return  !(right < rect.left
		|| left > rect.right
		|| bottom > rect.top
		|| rect.bottom > top);;
}
