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
