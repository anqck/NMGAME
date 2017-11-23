#pragma once

#include "Global.h"
#include "Sprite.h"
#include "MyRECT.h"

class ObjectState
{
public:
	ObjectState(std::vector<MyRECT> rect, int Animate_rate, LPWSTR filePath, D3DXVECTOR2 velocity, CenterArchor center = CenterArchor::Center);
	ObjectState(std::vector<MyRECT> rect, int Animate_rate, LPWSTR filePath, D3DXVECTOR2 velocity, D3DXVECTOR2 acceleration, CenterArchor center = CenterArchor::Center);
	/*ObjectState(D3DXVECTOR3 Position);
	ObjectState(int X, int Y);*/
	~ObjectState();

	virtual void		Render();
	virtual void		Update(float DeltaTime);
	virtual void		Animate(float DeltaTime);

	void				Move(float delta_time);
	void				MoveVertical(float delta_time, Direction dirVer);

	virtual void		nextFrame();	
	virtual bool		isDone();

	void				resetFrame();
	void				GoToFrame(int idx);
	void				GoToLastFrameIdx();

	D3DXVECTOR3			GetPosition() { return this->mPosition; };
	void				SetPosition(D3DXVECTOR3 Position) { this->mPosition = Position; this->mSprite->SetPosition(Position);};
	void				SetPosition(int X, int Y) { this->mPosition.x = X; this->mPosition.y = Y; 	};

	D3DXVECTOR2			GetVelocity();
	void				SetVelocity(D3DXVECTOR2 Velocity) {	this->mVelocity = Velocity;	};
	void				SetVelocity(float X, float Y) ;

	void				ResetDefaultVelocity();

	D3DXVECTOR2			GetAcceleration() { return this->mAcceleration; };
	void				SetAcceleration(D3DXVECTOR2 Acceleration) { this->mVelocity = Acceleration; };
	void				SetAcceleration(float X, float Y) { this->mAcceleration.x = X; this->mAcceleration.y = Y; };

	bool				GetFlipVertical() { return this->mIsFlipVertical; };
	void				SetFlipVertical(bool flipV);


	int					GetCurrentIdx() { return this->mCurrentIdx; };
	int					GetEndIdx() { return this->mEndIdx; };

	bool				GetIsNextFrame(); //Kiểm tra xem có cấp nhật frame idx tiếp theo trong lệnh Animate hay không

	MyRECT				GetCurrentFrameBoundingBox();
	

	Sprite*				mSprite;
	LPD3DXSPRITE		mSpriteHandle;
	int					mEndIdx;		//
	int					mCurrentIdx;	//Index hiện tại
	D3DXVECTOR3			mPosition;		//Vị trí của 
	D3DXVECTOR2			mVelocity;		//Vận tốc hiện tại của 
	D3DXVECTOR2			mAcceleration;		//Gia tốc hiện tại của
	D3DXVECTOR2			mDefaultVelocity;

	

	bool				mIsFlipVertical; //Lat hinh doc
	DWORD				last_time;	 // this is to control the animate rate of kitty

	int					ANIMATE_RATE;
	bool				isNextFrame;

	


	bool				ResetFlag;
};