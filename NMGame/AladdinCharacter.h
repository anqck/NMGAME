#pragma once
#include "Global.h"
#include "Sprite.h"
#include "MyRECT.h"

class AladdinCharacter
{
public:
	AladdinCharacter();
	AladdinCharacter(LPD3DXSPRITE SpriteHandle);
	AladdinCharacter(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position);
	AladdinCharacter(LPD3DXSPRITE SpriteHandle, int X, int Y);
	~AladdinCharacter();

	void			Draw();			//
	virtual void	Animate(float DeltaTime);
	void			Move(int delta_time);
	void			nextFrame();
	void			nextFrameWithoutLoop();
	void			resetFrame();

	D3DXVECTOR3			GetPosition();
	void				SetPosition(D3DXVECTOR3 Position);
	void				SetPosition(int X, int Y);

	D3DXVECTOR2			GetVelocity();
	void				SetVelocity(D3DXVECTOR2 Velocity);
	void				SetVelocity(float X, float Y);

	bool				GetFlipVertical();
	void				SetFlipVertical(bool flipV);

	int					GetCurrentIdx();
	int					GetEndIdx();

	void				GoToLastFrameIdx();

protected:
	Sprite*				mSprite;
	LPD3DXSPRITE		mSpriteHandle;
	int					mStartIdx;		//Index bắt đầu của các Rect chứa các Sprite
	int					mEndIdx;		//
	int					mCurrentIdx;	//Index hiện tại
	D3DXVECTOR3			mPosition;		//Vị trí của Aladdin
	D3DXVECTOR2			mVelocity;		//Vận tốc hiện tại của Aladdin
	D3DXVECTOR2			mDefaultSpeed;	//Vận tốc mặc định khi di chuyển
	bool				mIsFlipVertical; //Lat hinh doc
	DWORD last_time;	 // this is to control the animate rate of kitty

	//float       mTimePerFrame, //thoi gian luan chuyen 1 frame
	//			mCurrentTotalTime;
	int ANIMATE_RATE;
	




};