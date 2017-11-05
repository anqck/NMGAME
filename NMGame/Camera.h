#pragma once

#include "Global.h"


class Camera
{
public:
	static Camera*			GetInstance();
	~Camera();



private:
	static Camera*			mInstance;

	D3DXVECTOR3				mPosition; //Tọa độ gốc của ViewPort
};
