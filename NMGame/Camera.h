#pragma once
#ifndef __CAMERA_H__
#define __CAMERA_H__
#include "Global.h"
#include "GraphicsHelper.h"
#include "AladdinCharacter.h"

#define DELTA_CAMERA 10

class Camera
{
public:
	static Camera*			GetInstance();
	
	Camera();
	~Camera();

	void					Update(AladdinCharacter* object);

	D3DXVECTOR3				GetPosition();
	void					SetPosition(D3DXVECTOR3 Position);
	void					SetPosition(int X, int Y);

private:
	static Camera*			mInstance;

	D3DXVECTOR3				mPosition;
	D3DXVECTOR2				mVelocity;

	void					NomalizeCamera(); //Chuẩn hóa camera khi vượt ra khỏi giới hạn của map;
};
#endif __CAMERA_H__