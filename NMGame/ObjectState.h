#pragma once

#include "Global.h"
#include "Sprite.h"
#include "MyRECT.h"

class ObjectState
{
public:
	ObjectState(std::vector<MyRECT> rect, int Animate_rate, LPWSTR filePath, D3DXVECTOR2 velocity);
	/*ObjectState(D3DXVECTOR3 Position);
	ObjectState(int X, int Y);*/
	~ObjectState();

	virtual void	Render();
	virtual void	Update(float DeltaTime);
	virtual void	Animate(float DeltaTime);
	void			Move(float delta_time);
	virtual void	nextFrame();	
	virtual bool	isDone();

	//void			nextFrameWithoutLoop();
	void			resetFrame();
	void			GoToLastFrameIdx();

	D3DXVECTOR3			GetPosition() { return this->mPosition; };
	void				SetPosition(D3DXVECTOR3 Position) { this->mPosition = Position; this->mSprite->SetPosition(this->mPosition);};
	void				SetPosition(int X, int Y) { this->mPosition.x = X; this->mPosition.y = Y; this->mSprite->SetPosition(this->mPosition);	};

	D3DXVECTOR2			GetVelocity() { return this->mVelocity; };
	void				SetVelocity(D3DXVECTOR2 Velocity) {	this->mVelocity = Velocity;	};
	void				SetVelocity(float X, float Y) { this->mVelocity.x = X; this->mVelocity.y = Y;};

	bool				GetFlipVertical() { return this->mIsFlipVertical; };
	void				SetFlipVertical(bool flipV) {this->mIsFlipVertical = flipV; if (this->mIsFlipVertical != this->mSprite->IsFlipVertical()) this->mSprite->FlipVertical(this->mIsFlipVertical);
	};

	int					GetCurrentIdx() { return this->mCurrentIdx; };
	int					GetEndIdx() { return this->mEndIdx; };
	

	Sprite*				mSprite;
	LPD3DXSPRITE		mSpriteHandle;
	int					mEndIdx;		//
	int					mCurrentIdx;	//Index hiện tại
	D3DXVECTOR3			mPosition;		//Vị trí của Aladdin
	D3DXVECTOR2			mVelocity;		//Vận tốc hiện tại của Aladdin
	//D3DXVECTOR2			mDefaultSpeed;	//Vận tốc mặc định khi di chuyển
	bool				mIsFlipVertical; //Lat hinh doc
	DWORD				last_time;	 // this is to control the animate rate of kitty
	int					ANIMATE_RATE;

	bool				ResetFlag;
};