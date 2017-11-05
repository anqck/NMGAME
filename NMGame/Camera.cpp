#include "Camera.h"


Camera*				Camera::mInstance = NULL;

Camera * Camera::GetInstance()
{
	if (!mInstance)
		Camera::mInstance = new Camera();
	return Camera::mInstance;
}

Camera::~Camera()
{
}
