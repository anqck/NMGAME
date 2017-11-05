#include "ViewPort.h"

ViewPort*				ViewPort::mInstance = NULL;

ViewPort * ViewPort::GetInstance()
{
	if (!mInstance)
		ViewPort::mInstance = new ViewPort();
	return ViewPort::mInstance;
}

ViewPort::~ViewPort()
{
}

D3DXVECTOR3 ViewPort::getViewPortPosition(D3DXVECTOR3 worldPosition)
{
	worldPosition.z = 1;
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	matrix._22 = -1.0f;
	matrix._41 = -(this->mPosition.x);
	matrix._42 = this->mPosition.y;
	D3DXVECTOR4 viewPort_position;

	D3DXVec3Transform(&viewPort_position, &worldPosition, &matrix);

	D3DXVECTOR3 position = D3DXVECTOR3(viewPort_position.x, viewPort_position.y, 0);

	return position;
}

void ViewPort::Initialize(int x, int y)
{
	this->mPosition.x = x;
	this->mPosition.y = y;
}
