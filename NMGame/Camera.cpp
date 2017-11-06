#include "Camera.h"


Camera*				Camera::mInstance = NULL;

Camera * Camera::GetInstance()
{
	if (!mInstance)
		Camera::mInstance = new Camera();
	return Camera::mInstance;
}

Camera::Camera()
{
	this->mPosition = D3DXVECTOR3(0, 0, 0);
}

Camera::~Camera()
{
}

void Camera::Update(AladdinCharacter* object)
{
	float aladdinX = object->GetPosition().x;
	float aladdinY = object->GetPosition().y;

	float halfWidth = GLOBAL::GetWindowsWidth() / 2;
	float halfHeight = GLOBAL::GetWindowsHeight() / 2;

	D3DXVECTOR3 cameraPosition = ViewPort::GetInstance()->getViewPortPosition(this->mPosition);

	float cameraX = mPosition.x + halfWidth;
	float cameraY = mPosition.y - halfHeight;

	this->mVelocity.x = this->mVelocity.y = 0;

	//Left
	if (aladdinX < cameraX - DELTA_CAMERA)
	{
		this->mVelocity.x = aladdinX - cameraX + DELTA_CAMERA;
	}
	//Right
	if (aladdinX > cameraX + DELTA_CAMERA)
	{
		this->mVelocity.x = aladdinX - cameraX - DELTA_CAMERA;
	}
	//Top
	if (aladdinY < cameraY - DELTA_CAMERA)
	{
		this->mVelocity.y = aladdinY - (cameraY - DELTA_CAMERA);
	}
	//Bottom
	if (aladdinY > cameraY + DELTA_CAMERA)
	{
		this->mVelocity.y = aladdinY - (cameraY + DELTA_CAMERA);
	}
	this->mPosition.x += mVelocity.x;
	this->mPosition.y += mVelocity.y;

	NomalizeCamera();

	/*this->_position.x = aladdinX - halfWidth;
	this->_position.y = aladdinY + halfHeight;*/

	//_rectBound.top = _position.y - _height;
	//_rectBound.left = _position.x - _width;
	//_rectBound.right = _position.x + _width;
	//_rectBound.bottom = _position.y + _height;

	//GraphicsHelper::GetInstance()->DrawSurface(NULL, new Rect(_position.y, _position.x, _position.x + 50, _position.y + 50, D3DXVECTOR3(0, 0, 0)));
}

D3DXVECTOR3 Camera::GetPosition()
{
	return this->mPosition;
}

void Camera::SetPosition(D3DXVECTOR3 Position)
{
	this->mPosition = Position;
}

void Camera::SetPosition(int X, int Y)
{
	this->mPosition.x = X;
	this->mPosition.y = Y;
}

void Camera::NomalizeCamera()
{
	D3DXVECTOR3 lt_position = this->mPosition;
	D3DXVECTOR3 lb_position = D3DXVECTOR3(this->mPosition.x, this->mPosition.y - GLOBAL::GetWindowsHeight(), 0);
	D3DXVECTOR3 rt_position = D3DXVECTOR3(this->mPosition.x + GLOBAL::GetWindowsWidth(), this->mPosition.y, 0);
	D3DXVECTOR3 rb_position = D3DXVECTOR3(this->mPosition.x + GLOBAL::GetWindowsWidth(), this->mPosition.y - GLOBAL::GetWindowsHeight(), 0);

	//Left top
	if (lt_position.x < 0)
		this->mPosition.x = 0;
	if (lt_position.y > WORLD_Y)
		this->mPosition.y = WORLD_Y;

	//Left bottom
	if (lb_position.x < 0)
		this->mPosition.x = 0;
	if (lb_position.y < WORLD_Y - MAP_HEIGHT)
		this->mPosition.y = WORLD_Y - MAP_HEIGHT + GLOBAL::GetWindowsHeight();

	//Right top
	if (rt_position.x > WORLD_X)
		this->mPosition.x = WORLD_X - GLOBAL::GetWindowsWidth();
	if (rt_position.y > WORLD_Y)
		this->mPosition.y = WORLD_Y;

	//Right bottom
	if (rb_position.x > WORLD_X)
		this->mPosition.x = WORLD_X - GLOBAL::GetWindowsWidth();
	if (rb_position.y < WORLD_Y - MAP_HEIGHT)
		this->mPosition.y = WORLD_Y - MAP_HEIGHT + GLOBAL::GetWindowsHeight();
}
