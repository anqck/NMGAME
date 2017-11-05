
#pragma once

#include "Global.h"

class ViewPort
{
public:
	static ViewPort*			GetInstance();
	~ViewPort();

	D3DXVECTOR3					getViewPortPosition(D3DXVECTOR3 worldPosition);
	void						Initialize(int x, int y);

private:
	static ViewPort*			mInstance;

	D3DXVECTOR2					mPosition; //Tọa độ gốc của ViewPort

};