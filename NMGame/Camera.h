#pragma once
#ifndef __CAMERA_H__
#define __CAMERA_H__
#include "Global.h"
#include "GraphicsHelper.h"
#include "AladdinCharacter.h"

#define DELTA_CAMERA 15

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

	MyRECT					GetBoundingBoxInWorldAxis();

private:
	static Camera*			mInstance;

	D3DXVECTOR3				mPosition;
	int						mWidth, mHeight;

	D3DXVECTOR2				mVelocity;

	float					cameraX, cameraY; //Center of camera
	float					halfWidth, halfHeight;


	Direction				preDir; //Lưu lại hướng của Aladdin trước đó trong TH có đổi hướng


	void					NomalizeCamera(); //Chuẩn hóa camera khi vượt ra khỏi giới hạn của map;
};
#endif __CAMERA_H__