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

	this->mWidth = GLOBAL::GetWindowsWidth();
	this->mHeight = GLOBAL::GetWindowsHeight();
	preDir = Direction::Right;
	mCameraChangeDir = false;
	/*this->mWidth = 1000;
	this->mHeight = 1000;*/
}

Camera::~Camera()
{
}

void Camera::Update(AladdinCharacter* object)
{
	float aladdinX = object->GetPosition().x;
	float aladdinY = object->GetPosition().y;

	halfWidth = this->mWidth / 2;
	halfHeight = this->mHeight / 2;

	cameraX = mPosition.x + halfWidth;
	cameraY = mPosition.y - halfHeight;

	this->mVelocity.x = this->mVelocity.y = 0;

	Direction AladdinDir = object->getDirection();

	switch (AladdinDir)
	{
	case Direction::Right:
		if (AladdinDir != preDir)
		{
			preDir = AladdinDir;
			//this->mVelocity.x = 60;
			//if(object->getCurrentState()!= AState::RopeClimb)
				mCameraChangeDir = true;
		}
		else if (!mCameraChangeDir)
		{
			halfWidth = GLOBAL::GetWindowsWidth() * 2 / 5;
			//halfHeight = GLOBAL::GetWindowsHeight() / 2;

			cameraX = mPosition.x + halfWidth;
			//cameraY = mPosition.y - halfHeight;


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



		}
		break;
	case Direction::Left:
		if (AladdinDir != preDir)
		{
			preDir = AladdinDir;
			//if (object->getCurrentState() != AState::RopeClimb)
				mCameraChangeDir = true;
		}
		else if (!mCameraChangeDir)
		{
			halfWidth = GLOBAL::GetWindowsWidth() * 3 / 5;
			

			cameraX = mPosition.x + halfWidth;

			//Left
			if (aladdinX < cameraX - DELTA_CAMERA )
			{
				this->mVelocity.x = aladdinX - cameraX + DELTA_CAMERA;
			}

			//Right
			if (aladdinX > cameraX + DELTA_CAMERA)

			{
				this->mVelocity.x = aladdinX - cameraX - DELTA_CAMERA;
			}
			
		}
		break;
	}
	

	if (mCameraChangeDir)
	{
		/*if (aladdinX >= cameraX - DELTA_CAMERA &&aladdinX <= cameraX + DELTA_CAMERA)
		{
			mCameraChangeDir = false;
		}
		else*/
		{
			if (object->getDirection() == Direction::Right)
			{
				//aladdinX > cameraX + DELTA_CAMERA
				//if (mPosition.x + GLOBAL::GetWindowsWidth() >= aladdinX + GLOBAL::GetWindowsWidth() * 3 / 5  )
				if(mPosition.x >= aladdinX - GLOBAL::GetWindowsWidth() * 2 /5 - 30)
				{
					mCameraChangeDir = false;
				}
				else
					this->mVelocity.x = 20;
			}
			else
			{
				//aladdinX < cameraX - DELTA_CAMERA
				if (mPosition.x <= aladdinX - GLOBAL::GetWindowsWidth() * 3 / 5 + 30)
				{
					mCameraChangeDir = false;
				}
				else
					this->mVelocity.x = -20;
			}

		}		
	}

	halfHeight = GLOBAL::GetWindowsHeight() / 2;
	cameraY = mPosition.y - halfHeight;

	//Top
	if (aladdinY > cameraY + DELTA_CAMERA)
	{
		this->mVelocity.y = aladdinY - (cameraY + DELTA_CAMERA);
	}
	//Bottom
	if (aladdinY < cameraY - DELTA_CAMERA)
	{
		this->mVelocity.y = aladdinY - (cameraY - DELTA_CAMERA);
	}

	
	this->mPosition.x += mVelocity.x;
	this->mPosition.y += mVelocity.y;

	NomalizeCamera();


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

MyRECT Camera::GetBoundingBoxInWorldAxis()
{
	return MyRECT(mPosition.y,mPosition.x, mPosition.x + mWidth, mPosition.y - mHeight);
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
